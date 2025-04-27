warning: Currently logging to gdb.c.  Turn the logging off and on to make the new setting effective.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[Inferior 1 (process 6803) exited normally]
Undefined command: "exitg".  Try "help".
warning: Currently logging to gdb.c.  Turn the logging off and on to make the new setting effective.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[Inferior 1 (process 6934) exited normally]
Quit
warning: Currently logging to gdb.c.  Turn the logging off and on to make the new setting effective.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[New Thread 0x7ffff7ba36c0 (LWP 6979)]
[New Thread 0x7ffff738f6c0 (LWP 6980)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff7ba36c0 (LWP 6979)]
0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
warning: Source file is more recent than executable.
75	        var index = thread_index;
#0  0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
#1  0x00007ffff7f89ce3 in heap.SmpAllocator.alloc (context=0x0, len=14, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:131
#2  0x00007ffff7f346ba in mem.Allocator.rawAlloc () at /usr/lib/zig/std/mem/Allocator.zig:129
#3  mem.Allocator.allocBytesWithAlignment__anon_14706 (self=..., byte_count=14, return_address=140737353643937) at /usr/lib/zig/std/mem/Allocator.zig:269
#4  0x00007ffff7f26313 in mem.Allocator.allocWithSizeAndAlignment__anon_11852 (self=..., n=14, return_address=140737353643937) at /usr/lib/zig/std/mem/Allocator.zig:260
#5  0x00007ffff7f0ec22 in mem.Allocator.allocAdvancedWithRetAddr () at /usr/lib/zig/std/mem/Allocator.zig:254
#6  mem.Allocator.alloc__anon_8671 (self=..., n=14) at /usr/lib/zig/std/mem/Allocator.zig:178
#7  0x00007ffff7f877a1 in root.internal_malloc (len=6, zeroed=false) at root.zig:12
#8  0x00007ffff7f876fb in root.malloc (len=6) at root.zig:28
#9  0x00005555555554e3 in malloc_benchmark_loop (ptr_arr=0x7ffffffe33f0) at bench-malloc-thread.c:147
#10 0x0000555555555575 in benchmark_thread (arg=0x7fffffffb3f0) at bench-malloc-thread.c:175
#11 0x00007ffff7c3c708 in start_thread (arg=<optimized out>) at pthread_create.c:448
#12 0x00007ffff7cc0aac in __GI___clone3 () at ../sysdeps/unix/sysv/linux/x86_64/clone3.S:78
warning: Currently logging to gdb.c.  Turn the logging off and on to make the new setting effective.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[New Thread 0x7ffff7ba36c0 (LWP 7888)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff7ba36c0 (LWP 7888)]
0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
warning: Source file is more recent than executable.
75	        var index = thread_index;
