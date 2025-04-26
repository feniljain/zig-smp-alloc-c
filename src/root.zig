const std = @import("std");
const mem = std.mem;
const testing = std.testing;

test "test_alloc" {
    const ptr = malloc(1).?;
    // std.debug.print("test_alloc::ptr: {*}\n", .{ptr});
    free(ptr);
}

pub fn internal_malloc(len: usize, zeroed: bool) ?*u8 {
    const slice = std.heap.smp_allocator.alloc(u8, len + @sizeOf(usize)) catch return null;

    // not checking for null here, as we return immediately above if `alloc` returns null
    if (zeroed) {
        // std.debug.print("slice length: {} - zeoring: {}\n", .{slice.len, @sizeOf(usize)});
        @memset(mem.sliceAsBytes(slice), 0);
        // std.debug.print("zeroed\n", .{});
    }

    mem.writeInt(usize, mem.sliceAsBytes(slice)[0..@sizeOf(usize)], slice.len, .little);

    return @ptrCast(@as(*u8, @ptrFromInt(@intFromPtr(slice.ptr) + @sizeOf(usize))));
}

pub export fn malloc(len: usize) callconv(.C) ?*u8 {
    // std.debug.print("malloc called, len: {}\n", .{len});
    return internal_malloc(len, false);
}

pub export fn free(ptr: ?*anyopaque) callconv(.C) void {
    // std.debug.print("free called, ptr: {*}\n", .{ptr});
    if (ptr == null) {
        return;
    }

    const slice_addr: *usize = @ptrFromInt(@intFromPtr(ptr) - @sizeOf(usize));

    const data: *[]u8 = @constCast(@ptrCast(&.{ .ptr = @as(*u8, @ptrCast(slice_addr)), .len = slice_addr.* }));

    std.heap.smp_allocator.free(data.*);
}

pub export fn realloc(ptr: ?*anyopaque, len: usize) callconv(.C) ?*u8 {
    // std.debug.print("realloc called, ptr: {*}, len: {}\n", .{ ptr, len });
    // realloc with null ptr, acts as malloc
    if (ptr == null) {
        return malloc(len);
    }

    const slice_addr: *usize = @ptrFromInt(@intFromPtr(ptr) - @sizeOf(usize));
    const data: *[]u8 = @constCast(@ptrCast(&.{ .ptr = @as(*u8, @ptrCast(slice_addr)), .len = slice_addr.* }));

    // In SMP allocator's case, it does not resize for length which reduces it's class, so it returns
    // the same addr, where caller can just assume, len has been changed.
    // And in case where resize requests for larger length, it does allocate new memory region.
    const new_slice = std.heap.smp_allocator.realloc(data.*, len + @sizeOf(usize)) catch return null;

    mem.writeInt(usize, mem.sliceAsBytes(new_slice)[0..@sizeOf(usize)], new_slice.len, .little);

    return @ptrCast(@as(*u8, @ptrFromInt(@intFromPtr(new_slice.ptr) + @sizeOf(usize))));
}

pub export fn calloc(len: usize) callconv(.C) ?*u8 {
    // std.debug.print("calloc called, len: {}\n", .{len});
    return internal_malloc(len, true);
}

// LD_PRELOAD=/home/feniljain/Projects/zig-projects/smp-alloc/zig-out/lib/libsmp_alloc.so ./alloc-test 1
