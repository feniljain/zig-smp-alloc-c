const std = @import("std");
const mem = std.mem;
const testing = std.testing;

test "test_alloc" {
    const ptr = malloc(1).?;
    std.debug.print("test_alloc::ptr: {*}\n", .{ptr});
    free(ptr);
}

pub export fn malloc(len: usize) callconv(.C) ?*u8 {
    const slice = std.heap.smp_allocator.alloc(u8, len + @sizeOf(usize)) catch return null;
    mem.writeInt(usize, mem.sliceAsBytes(slice)[0..@sizeOf(usize)], slice.len, .little);

    return @ptrCast(@as(*u8, @ptrFromInt(@intFromPtr(slice.ptr) + @sizeOf(usize))));
}

pub export fn free(ptr: *anyopaque) callconv(.C) void {
    const slice_addr: *usize = @ptrFromInt(@intFromPtr(ptr) - @sizeOf(usize));

    const data: *[]u8 = @constCast(@ptrCast(&.{ .ptr = @as(*u8, @ptrCast(slice_addr)), .len = slice_addr.* }));

    std.heap.smp_allocator.free(data.*);
}
