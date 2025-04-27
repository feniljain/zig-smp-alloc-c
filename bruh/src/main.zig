//! By convention, main.zig is where your main function lives in the case that
//! you are building an executable. If you are making a library, the convention
//! is to delete this file and start with root.zig instead.

const std = @import("std");
const zThread = @cImport({
    @cInclude("pthread.h");
});

pub fn work(x: ?*anyopaque) callconv(.C) ?*anyopaque {
    while (true) {
        const slice = std.heap.smp_allocator.alloc(u8, 6) catch unreachable;
        @memset(std.mem.sliceAsBytes(slice), 0);
        std.debug.print("allocated ptr {*} ({*})\n", .{ slice, x });
    }
    return zThread.NULL;
}

//pub fn work() void {
//    csmp();
//}

pub fn main() !void {
    const slice = std.heap.smp_allocator.alloc(u8, 6) catch unreachable;
    @memset(std.mem.sliceAsBytes(slice), 0);
    var tid: zThread.pthread_t = 0;
    _ = zThread.pthread_create(&tid, 0, work, zThread.NULL);
    var tid_too: zThread.pthread_t = 0;
    _ = zThread.pthread_create(&tid_too, 0, work, zThread.NULL);
    var x: ?*anyopaque = zThread.NULL;
    _ = zThread.pthread_join(tid, &x);
    _ = zThread.pthread_join(tid_too, &x);
    if (false) {
        const allocator = std.heap.page_allocator;
        const spawnConfig = std.Thread.SpawnConfig{ .allocator = allocator };
        const thread = try std.Thread.spawn(spawnConfig, work, .{});
        const thread_too = try std.Thread.spawn(spawnConfig, work, .{});
        thread.join();
        thread_too.join();
    }
}
