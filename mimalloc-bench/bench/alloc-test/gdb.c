warning: Currently logging to gdb.c.  Turn the logging off and on to make the new setting effective.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[New Thread 0x7ffff78bf6c0 (LWP 12400)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff78bf6c0 (LWP 12400)]
0x00007ffff7ef9868 in Thread.LinuxThreadImpl.getCurrentId () at /usr/lib/zig/std/Thread.zig:1140
1140	        return tls_thread_id orelse {
#0  0x00007ffff7ef9868 in Thread.LinuxThreadImpl.getCurrentId () at /usr/lib/zig/std/Thread.zig:1140
#1  0x00007ffff7ef46d9 in Thread.getCurrentId () at /usr/lib/zig/std/Thread.zig:354
#2  0x00007ffff7f141ed in Thread.Mutex.Recursive.lock (r=0x7ffff7fb34d8 <Progress.stderr_mutex>) at /usr/lib/zig/std/Thread/Mutex/Recursive.zig:50
#3  0x00007ffff7ef980f in Progress.lockStdErr () at /usr/lib/zig/std/Progress.zig:545
#4  0x00007ffff7ef4679 in debug.lockStdErr () at /usr/lib/zig/std/debug.zig:202
#5  0x00007ffff7f8aabf in debug.print__anon_26676 (args=...) at /usr/lib/zig/std/debug.zig:212
#6  0x00007ffff7f8a457 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:74
#7  0x00007ffff7f89ea3 in heap.SmpAllocator.alloc (context=0x0, len=15, alignment=1, ra=140737353644385) at /usr/lib/zig/std/heap/SmpAllocator.zig:131
#8  0x00007ffff7f3487a in mem.Allocator.rawAlloc () at /usr/lib/zig/std/mem/Allocator.zig:129
#9  mem.Allocator.allocBytesWithAlignment__anon_14706 (self=..., byte_count=15, return_address=140737353644385) at /usr/lib/zig/std/mem/Allocator.zig:269
#10 0x00007ffff7f264d3 in mem.Allocator.allocWithSizeAndAlignment__anon_11852 (self=..., n=15, return_address=140737353644385) at /usr/lib/zig/std/mem/Allocator.zig:260
#11 0x00007ffff7f0ede2 in mem.Allocator.allocAdvancedWithRetAddr () at /usr/lib/zig/std/mem/Allocator.zig:254
#12 mem.Allocator.alloc__anon_8671 (self=..., n=15) at /usr/lib/zig/std/mem/Allocator.zig:178
#13 0x00007ffff7f87961 in root.internal_malloc (len=7, zeroed=false) at root.zig:12
#14 0x00007ffff7f878bb in root.malloc (len=7) at root.zig:28
#15 0x00007ffff7caebc5 in operator new (sz=7) at /usr/src/debug/gcc/gcc/libstdc++-v3/libsupc++/new_op.cc:50
#16 0x0000555555556af0 in NewDeleteAllocatorForTest::allocate (this=0x7ffff78bed78, sz=7) at /home/feniljain/Projects/zig-projects/smp-alloc/mimalloc-bench/bench/alloc-test/new_delete_allocator.h:52
#17 0x0000555555558d8c in randomPos_RandomSize<NewDeleteAllocatorForTest, (MEM_ACCESS_TYPE)2> (allocatorUnderTest=..., iterCount=100000000, maxItems=262144, maxItemSizeExp=10, threadID=0, rnd_seed=41) at /home/feniljain/Projects/zig-projects/smp-alloc/mimalloc-bench/bench/alloc-test/allocator_tester.h:305
#18 0x0000555555557419 in runRandomTest<NewDeleteAllocatorForTest> (params=0x7ffffffd81c0) at allocator_tester.cpp:49
#19 0x000055555555c21c in std::__invoke_impl<void*, void* (*)(void*), void*> (__f=@0x7ffff78c0018: 0x5555555572fe <runRandomTest<NewDeleteAllocatorForTest>(void*)>) at /usr/include/c++/14.2.1/bits/invoke.h:61
#20 0x000055555555c1a0 in std::__invoke<void* (*)(void*), void*> (__fn=@0x7ffff78c0018: 0x5555555572fe <runRandomTest<NewDeleteAllocatorForTest>(void*)>) at /usr/include/c++/14.2.1/bits/invoke.h:96
#21 0x000055555555c111 in std::thread::_Invoker<std::tuple<void* (*)(void*), void*> >::_M_invoke<0ul, 1ul> (this=0x7ffff78c0010) at /usr/include/c++/14.2.1/bits/std_thread.h:301
#22 0x000055555555c0cc in std::thread::_Invoker<std::tuple<void* (*)(void*), void*> >::operator() (this=0x7ffff78c0010) at /usr/include/c++/14.2.1/bits/std_thread.h:308
#23 0x000055555555c0b0 in std::thread::_State_impl<std::thread::_Invoker<std::tuple<void* (*)(void*), void*> > >::_M_run (this=0x7ffff78c0008) at /usr/include/c++/14.2.1/bits/std_thread.h:253
#24 0x00007ffff7ce1f74 in std::execute_native_thread_routine (__p=0x7ffff78c0008) at /usr/src/debug/gcc/gcc/libstdc++-v3/src/c++11/thread.cc:104
#25 0x00007ffff797d70a in ?? () from /usr/lib/libc.so.6
#26 0x00007ffff7a01aac in ?? () from /usr/lib/libc.so.6
Dump of assembler code for function Thread.LinuxThreadImpl.getCurrentId:
   0x00007ffff7ef9850 <+0>:	push   rbp
   0x00007ffff7ef9851 <+1>:	mov    rbp,rsp
   0x00007ffff7ef9854 <+4>:	sub    rsp,0x30
   0x00007ffff7ef9858 <+8>:	mov    QWORD PTR [rbp-0x20],rdi
   0x00007ffff7ef985c <+12>:	lea    rdi,[rip+0xb88bd]        # 0x7ffff7fb2120
   0x00007ffff7ef9863 <+19>:	call   0x7ffff7faebd0 <__tls_get_addr@plt>
=> 0x00007ffff7ef9868 <+24>:	mov    rax,QWORD PTR [rax+0x8]
   0x00007ffff7ef986f <+31>:	mov    QWORD PTR [rbp-0x18],rax
   0x00007ffff7ef9873 <+35>:	cmp    BYTE PTR [rbp-0x14],0x0
   0x00007ffff7ef9877 <+39>:	jne    0x7ffff7ef9884 <Thread.LinuxThreadImpl.getCurrentId+52>
   0x00007ffff7ef9879 <+41>:	jmp    0x7ffff7ef988c <Thread.LinuxThreadImpl.getCurrentId+60>
   0x00007ffff7ef987b <+43>:	mov    eax,DWORD PTR [rbp-0x24]
   0x00007ffff7ef987e <+46>:	add    rsp,0x30
   0x00007ffff7ef9882 <+50>:	pop    rbp
   0x00007ffff7ef9883 <+51>:	ret
   0x00007ffff7ef9884 <+52>:	mov    eax,DWORD PTR [rbp-0x18]
   0x00007ffff7ef9887 <+55>:	mov    DWORD PTR [rbp-0x24],eax
   0x00007ffff7ef988a <+58>:	jmp    0x7ffff7ef987b <Thread.LinuxThreadImpl.getCurrentId+43>
   0x00007ffff7ef988c <+60>:	mov    rdi,QWORD PTR [rbp-0x20]
   0x00007ffff7ef9890 <+64>:	call   0x7ffff7ef9c90 <os.linux.gettid>
   0x00007ffff7ef9895 <+69>:	mov    DWORD PTR [rbp-0x28],eax
   0x00007ffff7ef9898 <+72>:	mov    DWORD PTR [rbp-0xc],eax
   0x00007ffff7ef989b <+75>:	mov    DWORD PTR [rbp-0x8],eax
   0x00007ffff7ef989e <+78>:	mov    BYTE PTR [rbp-0x4],0x1
   0x00007ffff7ef98a2 <+82>:	mov    rax,QWORD PTR [rbp-0x8]
   0x00007ffff7ef98a6 <+86>:	mov    QWORD PTR [rbp-0x30],rax
   0x00007ffff7ef98aa <+90>:	lea    rdi,[rip+0xb886f]        # 0x7ffff7fb2120
   0x00007ffff7ef98b1 <+97>:	call   0x7ffff7faebd0 <__tls_get_addr@plt>
   0x00007ffff7ef98b6 <+102>:	mov    rdx,QWORD PTR [rbp-0x30]
   0x00007ffff7ef98ba <+106>:	mov    rcx,rax
   0x00007ffff7ef98bd <+109>:	mov    eax,DWORD PTR [rbp-0x28]
   0x00007ffff7ef98c0 <+112>:	mov    QWORD PTR [rcx+0x8],rdx
   0x00007ffff7ef98c7 <+119>:	add    rsp,0x30
   0x00007ffff7ef98cb <+123>:	pop    rbp
   0x00007ffff7ef98cc <+124>:	ret
End of assembler dump.
warning: Currently logging to gdb.c.  Turn the logging off and on to make the new setting effective.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[New Thread 0x7ffff78bf6c0 (LWP 12688)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff78bf6c0 (LWP 12688)]
0x00007ffff7ef9868 in Thread.LinuxThreadImpl.getCurrentId () at /usr/lib/zig/std/Thread.zig:1140
1140	        return tls_thread_id orelse {
Dump of assembler code for function Thread.LinuxThreadImpl.getCurrentId:
   0x00007ffff7ef9850 <+0>:	push   rbp
   0x00007ffff7ef9851 <+1>:	mov    rbp,rsp
   0x00007ffff7ef9854 <+4>:	sub    rsp,0x30
   0x00007ffff7ef9858 <+8>:	mov    QWORD PTR [rbp-0x20],rdi
   0x00007ffff7ef985c <+12>:	lea    rdi,[rip+0xb88bd]        # 0x7ffff7fb2120
   0x00007ffff7ef9863 <+19>:	call   0x7ffff7faebd0 <__tls_get_addr@plt>
=> 0x00007ffff7ef9868 <+24>:	mov    rax,QWORD PTR [rax+0x8]
   0x00007ffff7ef986f <+31>:	mov    QWORD PTR [rbp-0x18],rax
   0x00007ffff7ef9873 <+35>:	cmp    BYTE PTR [rbp-0x14],0x0
   0x00007ffff7ef9877 <+39>:	jne    0x7ffff7ef9884 <Thread.LinuxThreadImpl.getCurrentId+52>
   0x00007ffff7ef9879 <+41>:	jmp    0x7ffff7ef988c <Thread.LinuxThreadImpl.getCurrentId+60>
   0x00007ffff7ef987b <+43>:	mov    eax,DWORD PTR [rbp-0x24]
   0x00007ffff7ef987e <+46>:	add    rsp,0x30
   0x00007ffff7ef9882 <+50>:	pop    rbp
   0x00007ffff7ef9883 <+51>:	ret
   0x00007ffff7ef9884 <+52>:	mov    eax,DWORD PTR [rbp-0x18]
   0x00007ffff7ef9887 <+55>:	mov    DWORD PTR [rbp-0x24],eax
   0x00007ffff7ef988a <+58>:	jmp    0x7ffff7ef987b <Thread.LinuxThreadImpl.getCurrentId+43>
   0x00007ffff7ef988c <+60>:	mov    rdi,QWORD PTR [rbp-0x20]
   0x00007ffff7ef9890 <+64>:	call   0x7ffff7ef9c90 <os.linux.gettid>
   0x00007ffff7ef9895 <+69>:	mov    DWORD PTR [rbp-0x28],eax
   0x00007ffff7ef9898 <+72>:	mov    DWORD PTR [rbp-0xc],eax
   0x00007ffff7ef989b <+75>:	mov    DWORD PTR [rbp-0x8],eax
   0x00007ffff7ef989e <+78>:	mov    BYTE PTR [rbp-0x4],0x1
   0x00007ffff7ef98a2 <+82>:	mov    rax,QWORD PTR [rbp-0x8]
   0x00007ffff7ef98a6 <+86>:	mov    QWORD PTR [rbp-0x30],rax
   0x00007ffff7ef98aa <+90>:	lea    rdi,[rip+0xb886f]        # 0x7ffff7fb2120
   0x00007ffff7ef98b1 <+97>:	call   0x7ffff7faebd0 <__tls_get_addr@plt>
   0x00007ffff7ef98b6 <+102>:	mov    rdx,QWORD PTR [rbp-0x30]
   0x00007ffff7ef98ba <+106>:	mov    rcx,rax
   0x00007ffff7ef98bd <+109>:	mov    eax,DWORD PTR [rbp-0x28]
   0x00007ffff7ef98c0 <+112>:	mov    QWORD PTR [rcx+0x8],rdx
   0x00007ffff7ef98c7 <+119>:	add    rsp,0x30
   0x00007ffff7ef98cb <+123>:	pop    rbp
   0x00007ffff7ef98cc <+124>:	ret
End of assembler dump.
warning: Currently logging to gdb.c.  Turn the logging off and on to make the new setting effective.
Function "0x7ffff7faebd0" not defined.
Make breakpoint pending on future shared library load? (y or [n]) [answered N; input not from terminal]
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[New Thread 0x7ffff78bf6c0 (LWP 12755)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff78bf6c0 (LWP 12755)]
0x00007ffff7ef9868 in Thread.LinuxThreadImpl.getCurrentId () at /usr/lib/zig/std/Thread.zig:1140
1140	        return tls_thread_id orelse {
warning: Currently logging to gdb.c.  Turn the logging off and on to make the new setting effective.
Breakpoint 1 at 0x7ffff7faebd0
Warning:
Cannot insert breakpoint 1.
Cannot access memory at address 0x7ffff7faebd0

/home/feniljain/test.gdb:15: Error in sourced command file:
Command aborted.
warning: Currently logging to gdb.c.  Turn the logging off and on to make the new setting effective.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[New Thread 0x7ffff78bf6c0 (LWP 12884)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff78bf6c0 (LWP 12884)]
0x00007ffff7ef9868 in Thread.LinuxThreadImpl.getCurrentId () at /usr/lib/zig/std/Thread.zig:1140
1140	        return tls_thread_id orelse {
Breakpoint 1 at 0x7ffff7faebd0
Warning:
Cannot insert breakpoint 1.
Cannot access memory at address 0x7ffff7faebd0

/home/feniljain/test.gdb:17: Error in sourced command file:
Command aborted.
No function contains program counter for selected frame.
warning: Currently logging to gdb.c.  Turn the logging off and on to make the new setting effective.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[New Thread 0x7ffff78bf6c0 (LWP 12934)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff78bf6c0 (LWP 12934)]
0x00007ffff7ef9868 in Thread.LinuxThreadImpl.getCurrentId () at /usr/lib/zig/std/Thread.zig:1140
1140	        return tls_thread_id orelse {
Dump of assembler code for function Thread.LinuxThreadImpl.getCurrentId:
   0x00007ffff7ef9850 <+0>:	push   rbp
   0x00007ffff7ef9851 <+1>:	mov    rbp,rsp
   0x00007ffff7ef9854 <+4>:	sub    rsp,0x30
   0x00007ffff7ef9858 <+8>:	mov    QWORD PTR [rbp-0x20],rdi
   0x00007ffff7ef985c <+12>:	lea    rdi,[rip+0xb88bd]        # 0x7ffff7fb2120
   0x00007ffff7ef9863 <+19>:	call   0x7ffff7faebd0 <__tls_get_addr@plt>
=> 0x00007ffff7ef9868 <+24>:	mov    rax,QWORD PTR [rax+0x8]
   0x00007ffff7ef986f <+31>:	mov    QWORD PTR [rbp-0x18],rax
   0x00007ffff7ef9873 <+35>:	cmp    BYTE PTR [rbp-0x14],0x0
   0x00007ffff7ef9877 <+39>:	jne    0x7ffff7ef9884 <Thread.LinuxThreadImpl.getCurrentId+52>
   0x00007ffff7ef9879 <+41>:	jmp    0x7ffff7ef988c <Thread.LinuxThreadImpl.getCurrentId+60>
   0x00007ffff7ef987b <+43>:	mov    eax,DWORD PTR [rbp-0x24]
   0x00007ffff7ef987e <+46>:	add    rsp,0x30
   0x00007ffff7ef9882 <+50>:	pop    rbp
   0x00007ffff7ef9883 <+51>:	ret
   0x00007ffff7ef9884 <+52>:	mov    eax,DWORD PTR [rbp-0x18]
   0x00007ffff7ef9887 <+55>:	mov    DWORD PTR [rbp-0x24],eax
   0x00007ffff7ef988a <+58>:	jmp    0x7ffff7ef987b <Thread.LinuxThreadImpl.getCurrentId+43>
   0x00007ffff7ef988c <+60>:	mov    rdi,QWORD PTR [rbp-0x20]
   0x00007ffff7ef9890 <+64>:	call   0x7ffff7ef9c90 <os.linux.gettid>
   0x00007ffff7ef9895 <+69>:	mov    DWORD PTR [rbp-0x28],eax
   0x00007ffff7ef9898 <+72>:	mov    DWORD PTR [rbp-0xc],eax
   0x00007ffff7ef989b <+75>:	mov    DWORD PTR [rbp-0x8],eax
   0x00007ffff7ef989e <+78>:	mov    BYTE PTR [rbp-0x4],0x1
   0x00007ffff7ef98a2 <+82>:	mov    rax,QWORD PTR [rbp-0x8]
   0x00007ffff7ef98a6 <+86>:	mov    QWORD PTR [rbp-0x30],rax
   0x00007ffff7ef98aa <+90>:	lea    rdi,[rip+0xb886f]        # 0x7ffff7fb2120
   0x00007ffff7ef98b1 <+97>:	call   0x7ffff7faebd0 <__tls_get_addr@plt>
   0x00007ffff7ef98b6 <+102>:	mov    rdx,QWORD PTR [rbp-0x30]
   0x00007ffff7ef98ba <+106>:	mov    rcx,rax
   0x00007ffff7ef98bd <+109>:	mov    eax,DWORD PTR [rbp-0x28]
   0x00007ffff7ef98c0 <+112>:	mov    QWORD PTR [rcx+0x8],rdx
   0x00007ffff7ef98c7 <+119>:	add    rsp,0x30
   0x00007ffff7ef98cb <+123>:	pop    rbp
   0x00007ffff7ef98cc <+124>:	ret
End of assembler dump.
$1 = 140737353804752
Quit
$2 = -1 '\377'
Argument required (address).
__tls_get_addr@plt in section .plt of /home/feniljain/Projects/zig-projects/smp-alloc/zig-out/lib/libsmp_alloc.so
Dump of assembler code for function __tls_get_addr@plt:
   0x00007ffff7faebd0 <+0>:	jmp    QWORD PTR [rip+0x3602]        # 0x7ffff7fb21d8 <__tls_get_addr@got.plt>
   0x00007ffff7faebd6 <+6>:	push   0x12
   0x00007ffff7faebdb <+11>:	jmp    0x7ffff7faeaa0
End of assembler dump.
No function contains specified address.
Breakpoint 1 at 0x7ffff7faeaa0
Starting program: /home/feniljain/Projects/zig-projects/smp-alloc/mimalloc-bench/bench/alloc-test/a.out 1
Warning:
Cannot insert breakpoint 1.
Cannot access memory at address 0x7ffff7faeaa0

Command aborted.
Function "pthread_create" not defined.
Breakpoint 2 (pthread_create) pending.
Starting program: /home/feniljain/Projects/zig-projects/smp-alloc/mimalloc-bench/bench/alloc-test/a.out 1
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".

Breakpoint 2, 0x00007ffff797d928 in pthread_create () from /usr/lib/libc.so.6
Function "0x7ffff7faeaa0" not defined.
Quit
Quit
Quit
Breakpoint 3 at 0x7ffff7faeaa0
Breakpoint 4 at 0x7ffff7faeaa0
Continuing.
[New Thread 0x7ffff78bf6c0 (LWP 13143)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff78bf6c0 (LWP 13143)]
0x00007ffff7ef9868 in Thread.LinuxThreadImpl.getCurrentId () at /usr/lib/zig/std/Thread.zig:1140
1140	        return tls_thread_id orelse {
warning: Currently logging to gdb.c.  Turn the logging off and on to make the new setting effective.
µ‡£©`
Make breakpoint pending on future shared library load? (y or [n]) [answered N; input not from terminal]
E×©”Íp
Make breakpoint pending on future shared library load? (y or [n]) [answered N; input not from terminal]
Downloading 1.10 M separate debug info for /lib64/ld-linux-x86-64.so.2
[##                                                                                                            ]   3% (1.10 M)[######                                                                                                        ]   6% (1.10 M)[#######                                                                                                       ]   6% (1.10 M)[#######                                                                                                       ]   6% (1.10 M)[#######                                                                                                       ]   6% (1.10 M)[##########                                                                                                    ]   9% (1.10 M)[###########                                                                                                   ]  11% (1.10 M)[##############                                                                                                ]  13% (1.10 M)[##############                                                                                                ]  13% (1.10 M)[################                                                                                              ]  15% (1.10 M)[################                                                                                              ]  15% (1.10 M)[###################                                                                                           ]  18% (1.10 M)[######################                                                                                        ]  20% (1.10 M)[######################                                                                                        ]  20% (1.10 M)[#########################                                                                                     ]  23% (1.10 M)[#########################                                                                                     ]  23% (1.10 M)[#########################                                                                                     ]  23% (1.10 M)[###########################                                                                                   ]  25% (1.10 M)[##############################                                                                                ]  28% (1.10 M)[#################################                                                                             ]  30% (1.10 M)[#################################                                                                             ]  30% (1.10 M)[###################################                                                                           ]  33% (1.10 M)[###################################                                                                           ]  33% (1.10 M)[######################################                                                                        ]  35% (1.10 M)[######################################                                                                        ]  35% (1.10 M)[#########################################                                                                     ]  38% (1.10 M)[#########################################                                                                     ]  38% (1.10 M)[############################################                                                                  ]  40% (1.10 M)[#################################################                                                             ]  45% (1.10 M)[#################################################                                                             ]  45% (1.10 M)[###################################################                                                           ]  47% (1.10 M)[###################################################                                                           ]  47% (1.10 M)[#####################################################                                                         ]  48% (1.10 M)[#####################################################                                                         ]  48% (1.10 M)[########################################################                                                      ]  51% (1.10 M)[###########################################################                                                   ]  54% (1.10 M)[#############################################################                                                 ]  56% (1.10 M)[#################################################################                                             ]  60% (1.10 M)[#################################################################                                             ]  60% (1.10 M)[#####################################################################                                         ]  63% (1.10 M)[########################################################################                                      ]  66% (1.10 M)[########################################################################                                      ]  66% (1.10 M)[###########################################################################                                   ]  69% (1.10 M)[##############################################################################                                ]  71% (1.10 M)[#################################################################################                             ]  74% (1.10 M)[#################################################################################                             ]  74% (1.10 M)[####################################################################################                          ]  77% (1.10 M)[########################################################################################                      ]  81% (1.10 M)[########################################################################################                      ]  81% (1.10 M)[########################################################################################                      ]  81% (1.10 M)[############################################################################################                  ]  84% (1.10 M)[###############################################################################################               ]  87% (1.10 M)[#####################################################################################################         ]  92% (1.10 M)[########################################################################################################      ]  95% (1.10 M)[###########################################################################################################   ]  98% (1.10 M)[##############################################################################################################] 100% (1.10 M)                                                                                                                                Downloading 3.04 M separate debug info for /usr/lib/libm.so.6
[###############                                                                                               ]  14% (3.04 M)[###############                                                                                               ]  14% (3.04 M)[###############                                                                                               ]  14% (3.04 M)[#################                                                                                             ]  16% (3.04 M)[##################                                                                                            ]  17% (3.04 M)[###################                                                                                           ]  18% (3.04 M)[###################                                                                                           ]  18% (3.04 M)[###################                                                                                           ]  18% (3.04 M)[###################                                                                                           ]  18% (3.04 M)[####################                                                                                          ]  19% (3.04 M)[######################                                                                                        ]  20% (3.04 M)[#######################                                                                                       ]  21% (3.04 M)[########################                                                                                      ]  22% (3.04 M)[##########################                                                                                    ]  24% (3.04 M)[###########################                                                                                   ]  25% (3.04 M)[############################                                                                                  ]  26% (3.04 M)[#############################                                                                                 ]  27% (3.04 M)[##############################                                                                                ]  28% (3.04 M)[###############################                                                                               ]  29% (3.04 M)[##################################                                                                            ]  31% (3.04 M)[##################################                                                                            ]  31% (3.04 M)[###################################                                                                           ]  32% (3.04 M)[###################################                                                                           ]  32% (3.04 M)[#####################################                                                                         ]  34% (3.04 M)[######################################                                                                        ]  35% (3.04 M)[######################################                                                                        ]  35% (3.04 M)[######################################                                                                        ]  35% (3.04 M)[#######################################                                                                       ]  36% (3.04 M)[#######################################                                                                       ]  36% (3.04 M)[#######################################                                                                       ]  36% (3.04 M)[#########################################                                                                     ]  38% (3.04 M)[##########################################                                                                    ]  39% (3.04 M)[##########################################                                                                    ]  39% (3.04 M)[############################################                                                                  ]  40% (3.04 M)[############################################                                                                  ]  40% (3.04 M)[#############################################                                                                 ]  42% (3.04 M)[###############################################                                                               ]  43% (3.04 M)[################################################                                                              ]  44% (3.04 M)[################################################                                                              ]  44% (3.04 M)[################################################                                                              ]  44% (3.04 M)[##################################################                                                            ]  46% (3.04 M)[#####################################################                                                         ]  49% (3.04 M)[#####################################################                                                         ]  49% (3.04 M)[#####################################################                                                         ]  49% (3.04 M)[########################################################                                                      ]  51% (3.04 M)[###########################################################                                                   ]  54% (3.04 M)[############################################################                                                  ]  55% (3.04 M)[##############################################################                                                ]  57% (3.04 M)[##############################################################                                                ]  57% (3.04 M)[###############################################################                                               ]  58% (3.04 M)[################################################################                                              ]  59% (3.04 M)[################################################################                                              ]  59% (3.04 M)[#################################################################                                             ]  60% (3.04 M)[###################################################################                                           ]  61% (3.04 M)[####################################################################                                          ]  62% (3.04 M)[#####################################################################                                         ]  63% (3.04 M)[######################################################################                                        ]  64% (3.04 M)[########################################################################                                      ]  66% (3.04 M)[#########################################################################                                     ]  67% (3.04 M)[#############################################################################                                 ]  71% (3.04 M)[##################################################################################                            ]  75% (3.04 M)[###################################################################################                           ]  76% (3.04 M)[#####################################################################################                         ]  78% (3.04 M)[########################################################################################                      ]  80% (3.04 M)[#########################################################################################                     ]  81% (3.04 M)[#########################################################################################                     ]  81% (3.04 M)[###########################################################################################                   ]  83% (3.04 M)[###########################################################################################                   ]  84% (3.04 M)[###########################################################################################                   ]  84% (3.04 M)[#############################################################################################                 ]  85% (3.04 M)[##############################################################################################                ]  86% (3.04 M)[##############################################################################################                ]  86% (3.04 M)[###############################################################################################               ]  87% (3.04 M)[################################################################################################              ]  88% (3.04 M)[################################################################################################              ]  88% (3.04 M)[##################################################################################################            ]  89% (3.04 M)[###################################################################################################           ]  91% (3.04 M)[#####################################################################################################         ]  92% (3.04 M)[######################################################################################################        ]  93% (3.04 M)[#######################################################################################################       ]  94% (3.04 M)[#######################################################################################################       ]  94% (3.04 M)[########################################################################################################      ]  95% (3.04 M)[#########################################################################################################     ]  96% (3.04 M)[#########################################################################################################     ]  96% (3.04 M)[##########################################################################################################    ]  97% (3.04 M)[###########################################################################################################   ]  98% (3.04 M)[############################################################################################################# ] 100% (3.04 M)[##############################################################################################################] 100% (3.04 M)                                                                                                                                Downloading 9.67 M separate debug info for /usr/lib/libc.so.6
[####                                                                                                          ]   4% (9.67 M)[####                                                                                                          ]   4% (9.67 M)[####                                                                                                          ]   4% (9.67 M)[####                                                                                                          ]   4% (9.67 M)[####                                                                                                          ]   4% (9.67 M)[####                                                                                                          ]   5% (9.67 M)[#####                                                                                                         ]   5% (9.67 M)[#####                                                                                                         ]   5% (9.67 M)[#####                                                                                                         ]   5% (9.67 M)[#####                                                                                                         ]   5% (9.67 M)[######                                                                                                        ]   6% (9.67 M)[######                                                                                                        ]   6% (9.67 M)[######                                                                                                        ]   6% (9.67 M)[#######                                                                                                       ]   7% (9.67 M)[#######                                                                                                       ]   7% (9.67 M)[#######                                                                                                       ]   7% (9.67 M)[########                                                                                                      ]   8% (9.67 M)[########                                                                                                      ]   8% (9.67 M)[#########                                                                                                     ]   8% (9.67 M)[#########                                                                                                     ]   9% (9.67 M)[##########                                                                                                    ]   9% (9.67 M)[##########                                                                                                    ]  10% (9.67 M)[##########                                                                                                    ]  10% (9.67 M)[###########                                                                                                   ]  10% (9.67 M)[###########                                                                                                   ]  10% (9.67 M)[###########                                                                                                   ]  11% (9.67 M)[###########                                                                                                   ]  11% (9.67 M)[###########                                                                                                   ]  11% (9.67 M)[###########                                                                                                   ]  11% (9.67 M)[###########                                                                                                   ]  11% (9.67 M)[############                                                                                                  ]  11% (9.67 M)[############                                                                                                  ]  11% (9.67 M)[#############                                                                                                 ]  12% (9.67 M)[#############                                                                                                 ]  12% (9.67 M)[#############                                                                                                 ]  12% (9.67 M)[#############                                                                                                 ]  12% (9.67 M)[#############                                                                                                 ]  13% (9.67 M)[##############                                                                                                ]  13% (9.67 M)[##############                                                                                                ]  13% (9.67 M)[##############                                                                                                ]  13% (9.67 M)[###############                                                                                               ]  14% (9.67 M)[################                                                                                              ]  15% (9.67 M)[################                                                                                              ]  15% (9.67 M)[################                                                                                              ]  15% (9.67 M)[################                                                                                              ]  15% (9.67 M)[################                                                                                              ]  15% (9.67 M)[#################                                                                                             ]  16% (9.67 M)[#################                                                                                             ]  16% (9.67 M)[##################                                                                                            ]  17% (9.67 M)[##################                                                                                            ]  17% (9.67 M)[###################                                                                                           ]  17% (9.67 M)[###################                                                                                           ]  17% (9.67 M)[###################                                                                                           ]  17% (9.67 M)[###################                                                                                           ]  18% (9.67 M)[####################                                                                                          ]  18% (9.67 M)[####################                                                                                          ]  18% (9.67 M)[####################                                                                                          ]  19% (9.67 M)[####################                                                                                          ]  19% (9.67 M)[#####################                                                                                         ]  19% (9.67 M)[#####################                                                                                         ]  20% (9.67 M)[#####################                                                                                         ]  20% (9.67 M)[#####################                                                                                         ]  20% (9.67 M)[#####################                                                                                         ]  20% (9.67 M)[######################                                                                                        ]  20% (9.67 M)[######################                                                                                        ]  20% (9.67 M)[######################                                                                                        ]  20% (9.67 M)[######################                                                                                        ]  20% (9.67 M)[######################                                                                                        ]  20% (9.67 M)[######################                                                                                        ]  20% (9.67 M)[#######################                                                                                       ]  21% (9.67 M)[#######################                                                                                       ]  21% (9.67 M)[#######################                                                                                       ]  22% (9.67 M)[#######################                                                                                       ]  22% (9.67 M)[########################                                                                                      ]  22% (9.67 M)[########################                                                                                      ]  22% (9.67 M)[########################                                                                                      ]  22% (9.67 M)[########################                                                                                      ]  22% (9.67 M)[#########################                                                                                     ]  23% (9.67 M)[#########################                                                                                     ]  23% (9.67 M)[#########################                                                                                     ]  24% (9.67 M)[##########################                                                                                    ]  24% (9.67 M)[##########################                                                                                    ]  24% (9.67 M)[##########################                                                                                    ]  24% (9.67 M)[##########################                                                                                    ]  24% (9.67 M)[###########################                                                                                   ]  25% (9.67 M)[###########################                                                                                   ]  25% (9.67 M)[###########################                                                                                   ]  25% (9.67 M)[###########################                                                                                   ]  25% (9.67 M)[###########################                                                                                   ]  25% (9.67 M)[############################                                                                                  ]  26% (9.67 M)[############################                                                                                  ]  26% (9.67 M)[############################                                                                                  ]  26% (9.67 M)[############################                                                                                  ]  26% (9.67 M)[#############################                                                                                 ]  27% (9.67 M)[#############################                                                                                 ]  27% (9.67 M)[##############################                                                                                ]  27% (9.67 M)[##############################                                                                                ]  28% (9.67 M)[##############################                                                                                ]  28% (9.67 M)[###############################                                                                               ]  28% (9.67 M)[###############################                                                                               ]  29% (9.67 M)[################################                                                                              ]  29% (9.67 M)[################################                                                                              ]  30% (9.67 M)[#################################                                                                             ]  30% (9.67 M)[#################################                                                                             ]  31% (9.67 M)[#################################                                                                             ]  31% (9.67 M)[##################################                                                                            ]  31% (9.67 M)[##################################                                                                            ]  31% (9.67 M)[##################################                                                                            ]  31% (9.67 M)[##################################                                                                            ]  32% (9.67 M)[###################################                                                                           ]  32% (9.67 M)[###################################                                                                           ]  32% (9.67 M)[###################################                                                                           ]  32% (9.67 M)[###################################                                                                           ]  33% (9.67 M)[####################################                                                                          ]  33% (9.67 M)[####################################                                                                          ]  33% (9.67 M)[####################################                                                                          ]  33% (9.67 M)[#####################################                                                                         ]  34% (9.67 M)[#####################################                                                                         ]  34% (9.67 M)[#####################################                                                                         ]  34% (9.67 M)[#####################################                                                                         ]  34% (9.67 M)[#####################################                                                                         ]  35% (9.67 M)[######################################                                                                        ]  35% (9.67 M)[######################################                                                                        ]  35% (9.67 M)[######################################                                                                        ]  35% (9.67 M)[#######################################                                                                       ]  36% (9.67 M)[#######################################                                                                       ]  36% (9.67 M)[#######################################                                                                       ]  36% (9.67 M)[#######################################                                                                       ]  36% (9.67 M)[########################################                                                                      ]  36% (9.67 M)[########################################                                                                      ]  36% (9.67 M)[########################################                                                                      ]  37% (9.67 M)[########################################                                                                      ]  37% (9.67 M)[########################################                                                                      ]  37% (9.67 M)[#########################################                                                                     ]  37% (9.67 M)[#########################################                                                                     ]  37% (9.67 M)[#########################################                                                                     ]  38% (9.67 M)[#########################################                                                                     ]  38% (9.67 M)[#########################################                                                                     ]  38% (9.67 M)[##########################################                                                                    ]  38% (9.67 M)[##########################################                                                                    ]  38% (9.67 M)[##########################################                                                                    ]  39% (9.67 M)[##########################################                                                                    ]  39% (9.67 M)[###########################################                                                                   ]  39% (9.67 M)[###########################################                                                                   ]  40% (9.67 M)[############################################                                                                  ]  40% (9.67 M)[############################################                                                                  ]  40% (9.67 M)[#############################################                                                                 ]  41% (9.67 M)[#############################################                                                                 ]  42% (9.67 M)[##############################################                                                                ]  42% (9.67 M)[##############################################                                                                ]  43% (9.67 M)[###############################################                                                               ]  43% (9.67 M)[###############################################                                                               ]  43% (9.67 M)[################################################                                                              ]  44% (9.67 M)[################################################                                                              ]  44% (9.67 M)[#################################################                                                             ]  45% (9.67 M)[##################################################                                                            ]  46% (9.67 M)[##################################################                                                            ]  46% (9.67 M)[##################################################                                                            ]  46% (9.67 M)[###################################################                                                           ]  47% (9.67 M)[###################################################                                                           ]  47% (9.67 M)[####################################################                                                          ]  48% (9.67 M)[####################################################                                                          ]  48% (9.67 M)[#####################################################                                                         ]  49% (9.67 M)[######################################################                                                        ]  49% (9.67 M)[######################################################                                                        ]  50% (9.67 M)[#######################################################                                                       ]  50% (9.67 M)[#######################################################                                                       ]  51% (9.67 M)[########################################################                                                      ]  51% (9.67 M)[########################################################                                                      ]  51% (9.67 M)[########################################################                                                      ]  51% (9.67 M)[########################################################                                                      ]  51% (9.67 M)[########################################################                                                      ]  52% (9.67 M)[#########################################################                                                     ]  52% (9.67 M)[#########################################################                                                     ]  52% (9.67 M)[#########################################################                                                     ]  53% (9.67 M)[##########################################################                                                    ]  53% (9.67 M)[##########################################################                                                    ]  54% (9.67 M)[############################################################                                                  ]  55% (9.67 M)[############################################################                                                  ]  55% (9.67 M)[##############################################################                                                ]  56% (9.67 M)[##############################################################                                                ]  57% (9.67 M)[###############################################################                                               ]  58% (9.67 M)[###############################################################                                               ]  58% (9.67 M)[################################################################                                              ]  59% (9.67 M)[#################################################################                                             ]  59% (9.67 M)[##################################################################                                            ]  60% (9.67 M)[###################################################################                                           ]  61% (9.67 M)[###################################################################                                           ]  62% (9.67 M)[####################################################################                                          ]  62% (9.67 M)[#####################################################################                                         ]  63% (9.67 M)[#####################################################################                                         ]  63% (9.67 M)[######################################################################                                        ]  64% (9.67 M)[######################################################################                                        ]  64% (9.67 M)[#######################################################################                                       ]  65% (9.67 M)[#######################################################################                                       ]  65% (9.67 M)[########################################################################                                      ]  66% (9.67 M)[#########################################################################                                     ]  66% (9.67 M)[#########################################################################                                     ]  67% (9.67 M)[##########################################################################                                    ]  68% (9.67 M)[###########################################################################                                   ]  69% (9.67 M)[###########################################################################                                   ]  69% (9.67 M)[############################################################################                                  ]  69% (9.67 M)[############################################################################                                  ]  70% (9.67 M)[#############################################################################                                 ]  70% (9.67 M)[#############################################################################                                 ]  71% (9.67 M)[##############################################################################                                ]  71% (9.67 M)[###############################################################################                               ]  72% (9.67 M)[###############################################################################                               ]  72% (9.67 M)[################################################################################                              ]  73% (9.67 M)[################################################################################                              ]  74% (9.67 M)[#################################################################################                             ]  74% (9.67 M)[#################################################################################                             ]  74% (9.67 M)[##################################################################################                            ]  75% (9.67 M)[##################################################################################                            ]  75% (9.67 M)[###################################################################################                           ]  76% (9.67 M)[####################################################################################                          ]  77% (9.67 M)[#####################################################################################                         ]  77% (9.67 M)[#####################################################################################                         ]  78% (9.67 M)[######################################################################################                        ]  78% (9.67 M)[######################################################################################                        ]  79% (9.67 M)[#######################################################################################                       ]  80% (9.67 M)[########################################################################################                      ]  80% (9.67 M)[########################################################################################                      ]  80% (9.67 M)[#########################################################################################                     ]  81% (9.67 M)[#########################################################################################                     ]  81% (9.67 M)[##########################################################################################                    ]  82% (9.67 M)[##########################################################################################                    ]  82% (9.67 M)[##########################################################################################                    ]  83% (9.67 M)[##########################################################################################                    ]  83% (9.67 M)[###########################################################################################                   ]  83% (9.67 M)[###########################################################################################                   ]  83% (9.67 M)[############################################################################################                  ]  84% (9.67 M)[############################################################################################                  ]  84% (9.67 M)[#############################################################################################                 ]  85% (9.67 M)[#############################################################################################                 ]  85% (9.67 M)[##############################################################################################                ]  86% (9.67 M)[##############################################################################################                ]  86% (9.67 M)[###############################################################################################               ]  87% (9.67 M)[###############################################################################################               ]  87% (9.67 M)[###############################################################################################               ]  87% (9.67 M)[################################################################################################              ]  88% (9.67 M)[################################################################################################              ]  88% (9.67 M)[#################################################################################################             ]  88% (9.67 M)[#################################################################################################             ]  89% (9.67 M)[##################################################################################################            ]  89% (9.67 M)[##################################################################################################            ]  89% (9.67 M)[##################################################################################################            ]  89% (9.67 M)[##################################################################################################            ]  89% (9.67 M)[##################################################################################################            ]  90% (9.67 M)[##################################################################################################            ]  90% (9.67 M)[##################################################################################################            ]  90% (9.67 M)[###################################################################################################           ]  91% (9.67 M)[####################################################################################################          ]  91% (9.67 M)[####################################################################################################          ]  91% (9.67 M)[####################################################################################################          ]  91% (9.67 M)[####################################################################################################          ]  92% (9.67 M)[####################################################################################################          ]  92% (9.67 M)[#####################################################################################################         ]  92% (9.67 M)[#####################################################################################################         ]  92% (9.67 M)[#####################################################################################################         ]  92% (9.67 M)[#####################################################################################################         ]  93% (9.67 M)[#####################################################################################################         ]  93% (9.67 M)[######################################################################################################        ]  93% (9.67 M)[######################################################################################################        ]  93% (9.67 M)[######################################################################################################        ]  93% (9.67 M)[#######################################################################################################       ]  94% (9.67 M)[#######################################################################################################       ]  95% (9.67 M)[########################################################################################################      ]  95% (9.67 M)[########################################################################################################      ]  95% (9.67 M)[########################################################################################################      ]  95% (9.67 M)[########################################################################################################      ]  95% (9.67 M)[########################################################################################################      ]  95% (9.67 M)[########################################################################################################      ]  95% (9.67 M)[#########################################################################################################     ]  96% (9.67 M)[#########################################################################################################     ]  96% (9.67 M)[#########################################################################################################     ]  96% (9.67 M)[##########################################################################################################    ]  97% (9.67 M)[##########################################################################################################    ]  97% (9.67 M)[###########################################################################################################   ]  97% (9.67 M)[###########################################################################################################   ]  97% (9.67 M)[###########################################################################################################   ]  98% (9.67 M)[###########################################################################################################   ]  98% (9.67 M)[############################################################################################################  ]  99% (9.67 M)[############################################################################################################# ] 100% (9.67 M)[##############################################################################################################] 100% (9.67 M)                                                                                                                                [Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[New Thread 0x7ffff78bf6c0 (LWP 2770)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff78bf6c0 (LWP 2770)]
0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
warning: Currently logging to gdb.c.  Turn the logging off and on to make the new setting effective.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[New Thread 0x7ffff78bf6c0 (LWP 2820)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff78bf6c0 (LWP 2820)]
0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Breakpoint 1 at 0x7ffff7f8a3ae: file /usr/lib/zig/std/heap/SmpAllocator.zig, line 89.
Breakpoint 2 at 0x7ffff7f8a0f0: file /usr/lib/zig/std/heap/SmpAllocator.zig, line 168.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".

Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=1032, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
  Id   Target Id                                Frame 
* 1    Thread 0x7ffff7e8c780 (LWP 2821) "a.out" heap.SmpAllocator.alloc (context=0x0, len=1032, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
top_free_ptr = 0
next_addr = 0
cpu_count = 12
index = 1
class = 8
slot_size = 2048
search_count = 0 '\000'
t = 0x7ffff7fb4180 <heap.SmpAllocator.global+256>
Continuing.

Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=32, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
top_free_ptr = 0
next_addr = 0
cpu_count = 12
index = 2
class = 2
slot_size = 32
search_count = 0 '\000'
t = 0x7ffff7fb4280 <heap.SmpAllocator.global+512>
No symbol "thread_index" in current context.
Dump of assembler code for function heap.SmpAllocator.alloc:
   0x00007ffff7f89c20 <+0>:	push   rbp
   0x00007ffff7f89c21 <+1>:	mov    rbp,rsp
   0x00007ffff7f89c24 <+4>:	sub    rsp,0x120
   0x00007ffff7f89c2b <+11>:	mov    eax,ecx
   0x00007ffff7f89c2d <+13>:	mov    QWORD PTR [rbp-0x88],rdx
   0x00007ffff7f89c34 <+20>:	mov    rcx,rsi
   0x00007ffff7f89c37 <+23>:	mov    rsi,QWORD PTR [rbp-0x88]
   0x00007ffff7f89c3e <+30>:	mov    QWORD PTR [rbp-0x80],rdi
   0x00007ffff7f89c42 <+34>:	mov    BYTE PTR [rbp-0x71],al
   0x00007ffff7f89c45 <+37>:	mov    QWORD PTR [rbp-0x68],rcx
   0x00007ffff7f89c49 <+41>:	mov    QWORD PTR [rbp-0x60],rsi
   0x00007ffff7f89c4d <+45>:	mov    cl,al
   0x00007ffff7f89c4f <+47>:	and    cl,0x3f
   0x00007ffff7f89c52 <+50>:	mov    BYTE PTR [rbp-0x51],cl
   0x00007ffff7f89c55 <+53>:	mov    QWORD PTR [rbp-0x50],r8
   0x00007ffff7f89c59 <+57>:	movzx  edx,al
   0x00007ffff7f89c5c <+60>:	call   0x7ffff7f8a140 <heap.SmpAllocator.sizeClassIndex>
   0x00007ffff7f89c61 <+65>:	mov    QWORD PTR [rbp-0x70],rax
   0x00007ffff7f89c65 <+69>:	mov    QWORD PTR [rbp-0x48],rax
   0x00007ffff7f89c69 <+73>:	cmp    rax,0xd
   0x00007ffff7f89c6d <+77>:	jae    0x7ffff7f89c91 <heap.SmpAllocator.alloc+113>
   0x00007ffff7f89c6f <+79>:	jmp    0x7ffff7f89cb0 <heap.SmpAllocator.alloc+144>
   0x00007ffff7f89c71 <+81>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89c75 <+85>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89c79 <+89>:	call   0x7ffff7f8a200 <heap.SmpAllocator.slotSize>
   0x00007ffff7f89c7e <+94>:	mov    QWORD PTR [rbp-0x90],rax
   0x00007ffff7f89c85 <+101>:	mov    QWORD PTR [rbp-0x40],rax
   0x00007ffff7f89c89 <+105>:	cmp    rax,0x0
   0x00007ffff7f89c8d <+109>:	jne    0x7ffff7f89ce9 <heap.SmpAllocator.alloc+201>
   0x00007ffff7f89c8f <+111>:	jmp    0x7ffff7f89ceb <heap.SmpAllocator.alloc+203>
   0x00007ffff7f89c91 <+113>:	mov    rsi,QWORD PTR [rbp-0x88]
   0x00007ffff7f89c98 <+120>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89c9c <+124>:	mov    al,BYTE PTR [rbp-0x71]
   0x00007ffff7f89c9f <+127>:	movzx  edx,al
   0x00007ffff7f89ca2 <+130>:	call   0x7ffff7f889a0 <heap.PageAllocator.map>
   0x00007ffff7f89ca7 <+135>:	add    rsp,0x120
   0x00007ffff7f89cae <+142>:	pop    rbp
   0x00007ffff7f89caf <+143>:	ret
   0x00007ffff7f89cb0 <+144>:	jmp    0x7ffff7f89c71 <heap.SmpAllocator.alloc+81>
   0x00007ffff7f89cb2 <+146>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cb6 <+150>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89cbd <+157>:	mov    eax,0x10000
   0x00007ffff7f89cc2 <+162>:	xor    edx,edx
   0x00007ffff7f89cc4 <+164>:	div    rcx
   0x00007ffff7f89cc7 <+167>:	cmp    rdx,0x0
   0x00007ffff7f89ccb <+171>:	sete   al
   0x00007ffff7f89cce <+174>:	movzx  esi,al
   0x00007ffff7f89cd1 <+177>:	call   0x7ffff7ef2790 <debug.assert>
   0x00007ffff7f89cd6 <+182>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cda <+186>:	mov    BYTE PTR [rbp-0x31],0x0
   0x00007ffff7f89cde <+190>:	call   0x7ffff7f8a260 <heap.SmpAllocator.Thread.lock>
   0x00007ffff7f89ce3 <+195>:	mov    QWORD PTR [rbp-0x30],rax
   0x00007ffff7f89ce7 <+199>:	jmp    0x7ffff7f89cf4 <heap.SmpAllocator.alloc+212>
   0x00007ffff7f89ce9 <+201>:	jmp    0x7ffff7f89cb2 <heap.SmpAllocator.alloc+146>
   0x00007ffff7f89ceb <+203>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cef <+207>:	call   0x7ffff7f10e70 <debug.FullPanic((function 'defaultPanic')).divideByZero>
   0x00007ffff7f89cf4 <+212>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89cf8 <+216>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89cfc <+220>:	add    rcx,0x68
   0x00007ffff7f89d00 <+224>:	mov    QWORD PTR [rbp-0x98],rcx
   0x00007ffff7f89d07 <+231>:	cmp    rax,0xd
   0x00007ffff7f89d0b <+235>:	jb     0x7ffff7f89d33 <heap.SmpAllocator.alloc+275>
   0x00007ffff7f89d0d <+237>:	jmp    0x7ffff7f89d35 <heap.SmpAllocator.alloc+277>
   0x00007ffff7f89d0f <+239>:	jmp    0x7ffff7f89cf4 <heap.SmpAllocator.alloc+212>
   0x00007ffff7f89d11 <+241>:	mov    rax,QWORD PTR [rbp-0x98]
   0x00007ffff7f89d18 <+248>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d1c <+252>:	mov    rax,QWORD PTR [rax+rcx*8]
   0x00007ffff7f89d20 <+256>:	mov    QWORD PTR [rbp-0xa0],rax
   0x00007ffff7f89d27 <+263>:	mov    QWORD PTR [rbp-0x28],rax
   0x00007ffff7f89d2b <+267>:	cmp    rax,0x0
   0x00007ffff7f89d2f <+271>:	jne    0x7ffff7f89d65 <heap.SmpAllocator.alloc+325>
   0x00007ffff7f89d31 <+273>:	jmp    0x7ffff7f89d74 <heap.SmpAllocator.alloc+340>
   0x00007ffff7f89d33 <+275>:	jmp    0x7ffff7f89d11 <heap.SmpAllocator.alloc+241>
   0x00007ffff7f89d35 <+277>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d39 <+281>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89d3d <+285>:	mov    edx,0xd
   0x00007ffff7f89d42 <+290>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89d47 <+295>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d4b <+299>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89d4f <+303>:	mov    QWORD PTR [rbp-0xa8],rcx
   0x00007ffff7f89d56 <+310>:	cmp    rax,0xd
   0x00007ffff7f89d5a <+314>:	jb     0x7ffff7f89e37 <heap.SmpAllocator.alloc+535>
   0x00007ffff7f89d60 <+320>:	jmp    0x7ffff7f89e39 <heap.SmpAllocator.alloc+537>
   0x00007ffff7f89d65 <+325>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d6c <+332>:	cmp    rax,0x0
   0x00007ffff7f89d70 <+336>:	jne    0x7ffff7f89d89 <heap.SmpAllocator.alloc+361>
   0x00007ffff7f89d72 <+338>:	jmp    0x7ffff7f89d8b <heap.SmpAllocator.alloc+363>
   0x00007ffff7f89d74 <+340>:	jmp    0x7ffff7f89d47 <heap.SmpAllocator.alloc+295>
   0x00007ffff7f89d76 <+342>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d7d <+349>:	and    rax,0x7
   0x00007ffff7f89d81 <+353>:	cmp    rax,0x0
   0x00007ffff7f89d85 <+357>:	je     0x7ffff7f89dba <heap.SmpAllocator.alloc+410>
   0x00007ffff7f89d87 <+359>:	jmp    0x7ffff7f89dbc <heap.SmpAllocator.alloc+412>
   0x00007ffff7f89d89 <+361>:	jmp    0x7ffff7f89d76 <heap.SmpAllocator.alloc+342>
   0x00007ffff7f89d8b <+363>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89d8f <+367>:	call   0x7ffff7efa8d0 <debug.FullPanic((function 'defaultPanic')).castToNull>
   0x00007ffff7f89d94 <+372>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d98 <+376>:	mov    rcx,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d9f <+383>:	mov    QWORD PTR [rbp-0x20],rcx
   0x00007ffff7f89da3 <+387>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89da7 <+391>:	add    rcx,0x68
   0x00007ffff7f89dab <+395>:	mov    QWORD PTR [rbp-0xb0],rcx
   0x00007ffff7f89db2 <+402>:	cmp    rax,0xd
   0x00007ffff7f89db6 <+406>:	jb     0x7ffff7f89dfb <heap.SmpAllocator.alloc+475>
   0x00007ffff7f89db8 <+408>:	jmp    0x7ffff7f89dfd <heap.SmpAllocator.alloc+477>
   0x00007ffff7f89dba <+410>:	jmp    0x7ffff7f89d94 <heap.SmpAllocator.alloc+372>
   0x00007ffff7f89dbc <+412>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89dc0 <+416>:	call   0x7ffff7ef5d30 <debug.FullPanic((function 'defaultPanic')).incorrectAlignment>
   0x00007ffff7f89dc5 <+421>:	mov    rdx,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89dcc <+428>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89dd0 <+432>:	mov    rax,QWORD PTR [rbp-0xb0]
   0x00007ffff7f89dd7 <+439>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89ddb <+443>:	mov    rdx,QWORD PTR [rdx]
   0x00007ffff7f89dde <+446>:	mov    QWORD PTR [rax+rcx*8],rdx
   0x00007ffff7f89de2 <+450>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89de6 <+454>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89deb <+459>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89df2 <+466>:	add    rsp,0x120
   0x00007ffff7f89df9 <+473>:	pop    rbp
   0x00007ffff7f89dfa <+474>:	ret
   0x00007ffff7f89dfb <+475>:	jmp    0x7ffff7f89dc5 <heap.SmpAllocator.alloc+421>
   0x00007ffff7f89dfd <+477>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e01 <+481>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89e05 <+485>:	mov    edx,0xd
   0x00007ffff7f89e0a <+490>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89e0f <+495>:	mov    rax,QWORD PTR [rbp-0xa8]
   0x00007ffff7f89e16 <+502>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e1a <+506>:	mov    rax,QWORD PTR [rax+rcx*8]
   0x00007ffff7f89e1e <+510>:	mov    QWORD PTR [rbp-0xb8],rax
   0x00007ffff7f89e25 <+517>:	mov    QWORD PTR [rbp-0x18],rax
   0x00007ffff7f89e29 <+521>:	and    rax,0xffff
   0x00007ffff7f89e2f <+527>:	cmp    rax,0x0
   0x00007ffff7f89e33 <+531>:	jne    0x7ffff7f89e5a <heap.SmpAllocator.alloc+570>
   0x00007ffff7f89e35 <+533>:	jmp    0x7ffff7f89e71 <heap.SmpAllocator.alloc+593>
   0x00007ffff7f89e37 <+535>:	jmp    0x7ffff7f89e0f <heap.SmpAllocator.alloc+495>
   0x00007ffff7f89e39 <+537>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e3d <+541>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89e41 <+545>:	mov    edx,0xd
   0x00007ffff7f89e46 <+550>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89e4b <+555>:	cmp    BYTE PTR [rbp-0x31],0x1
   0x00007ffff7f89e4f <+559>:	jae    0x7ffff7f89f42 <heap.SmpAllocator.alloc+802>
   0x00007ffff7f89e55 <+565>:	jmp    0x7ffff7f89f70 <heap.SmpAllocator.alloc+848>
   0x00007ffff7f89e5a <+570>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e5e <+574>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89e62 <+578>:	mov    QWORD PTR [rbp-0xc0],rcx
   0x00007ffff7f89e69 <+585>:	cmp    rax,0xd
   0x00007ffff7f89e6d <+589>:	jb     0x7ffff7f89eab <heap.SmpAllocator.alloc+651>
   0x00007ffff7f89e6f <+591>:	jmp    0x7ffff7f89ead <heap.SmpAllocator.alloc+653>
   0x00007ffff7f89e71 <+593>:	jmp    0x7ffff7f89e4b <heap.SmpAllocator.alloc+555>
   0x00007ffff7f89e73 <+595>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89e7a <+602>:	mov    rax,QWORD PTR [rbp-0xb8]
   0x00007ffff7f89e81 <+609>:	mov    rdx,QWORD PTR [rbp-0xc0]
   0x00007ffff7f89e88 <+616>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e8c <+620>:	shl    rsi,0x3
   0x00007ffff7f89e90 <+624>:	add    rdx,rsi
   0x00007ffff7f89e93 <+627>:	mov    QWORD PTR [rbp-0xd0],rdx
   0x00007ffff7f89e9a <+634>:	add    rax,rcx
   0x00007ffff7f89e9d <+637>:	mov    QWORD PTR [rbp-0xc8],rax
   0x00007ffff7f89ea4 <+644>:	setb   al
   0x00007ffff7f89ea7 <+647>:	jb     0x7ffff7f89ebf <heap.SmpAllocator.alloc+671>
   0x00007ffff7f89ea9 <+649>:	jmp    0x7ffff7f89ec8 <heap.SmpAllocator.alloc+680>
   0x00007ffff7f89eab <+651>:	jmp    0x7ffff7f89e73 <heap.SmpAllocator.alloc+595>
   0x00007ffff7f89ead <+653>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89eb1 <+657>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89eb5 <+661>:	mov    edx,0xd
   0x00007ffff7f89eba <+666>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89ebf <+671>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89ec3 <+675>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f89ec8 <+680>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89ecc <+684>:	mov    rax,QWORD PTR [rbp-0xd0]
   0x00007ffff7f89ed3 <+691>:	mov    rcx,QWORD PTR [rbp-0xc8]
   0x00007ffff7f89eda <+698>:	mov    QWORD PTR [rax],rcx
   0x00007ffff7f89edd <+701>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89ee1 <+705>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89ee6 <+710>:	mov    rax,QWORD PTR [rbp-0xb8]
   0x00007ffff7f89eed <+717>:	add    rsp,0x120
   0x00007ffff7f89ef4 <+724>:	pop    rbp
   0x00007ffff7f89ef5 <+725>:	ret
   0x00007ffff7f89ef6 <+726>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89efa <+730>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89efe <+734>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89f03 <+739>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f07 <+743>:	call   0x7ffff7f8a410 <heap.SmpAllocator.getCpuCount>
   0x00007ffff7f89f0c <+748>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f10 <+752>:	mov    ecx,eax
   0x00007ffff7f89f12 <+754>:	mov    DWORD PTR [rbp-0xd4],ecx
   0x00007ffff7f89f18 <+760>:	mov    DWORD PTR [rbp-0x8],eax
   0x00007ffff7f89f1b <+763>:	test   eax,eax
   0x00007ffff7f89f1d <+765>:	setne  al
   0x00007ffff7f89f20 <+768>:	movzx  esi,al
   0x00007ffff7f89f23 <+771>:	call   0x7ffff7ef2790 <debug.assert>
   0x00007ffff7f89f28 <+776>:	lea    rdi,[rip+0x27bf1]        # 0x7ffff7fb1b20
   0x00007ffff7f89f2f <+783>:	call   0x7ffff7fae630 <__tls_get_addr@plt>
   0x00007ffff7f89f34 <+788>:	mov    eax,DWORD PTR [rax+0x10]
   0x00007ffff7f89f3a <+794>:	mov    DWORD PTR [rbp-0x4],eax
   0x00007ffff7f89f3d <+797>:	jmp    0x7ffff7f8a046 <heap.SmpAllocator.alloc+1062>
   0x00007ffff7f89f42 <+802>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f46 <+806>:	mov    esi,0x10000
   0x00007ffff7f89f4b <+811>:	call   0x7ffff7f18cd0 <mem.Alignment.fromByteUnits>
   0x00007ffff7f89f50 <+816>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f54 <+820>:	movzx  edx,al
   0x00007ffff7f89f57 <+823>:	mov    esi,0x10000
   0x00007ffff7f89f5c <+828>:	call   0x7ffff7f889a0 <heap.PageAllocator.map>
   0x00007ffff7f89f61 <+833>:	mov    QWORD PTR [rbp-0xe0],rax
   0x00007ffff7f89f68 <+840>:	cmp    rax,0x0
   0x00007ffff7f89f6c <+844>:	jne    0x7ffff7f89f9b <heap.SmpAllocator.alloc+891>
   0x00007ffff7f89f6e <+846>:	jmp    0x7ffff7f89fab <heap.SmpAllocator.alloc+907>
   0x00007ffff7f89f70 <+848>:	jmp    0x7ffff7f89ef6 <heap.SmpAllocator.alloc+726>
   0x00007ffff7f89f72 <+850>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89f76 <+854>:	mov    rcx,QWORD PTR [rbp-0xf8]
   0x00007ffff7f89f7d <+861>:	mov    QWORD PTR [rbp-0xf0],rcx
   0x00007ffff7f89f84 <+868>:	mov    QWORD PTR [rbp-0x10],rcx
   0x00007ffff7f89f88 <+872>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89f8c <+876>:	mov    QWORD PTR [rbp-0xe8],rcx
   0x00007ffff7f89f93 <+883>:	cmp    rax,0xd
   0x00007ffff7f89f97 <+887>:	jb     0x7ffff7f89ffb <heap.SmpAllocator.alloc+987>
   0x00007ffff7f89f99 <+889>:	jmp    0x7ffff7f89ffd <heap.SmpAllocator.alloc+989>
   0x00007ffff7f89f9b <+891>:	mov    rax,QWORD PTR [rbp-0xe0]
   0x00007ffff7f89fa2 <+898>:	mov    QWORD PTR [rbp-0xf8],rax
   0x00007ffff7f89fa9 <+905>:	jmp    0x7ffff7f89f72 <heap.SmpAllocator.alloc+850>
   0x00007ffff7f89fab <+907>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89faf <+911>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89fb3 <+915>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89fb8 <+920>:	xor    eax,eax
   0x00007ffff7f89fba <+922>:	add    rsp,0x120
   0x00007ffff7f89fc1 <+929>:	pop    rbp
   0x00007ffff7f89fc2 <+930>:	ret
   0x00007ffff7f89fc3 <+931>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89fca <+938>:	mov    rax,QWORD PTR [rbp-0xf0]
   0x00007ffff7f89fd1 <+945>:	mov    rdx,QWORD PTR [rbp-0xe8]
   0x00007ffff7f89fd8 <+952>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89fdc <+956>:	shl    rsi,0x3
   0x00007ffff7f89fe0 <+960>:	add    rdx,rsi
   0x00007ffff7f89fe3 <+963>:	mov    QWORD PTR [rbp-0x108],rdx
   0x00007ffff7f89fea <+970>:	add    rax,rcx
   0x00007ffff7f89fed <+973>:	mov    QWORD PTR [rbp-0x100],rax
   0x00007ffff7f89ff4 <+980>:	setb   al
   0x00007ffff7f89ff7 <+983>:	jb     0x7ffff7f8a00f <heap.SmpAllocator.alloc+1007>
   0x00007ffff7f89ff9 <+985>:	jmp    0x7ffff7f8a018 <heap.SmpAllocator.alloc+1016>
   0x00007ffff7f89ffb <+987>:	jmp    0x7ffff7f89fc3 <heap.SmpAllocator.alloc+931>
   0x00007ffff7f89ffd <+989>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f8a001 <+993>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a005 <+997>:	mov    edx,0xd
   0x00007ffff7f8a00a <+1002>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f8a00f <+1007>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a013 <+1011>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a018 <+1016>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a01c <+1020>:	mov    rax,QWORD PTR [rbp-0x108]
   0x00007ffff7f8a023 <+1027>:	mov    rcx,QWORD PTR [rbp-0x100]
   0x00007ffff7f8a02a <+1034>:	mov    QWORD PTR [rax],rcx
   0x00007ffff7f8a02d <+1037>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f8a031 <+1041>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f8a036 <+1046>:	mov    rax,QWORD PTR [rbp-0xf0]
   0x00007ffff7f8a03d <+1053>:	add    rsp,0x120
   0x00007ffff7f8a044 <+1060>:	pop    rbp
   0x00007ffff7f8a045 <+1061>:	ret
   0x00007ffff7f8a046 <+1062>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a049 <+1065>:	add    eax,0x1
   0x00007ffff7f8a04c <+1068>:	mov    DWORD PTR [rbp-0x10c],eax
   0x00007ffff7f8a052 <+1074>:	setb   al
   0x00007ffff7f8a055 <+1077>:	jb     0x7ffff7f8a059 <heap.SmpAllocator.alloc+1081>
   0x00007ffff7f8a057 <+1079>:	jmp    0x7ffff7f8a062 <heap.SmpAllocator.alloc+1090>
   0x00007ffff7f8a059 <+1081>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a05d <+1085>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a062 <+1090>:	mov    eax,DWORD PTR [rbp-0xd4]
   0x00007ffff7f8a068 <+1096>:	cmp    eax,0x0
   0x00007ffff7f8a06b <+1099>:	jne    0x7ffff7f8a096 <heap.SmpAllocator.alloc+1142>
   0x00007ffff7f8a06d <+1101>:	jmp    0x7ffff7f8a098 <heap.SmpAllocator.alloc+1144>
   0x00007ffff7f8a06f <+1103>:	mov    ecx,DWORD PTR [rbp-0xd4]
   0x00007ffff7f8a075 <+1109>:	mov    eax,DWORD PTR [rbp-0x10c]
   0x00007ffff7f8a07b <+1115>:	xor    edx,edx
   0x00007ffff7f8a07d <+1117>:	div    ecx
   0x00007ffff7f8a07f <+1119>:	mov    DWORD PTR [rbp-0x4],edx
   0x00007ffff7f8a082 <+1122>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a085 <+1125>:	mov    QWORD PTR [rbp-0x118],rax
   0x00007ffff7f8a08c <+1132>:	cmp    rax,0x80
   0x00007ffff7f8a092 <+1138>:	jb     0x7ffff7f8a0d4 <heap.SmpAllocator.alloc+1204>
   0x00007ffff7f8a094 <+1140>:	jmp    0x7ffff7f8a0d6 <heap.SmpAllocator.alloc+1206>
   0x00007ffff7f8a096 <+1142>:	jmp    0x7ffff7f8a06f <heap.SmpAllocator.alloc+1103>
   0x00007ffff7f8a098 <+1144>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a09c <+1148>:	call   0x7ffff7f10e70 <debug.FullPanic((function 'defaultPanic')).divideByZero>
   0x00007ffff7f8a0a1 <+1153>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a0a5 <+1157>:	mov    rcx,QWORD PTR [rbp-0x118]
   0x00007ffff7f8a0ac <+1164>:	lea    rax,[rip+0x29fcd]        # 0x7ffff7fb4080 <heap.SmpAllocator.global>
   0x00007ffff7f8a0b3 <+1171>:	shl    rcx,0x8
   0x00007ffff7f8a0b7 <+1175>:	add    rax,rcx
   0x00007ffff7f8a0ba <+1178>:	mov    QWORD PTR [rbp-0x30],rax
   0x00007ffff7f8a0be <+1182>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f8a0c2 <+1186>:	add    rsi,0xd0
   0x00007ffff7f8a0c9 <+1193>:	call   0x7ffff7f8a4e0 <Thread.Mutex.tryLock>
   0x00007ffff7f8a0ce <+1198>:	test   al,0x1
   0x00007ffff7f8a0d0 <+1200>:	jne    0x7ffff7f8a0f0 <heap.SmpAllocator.alloc+1232>
   0x00007ffff7f8a0d2 <+1202>:	jmp    0x7ffff7f8a125 <heap.SmpAllocator.alloc+1285>
   0x00007ffff7f8a0d4 <+1204>:	jmp    0x7ffff7f8a0a1 <heap.SmpAllocator.alloc+1153>
   0x00007ffff7f8a0d6 <+1206>:	mov    rsi,QWORD PTR [rbp-0x118]
   0x00007ffff7f8a0dd <+1213>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a0e1 <+1217>:	mov    edx,0x80
   0x00007ffff7f8a0e6 <+1222>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f8a0eb <+1227>:	jmp    0x7ffff7f8a046 <heap.SmpAllocator.alloc+1062>
=> 0x00007ffff7f8a0f0 <+1232>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a0f3 <+1235>:	mov    DWORD PTR [rbp-0x120],eax
   0x00007ffff7f8a0f9 <+1241>:	lea    rdi,[rip+0x27a20]        # 0x7ffff7fb1b20
   0x00007ffff7f8a100 <+1248>:	call   0x7ffff7fae630 <__tls_get_addr@plt>
   0x00007ffff7f8a105 <+1253>:	mov    ecx,DWORD PTR [rbp-0x120]
   0x00007ffff7f8a10b <+1259>:	mov    DWORD PTR [rax+0x10],ecx
   0x00007ffff7f8a111 <+1265>:	mov    al,BYTE PTR [rbp-0x31]
   0x00007ffff7f8a114 <+1268>:	add    al,0x1
   0x00007ffff7f8a116 <+1270>:	mov    BYTE PTR [rbp-0x119],al
   0x00007ffff7f8a11c <+1276>:	setb   al
   0x00007ffff7f8a11f <+1279>:	test   al,0x1
   0x00007ffff7f8a121 <+1281>:	jne    0x7ffff7f8a127 <heap.SmpAllocator.alloc+1287>
   0x00007ffff7f8a123 <+1283>:	jmp    0x7ffff7f8a130 <heap.SmpAllocator.alloc+1296>
   0x00007ffff7f8a125 <+1285>:	jmp    0x7ffff7f8a0eb <heap.SmpAllocator.alloc+1227>
   0x00007ffff7f8a127 <+1287>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a12b <+1291>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a130 <+1296>:	mov    al,BYTE PTR [rbp-0x119]
   0x00007ffff7f8a136 <+1302>:	mov    BYTE PTR [rbp-0x31],al
   0x00007ffff7f8a139 <+1305>:	jmp    0x7ffff7f89d0f <heap.SmpAllocator.alloc+239>
End of assembler dump.
0x00007ffff7f8a0f3	168	                thread_index = index;
0x00007ffff7f8a0f9	168	                thread_index = index;
0x00007ffff7f8a100	168	                thread_index = index;
0x00007ffff7f8a105	168	                thread_index = index;
0x00007ffff7f8a10b	168	                thread_index = index;
169	                search_count += 1;
#0  heap.SmpAllocator.alloc (context=0x0, len=32, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:169
#1  0x00007ffff7f346ba in mem.Allocator.rawAlloc () at /usr/lib/zig/std/mem/Allocator.zig:129
#2  mem.Allocator.allocBytesWithAlignment__anon_14706 (self=..., byte_count=32, return_address=140737353643937) at /usr/lib/zig/std/mem/Allocator.zig:269
#3  0x00007ffff7f26313 in mem.Allocator.allocWithSizeAndAlignment__anon_11852 (self=..., n=32, return_address=140737353643937) at /usr/lib/zig/std/mem/Allocator.zig:260
#4  0x00007ffff7f0ec22 in mem.Allocator.allocAdvancedWithRetAddr () at /usr/lib/zig/std/mem/Allocator.zig:254
#5  mem.Allocator.alloc__anon_8671 (self=..., n=32) at /usr/lib/zig/std/mem/Allocator.zig:178
#6  0x00007ffff7f877a1 in root.internal_malloc (len=24, zeroed=false) at root.zig:12
#7  0x00007ffff7f876fb in root.malloc (len=24) at root.zig:28
#8  0x00007ffff7caebc5 in operator new (sz=24) at /usr/src/debug/gcc/gcc/libstdc++-v3/libsupc++/new_op.cc:50
#9  0x00005555555574ec in std::thread::thread<void* (&)(void*), void*, void> (this=0x7ffffffd8078, __f=@0x5555555572fe: {void *(void *)} 0x5555555572fe <runRandomTest<NewDeleteAllocatorForTest>(void*)>) at /usr/include/c++/14.2.1/bits/std_thread.h:173
#10 0x0000555555556ec1 in runTest<NewDeleteAllocatorForTest> (startupParams=0x7ffffffd8a30) at allocator_tester.cpp:83
#11 0x00005555555569f5 in main (argc=2, argv=0x7fffffffd7a8) at allocator_tester.cpp:141
0x00007ffff7f8a114	169	                search_count += 1;
170	                continue :outer;
#0  heap.SmpAllocator.alloc (context=0x0, len=32, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:170
#1  0x00007ffff7f346ba in mem.Allocator.rawAlloc () at /usr/lib/zig/std/mem/Allocator.zig:129
#2  mem.Allocator.allocBytesWithAlignment__anon_14706 (self=..., byte_count=32, return_address=140737353643937) at /usr/lib/zig/std/mem/Allocator.zig:269
#3  0x00007ffff7f26313 in mem.Allocator.allocWithSizeAndAlignment__anon_11852 (self=..., n=32, return_address=140737353643937) at /usr/lib/zig/std/mem/Allocator.zig:260
#4  0x00007ffff7f0ec22 in mem.Allocator.allocAdvancedWithRetAddr () at /usr/lib/zig/std/mem/Allocator.zig:254
#5  mem.Allocator.alloc__anon_8671 (self=..., n=32) at /usr/lib/zig/std/mem/Allocator.zig:178
#6  0x00007ffff7f877a1 in root.internal_malloc (len=24, zeroed=false) at root.zig:12
#7  0x00007ffff7f876fb in root.malloc (len=24) at root.zig:28
#8  0x00007ffff7caebc5 in operator new (sz=24) at /usr/src/debug/gcc/gcc/libstdc++-v3/libsupc++/new_op.cc:50
#9  0x00005555555574ec in std::thread::thread<void* (&)(void*), void*, void> (this=0x7ffffffd8078, __f=@0x5555555572fe: {void *(void *)} 0x5555555572fe <runRandomTest<NewDeleteAllocatorForTest>(void*)>) at /usr/include/c++/14.2.1/bits/std_thread.h:173
#10 0x0000555555556ec1 in runTest<NewDeleteAllocatorForTest> (startupParams=0x7ffffffd8a30) at allocator_tester.cpp:83
#11 0x00005555555569f5 in main (argc=2, argv=0x7fffffffd7a8) at allocator_tester.cpp:141
172	        }
#0  heap.SmpAllocator.alloc (context=0x0, len=32, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:172
#1  0x00007ffff7f346ba in mem.Allocator.rawAlloc () at /usr/lib/zig/std/mem/Allocator.zig:129
#2  mem.Allocator.allocBytesWithAlignment__anon_14706 (self=..., byte_count=32, return_address=140737353643937) at /usr/lib/zig/std/mem/Allocator.zig:269
#3  0x00007ffff7f26313 in mem.Allocator.allocWithSizeAndAlignment__anon_11852 (self=..., n=32, return_address=140737353643937) at /usr/lib/zig/std/mem/Allocator.zig:260
#4  0x00007ffff7f0ec22 in mem.Allocator.allocAdvancedWithRetAddr () at /usr/lib/zig/std/mem/Allocator.zig:254
#5  mem.Allocator.alloc__anon_8671 (self=..., n=32) at /usr/lib/zig/std/mem/Allocator.zig:178
#6  0x00007ffff7f877a1 in root.internal_malloc (len=24, zeroed=false) at root.zig:12
#7  0x00007ffff7f876fb in root.malloc (len=24) at root.zig:28
#8  0x00007ffff7caebc5 in operator new (sz=24) at /usr/src/debug/gcc/gcc/libstdc++-v3/libsupc++/new_op.cc:50
#9  0x00005555555574ec in std::thread::thread<void* (&)(void*), void*, void> (this=0x7ffffffd8078, __f=@0x5555555572fe: {void *(void *)} 0x5555555572fe <runRandomTest<NewDeleteAllocatorForTest>(void*)>) at /usr/include/c++/14.2.1/bits/std_thread.h:173
#10 0x0000555555556ec1 in runTest<NewDeleteAllocatorForTest> (startupParams=0x7ffffffd8a30) at allocator_tester.cpp:83
#11 0x00005555555569f5 in main (argc=2, argv=0x7fffffffd7a8) at allocator_tester.cpp:141
Dump of assembler code for function heap.SmpAllocator.alloc:
   0x00007ffff7f89c20 <+0>:	push   rbp
   0x00007ffff7f89c21 <+1>:	mov    rbp,rsp
   0x00007ffff7f89c24 <+4>:	sub    rsp,0x120
   0x00007ffff7f89c2b <+11>:	mov    eax,ecx
   0x00007ffff7f89c2d <+13>:	mov    QWORD PTR [rbp-0x88],rdx
   0x00007ffff7f89c34 <+20>:	mov    rcx,rsi
   0x00007ffff7f89c37 <+23>:	mov    rsi,QWORD PTR [rbp-0x88]
   0x00007ffff7f89c3e <+30>:	mov    QWORD PTR [rbp-0x80],rdi
   0x00007ffff7f89c42 <+34>:	mov    BYTE PTR [rbp-0x71],al
   0x00007ffff7f89c45 <+37>:	mov    QWORD PTR [rbp-0x68],rcx
   0x00007ffff7f89c49 <+41>:	mov    QWORD PTR [rbp-0x60],rsi
   0x00007ffff7f89c4d <+45>:	mov    cl,al
   0x00007ffff7f89c4f <+47>:	and    cl,0x3f
   0x00007ffff7f89c52 <+50>:	mov    BYTE PTR [rbp-0x51],cl
   0x00007ffff7f89c55 <+53>:	mov    QWORD PTR [rbp-0x50],r8
   0x00007ffff7f89c59 <+57>:	movzx  edx,al
   0x00007ffff7f89c5c <+60>:	call   0x7ffff7f8a140 <heap.SmpAllocator.sizeClassIndex>
   0x00007ffff7f89c61 <+65>:	mov    QWORD PTR [rbp-0x70],rax
   0x00007ffff7f89c65 <+69>:	mov    QWORD PTR [rbp-0x48],rax
   0x00007ffff7f89c69 <+73>:	cmp    rax,0xd
   0x00007ffff7f89c6d <+77>:	jae    0x7ffff7f89c91 <heap.SmpAllocator.alloc+113>
   0x00007ffff7f89c6f <+79>:	jmp    0x7ffff7f89cb0 <heap.SmpAllocator.alloc+144>
   0x00007ffff7f89c71 <+81>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89c75 <+85>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89c79 <+89>:	call   0x7ffff7f8a200 <heap.SmpAllocator.slotSize>
   0x00007ffff7f89c7e <+94>:	mov    QWORD PTR [rbp-0x90],rax
   0x00007ffff7f89c85 <+101>:	mov    QWORD PTR [rbp-0x40],rax
   0x00007ffff7f89c89 <+105>:	cmp    rax,0x0
   0x00007ffff7f89c8d <+109>:	jne    0x7ffff7f89ce9 <heap.SmpAllocator.alloc+201>
   0x00007ffff7f89c8f <+111>:	jmp    0x7ffff7f89ceb <heap.SmpAllocator.alloc+203>
   0x00007ffff7f89c91 <+113>:	mov    rsi,QWORD PTR [rbp-0x88]
   0x00007ffff7f89c98 <+120>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89c9c <+124>:	mov    al,BYTE PTR [rbp-0x71]
   0x00007ffff7f89c9f <+127>:	movzx  edx,al
   0x00007ffff7f89ca2 <+130>:	call   0x7ffff7f889a0 <heap.PageAllocator.map>
   0x00007ffff7f89ca7 <+135>:	add    rsp,0x120
   0x00007ffff7f89cae <+142>:	pop    rbp
   0x00007ffff7f89caf <+143>:	ret
   0x00007ffff7f89cb0 <+144>:	jmp    0x7ffff7f89c71 <heap.SmpAllocator.alloc+81>
   0x00007ffff7f89cb2 <+146>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cb6 <+150>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89cbd <+157>:	mov    eax,0x10000
   0x00007ffff7f89cc2 <+162>:	xor    edx,edx
   0x00007ffff7f89cc4 <+164>:	div    rcx
   0x00007ffff7f89cc7 <+167>:	cmp    rdx,0x0
   0x00007ffff7f89ccb <+171>:	sete   al
   0x00007ffff7f89cce <+174>:	movzx  esi,al
   0x00007ffff7f89cd1 <+177>:	call   0x7ffff7ef2790 <debug.assert>
   0x00007ffff7f89cd6 <+182>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cda <+186>:	mov    BYTE PTR [rbp-0x31],0x0
   0x00007ffff7f89cde <+190>:	call   0x7ffff7f8a260 <heap.SmpAllocator.Thread.lock>
   0x00007ffff7f89ce3 <+195>:	mov    QWORD PTR [rbp-0x30],rax
   0x00007ffff7f89ce7 <+199>:	jmp    0x7ffff7f89cf4 <heap.SmpAllocator.alloc+212>
   0x00007ffff7f89ce9 <+201>:	jmp    0x7ffff7f89cb2 <heap.SmpAllocator.alloc+146>
   0x00007ffff7f89ceb <+203>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cef <+207>:	call   0x7ffff7f10e70 <debug.FullPanic((function 'defaultPanic')).divideByZero>
   0x00007ffff7f89cf4 <+212>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89cf8 <+216>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89cfc <+220>:	add    rcx,0x68
   0x00007ffff7f89d00 <+224>:	mov    QWORD PTR [rbp-0x98],rcx
   0x00007ffff7f89d07 <+231>:	cmp    rax,0xd
   0x00007ffff7f89d0b <+235>:	jb     0x7ffff7f89d33 <heap.SmpAllocator.alloc+275>
   0x00007ffff7f89d0d <+237>:	jmp    0x7ffff7f89d35 <heap.SmpAllocator.alloc+277>
=> 0x00007ffff7f89d0f <+239>:	jmp    0x7ffff7f89cf4 <heap.SmpAllocator.alloc+212>
   0x00007ffff7f89d11 <+241>:	mov    rax,QWORD PTR [rbp-0x98]
   0x00007ffff7f89d18 <+248>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d1c <+252>:	mov    rax,QWORD PTR [rax+rcx*8]
   0x00007ffff7f89d20 <+256>:	mov    QWORD PTR [rbp-0xa0],rax
   0x00007ffff7f89d27 <+263>:	mov    QWORD PTR [rbp-0x28],rax
   0x00007ffff7f89d2b <+267>:	cmp    rax,0x0
   0x00007ffff7f89d2f <+271>:	jne    0x7ffff7f89d65 <heap.SmpAllocator.alloc+325>
   0x00007ffff7f89d31 <+273>:	jmp    0x7ffff7f89d74 <heap.SmpAllocator.alloc+340>
   0x00007ffff7f89d33 <+275>:	jmp    0x7ffff7f89d11 <heap.SmpAllocator.alloc+241>
   0x00007ffff7f89d35 <+277>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d39 <+281>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89d3d <+285>:	mov    edx,0xd
   0x00007ffff7f89d42 <+290>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89d47 <+295>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d4b <+299>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89d4f <+303>:	mov    QWORD PTR [rbp-0xa8],rcx
   0x00007ffff7f89d56 <+310>:	cmp    rax,0xd
   0x00007ffff7f89d5a <+314>:	jb     0x7ffff7f89e37 <heap.SmpAllocator.alloc+535>
   0x00007ffff7f89d60 <+320>:	jmp    0x7ffff7f89e39 <heap.SmpAllocator.alloc+537>
   0x00007ffff7f89d65 <+325>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d6c <+332>:	cmp    rax,0x0
   0x00007ffff7f89d70 <+336>:	jne    0x7ffff7f89d89 <heap.SmpAllocator.alloc+361>
   0x00007ffff7f89d72 <+338>:	jmp    0x7ffff7f89d8b <heap.SmpAllocator.alloc+363>
   0x00007ffff7f89d74 <+340>:	jmp    0x7ffff7f89d47 <heap.SmpAllocator.alloc+295>
   0x00007ffff7f89d76 <+342>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d7d <+349>:	and    rax,0x7
   0x00007ffff7f89d81 <+353>:	cmp    rax,0x0
   0x00007ffff7f89d85 <+357>:	je     0x7ffff7f89dba <heap.SmpAllocator.alloc+410>
   0x00007ffff7f89d87 <+359>:	jmp    0x7ffff7f89dbc <heap.SmpAllocator.alloc+412>
   0x00007ffff7f89d89 <+361>:	jmp    0x7ffff7f89d76 <heap.SmpAllocator.alloc+342>
   0x00007ffff7f89d8b <+363>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89d8f <+367>:	call   0x7ffff7efa8d0 <debug.FullPanic((function 'defaultPanic')).castToNull>
   0x00007ffff7f89d94 <+372>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d98 <+376>:	mov    rcx,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d9f <+383>:	mov    QWORD PTR [rbp-0x20],rcx
   0x00007ffff7f89da3 <+387>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89da7 <+391>:	add    rcx,0x68
   0x00007ffff7f89dab <+395>:	mov    QWORD PTR [rbp-0xb0],rcx
   0x00007ffff7f89db2 <+402>:	cmp    rax,0xd
   0x00007ffff7f89db6 <+406>:	jb     0x7ffff7f89dfb <heap.SmpAllocator.alloc+475>
   0x00007ffff7f89db8 <+408>:	jmp    0x7ffff7f89dfd <heap.SmpAllocator.alloc+477>
   0x00007ffff7f89dba <+410>:	jmp    0x7ffff7f89d94 <heap.SmpAllocator.alloc+372>
   0x00007ffff7f89dbc <+412>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89dc0 <+416>:	call   0x7ffff7ef5d30 <debug.FullPanic((function 'defaultPanic')).incorrectAlignment>
   0x00007ffff7f89dc5 <+421>:	mov    rdx,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89dcc <+428>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89dd0 <+432>:	mov    rax,QWORD PTR [rbp-0xb0]
   0x00007ffff7f89dd7 <+439>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89ddb <+443>:	mov    rdx,QWORD PTR [rdx]
   0x00007ffff7f89dde <+446>:	mov    QWORD PTR [rax+rcx*8],rdx
   0x00007ffff7f89de2 <+450>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89de6 <+454>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89deb <+459>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89df2 <+466>:	add    rsp,0x120
   0x00007ffff7f89df9 <+473>:	pop    rbp
   0x00007ffff7f89dfa <+474>:	ret
   0x00007ffff7f89dfb <+475>:	jmp    0x7ffff7f89dc5 <heap.SmpAllocator.alloc+421>
   0x00007ffff7f89dfd <+477>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e01 <+481>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89e05 <+485>:	mov    edx,0xd
   0x00007ffff7f89e0a <+490>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89e0f <+495>:	mov    rax,QWORD PTR [rbp-0xa8]
   0x00007ffff7f89e16 <+502>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e1a <+506>:	mov    rax,QWORD PTR [rax+rcx*8]
   0x00007ffff7f89e1e <+510>:	mov    QWORD PTR [rbp-0xb8],rax
   0x00007ffff7f89e25 <+517>:	mov    QWORD PTR [rbp-0x18],rax
   0x00007ffff7f89e29 <+521>:	and    rax,0xffff
   0x00007ffff7f89e2f <+527>:	cmp    rax,0x0
   0x00007ffff7f89e33 <+531>:	jne    0x7ffff7f89e5a <heap.SmpAllocator.alloc+570>
   0x00007ffff7f89e35 <+533>:	jmp    0x7ffff7f89e71 <heap.SmpAllocator.alloc+593>
   0x00007ffff7f89e37 <+535>:	jmp    0x7ffff7f89e0f <heap.SmpAllocator.alloc+495>
   0x00007ffff7f89e39 <+537>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e3d <+541>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89e41 <+545>:	mov    edx,0xd
   0x00007ffff7f89e46 <+550>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89e4b <+555>:	cmp    BYTE PTR [rbp-0x31],0x1
   0x00007ffff7f89e4f <+559>:	jae    0x7ffff7f89f42 <heap.SmpAllocator.alloc+802>
   0x00007ffff7f89e55 <+565>:	jmp    0x7ffff7f89f70 <heap.SmpAllocator.alloc+848>
   0x00007ffff7f89e5a <+570>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e5e <+574>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89e62 <+578>:	mov    QWORD PTR [rbp-0xc0],rcx
   0x00007ffff7f89e69 <+585>:	cmp    rax,0xd
   0x00007ffff7f89e6d <+589>:	jb     0x7ffff7f89eab <heap.SmpAllocator.alloc+651>
   0x00007ffff7f89e6f <+591>:	jmp    0x7ffff7f89ead <heap.SmpAllocator.alloc+653>
   0x00007ffff7f89e71 <+593>:	jmp    0x7ffff7f89e4b <heap.SmpAllocator.alloc+555>
   0x00007ffff7f89e73 <+595>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89e7a <+602>:	mov    rax,QWORD PTR [rbp-0xb8]
   0x00007ffff7f89e81 <+609>:	mov    rdx,QWORD PTR [rbp-0xc0]
   0x00007ffff7f89e88 <+616>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e8c <+620>:	shl    rsi,0x3
   0x00007ffff7f89e90 <+624>:	add    rdx,rsi
   0x00007ffff7f89e93 <+627>:	mov    QWORD PTR [rbp-0xd0],rdx
   0x00007ffff7f89e9a <+634>:	add    rax,rcx
   0x00007ffff7f89e9d <+637>:	mov    QWORD PTR [rbp-0xc8],rax
   0x00007ffff7f89ea4 <+644>:	setb   al
   0x00007ffff7f89ea7 <+647>:	jb     0x7ffff7f89ebf <heap.SmpAllocator.alloc+671>
   0x00007ffff7f89ea9 <+649>:	jmp    0x7ffff7f89ec8 <heap.SmpAllocator.alloc+680>
   0x00007ffff7f89eab <+651>:	jmp    0x7ffff7f89e73 <heap.SmpAllocator.alloc+595>
   0x00007ffff7f89ead <+653>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89eb1 <+657>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89eb5 <+661>:	mov    edx,0xd
   0x00007ffff7f89eba <+666>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89ebf <+671>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89ec3 <+675>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f89ec8 <+680>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89ecc <+684>:	mov    rax,QWORD PTR [rbp-0xd0]
   0x00007ffff7f89ed3 <+691>:	mov    rcx,QWORD PTR [rbp-0xc8]
   0x00007ffff7f89eda <+698>:	mov    QWORD PTR [rax],rcx
   0x00007ffff7f89edd <+701>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89ee1 <+705>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89ee6 <+710>:	mov    rax,QWORD PTR [rbp-0xb8]
   0x00007ffff7f89eed <+717>:	add    rsp,0x120
   0x00007ffff7f89ef4 <+724>:	pop    rbp
   0x00007ffff7f89ef5 <+725>:	ret
   0x00007ffff7f89ef6 <+726>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89efa <+730>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89efe <+734>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89f03 <+739>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f07 <+743>:	call   0x7ffff7f8a410 <heap.SmpAllocator.getCpuCount>
   0x00007ffff7f89f0c <+748>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f10 <+752>:	mov    ecx,eax
   0x00007ffff7f89f12 <+754>:	mov    DWORD PTR [rbp-0xd4],ecx
   0x00007ffff7f89f18 <+760>:	mov    DWORD PTR [rbp-0x8],eax
   0x00007ffff7f89f1b <+763>:	test   eax,eax
   0x00007ffff7f89f1d <+765>:	setne  al
   0x00007ffff7f89f20 <+768>:	movzx  esi,al
   0x00007ffff7f89f23 <+771>:	call   0x7ffff7ef2790 <debug.assert>
   0x00007ffff7f89f28 <+776>:	lea    rdi,[rip+0x27bf1]        # 0x7ffff7fb1b20
   0x00007ffff7f89f2f <+783>:	call   0x7ffff7fae630 <__tls_get_addr@plt>
   0x00007ffff7f89f34 <+788>:	mov    eax,DWORD PTR [rax+0x10]
   0x00007ffff7f89f3a <+794>:	mov    DWORD PTR [rbp-0x4],eax
   0x00007ffff7f89f3d <+797>:	jmp    0x7ffff7f8a046 <heap.SmpAllocator.alloc+1062>
   0x00007ffff7f89f42 <+802>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f46 <+806>:	mov    esi,0x10000
   0x00007ffff7f89f4b <+811>:	call   0x7ffff7f18cd0 <mem.Alignment.fromByteUnits>
   0x00007ffff7f89f50 <+816>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f54 <+820>:	movzx  edx,al
   0x00007ffff7f89f57 <+823>:	mov    esi,0x10000
   0x00007ffff7f89f5c <+828>:	call   0x7ffff7f889a0 <heap.PageAllocator.map>
   0x00007ffff7f89f61 <+833>:	mov    QWORD PTR [rbp-0xe0],rax
   0x00007ffff7f89f68 <+840>:	cmp    rax,0x0
   0x00007ffff7f89f6c <+844>:	jne    0x7ffff7f89f9b <heap.SmpAllocator.alloc+891>
   0x00007ffff7f89f6e <+846>:	jmp    0x7ffff7f89fab <heap.SmpAllocator.alloc+907>
   0x00007ffff7f89f70 <+848>:	jmp    0x7ffff7f89ef6 <heap.SmpAllocator.alloc+726>
   0x00007ffff7f89f72 <+850>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89f76 <+854>:	mov    rcx,QWORD PTR [rbp-0xf8]
   0x00007ffff7f89f7d <+861>:	mov    QWORD PTR [rbp-0xf0],rcx
   0x00007ffff7f89f84 <+868>:	mov    QWORD PTR [rbp-0x10],rcx
   0x00007ffff7f89f88 <+872>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89f8c <+876>:	mov    QWORD PTR [rbp-0xe8],rcx
   0x00007ffff7f89f93 <+883>:	cmp    rax,0xd
   0x00007ffff7f89f97 <+887>:	jb     0x7ffff7f89ffb <heap.SmpAllocator.alloc+987>
   0x00007ffff7f89f99 <+889>:	jmp    0x7ffff7f89ffd <heap.SmpAllocator.alloc+989>
   0x00007ffff7f89f9b <+891>:	mov    rax,QWORD PTR [rbp-0xe0]
   0x00007ffff7f89fa2 <+898>:	mov    QWORD PTR [rbp-0xf8],rax
   0x00007ffff7f89fa9 <+905>:	jmp    0x7ffff7f89f72 <heap.SmpAllocator.alloc+850>
   0x00007ffff7f89fab <+907>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89faf <+911>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89fb3 <+915>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89fb8 <+920>:	xor    eax,eax
   0x00007ffff7f89fba <+922>:	add    rsp,0x120
   0x00007ffff7f89fc1 <+929>:	pop    rbp
   0x00007ffff7f89fc2 <+930>:	ret
   0x00007ffff7f89fc3 <+931>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89fca <+938>:	mov    rax,QWORD PTR [rbp-0xf0]
   0x00007ffff7f89fd1 <+945>:	mov    rdx,QWORD PTR [rbp-0xe8]
   0x00007ffff7f89fd8 <+952>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89fdc <+956>:	shl    rsi,0x3
   0x00007ffff7f89fe0 <+960>:	add    rdx,rsi
   0x00007ffff7f89fe3 <+963>:	mov    QWORD PTR [rbp-0x108],rdx
   0x00007ffff7f89fea <+970>:	add    rax,rcx
   0x00007ffff7f89fed <+973>:	mov    QWORD PTR [rbp-0x100],rax
   0x00007ffff7f89ff4 <+980>:	setb   al
   0x00007ffff7f89ff7 <+983>:	jb     0x7ffff7f8a00f <heap.SmpAllocator.alloc+1007>
   0x00007ffff7f89ff9 <+985>:	jmp    0x7ffff7f8a018 <heap.SmpAllocator.alloc+1016>
   0x00007ffff7f89ffb <+987>:	jmp    0x7ffff7f89fc3 <heap.SmpAllocator.alloc+931>
   0x00007ffff7f89ffd <+989>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f8a001 <+993>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a005 <+997>:	mov    edx,0xd
   0x00007ffff7f8a00a <+1002>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f8a00f <+1007>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a013 <+1011>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a018 <+1016>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a01c <+1020>:	mov    rax,QWORD PTR [rbp-0x108]
   0x00007ffff7f8a023 <+1027>:	mov    rcx,QWORD PTR [rbp-0x100]
   0x00007ffff7f8a02a <+1034>:	mov    QWORD PTR [rax],rcx
   0x00007ffff7f8a02d <+1037>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f8a031 <+1041>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f8a036 <+1046>:	mov    rax,QWORD PTR [rbp-0xf0]
   0x00007ffff7f8a03d <+1053>:	add    rsp,0x120
   0x00007ffff7f8a044 <+1060>:	pop    rbp
   0x00007ffff7f8a045 <+1061>:	ret
   0x00007ffff7f8a046 <+1062>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a049 <+1065>:	add    eax,0x1
   0x00007ffff7f8a04c <+1068>:	mov    DWORD PTR [rbp-0x10c],eax
   0x00007ffff7f8a052 <+1074>:	setb   al
   0x00007ffff7f8a055 <+1077>:	jb     0x7ffff7f8a059 <heap.SmpAllocator.alloc+1081>
   0x00007ffff7f8a057 <+1079>:	jmp    0x7ffff7f8a062 <heap.SmpAllocator.alloc+1090>
   0x00007ffff7f8a059 <+1081>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a05d <+1085>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a062 <+1090>:	mov    eax,DWORD PTR [rbp-0xd4]
   0x00007ffff7f8a068 <+1096>:	cmp    eax,0x0
   0x00007ffff7f8a06b <+1099>:	jne    0x7ffff7f8a096 <heap.SmpAllocator.alloc+1142>
   0x00007ffff7f8a06d <+1101>:	jmp    0x7ffff7f8a098 <heap.SmpAllocator.alloc+1144>
   0x00007ffff7f8a06f <+1103>:	mov    ecx,DWORD PTR [rbp-0xd4]
   0x00007ffff7f8a075 <+1109>:	mov    eax,DWORD PTR [rbp-0x10c]
   0x00007ffff7f8a07b <+1115>:	xor    edx,edx
   0x00007ffff7f8a07d <+1117>:	div    ecx
   0x00007ffff7f8a07f <+1119>:	mov    DWORD PTR [rbp-0x4],edx
   0x00007ffff7f8a082 <+1122>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a085 <+1125>:	mov    QWORD PTR [rbp-0x118],rax
   0x00007ffff7f8a08c <+1132>:	cmp    rax,0x80
   0x00007ffff7f8a092 <+1138>:	jb     0x7ffff7f8a0d4 <heap.SmpAllocator.alloc+1204>
   0x00007ffff7f8a094 <+1140>:	jmp    0x7ffff7f8a0d6 <heap.SmpAllocator.alloc+1206>
   0x00007ffff7f8a096 <+1142>:	jmp    0x7ffff7f8a06f <heap.SmpAllocator.alloc+1103>
   0x00007ffff7f8a098 <+1144>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a09c <+1148>:	call   0x7ffff7f10e70 <debug.FullPanic((function 'defaultPanic')).divideByZero>
   0x00007ffff7f8a0a1 <+1153>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a0a5 <+1157>:	mov    rcx,QWORD PTR [rbp-0x118]
   0x00007ffff7f8a0ac <+1164>:	lea    rax,[rip+0x29fcd]        # 0x7ffff7fb4080 <heap.SmpAllocator.global>
   0x00007ffff7f8a0b3 <+1171>:	shl    rcx,0x8
   0x00007ffff7f8a0b7 <+1175>:	add    rax,rcx
   0x00007ffff7f8a0ba <+1178>:	mov    QWORD PTR [rbp-0x30],rax
   0x00007ffff7f8a0be <+1182>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f8a0c2 <+1186>:	add    rsi,0xd0
   0x00007ffff7f8a0c9 <+1193>:	call   0x7ffff7f8a4e0 <Thread.Mutex.tryLock>
   0x00007ffff7f8a0ce <+1198>:	test   al,0x1
   0x00007ffff7f8a0d0 <+1200>:	jne    0x7ffff7f8a0f0 <heap.SmpAllocator.alloc+1232>
   0x00007ffff7f8a0d2 <+1202>:	jmp    0x7ffff7f8a125 <heap.SmpAllocator.alloc+1285>
   0x00007ffff7f8a0d4 <+1204>:	jmp    0x7ffff7f8a0a1 <heap.SmpAllocator.alloc+1153>
   0x00007ffff7f8a0d6 <+1206>:	mov    rsi,QWORD PTR [rbp-0x118]
   0x00007ffff7f8a0dd <+1213>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a0e1 <+1217>:	mov    edx,0x80
   0x00007ffff7f8a0e6 <+1222>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f8a0eb <+1227>:	jmp    0x7ffff7f8a046 <heap.SmpAllocator.alloc+1062>
   0x00007ffff7f8a0f0 <+1232>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a0f3 <+1235>:	mov    DWORD PTR [rbp-0x120],eax
   0x00007ffff7f8a0f9 <+1241>:	lea    rdi,[rip+0x27a20]        # 0x7ffff7fb1b20
   0x00007ffff7f8a100 <+1248>:	call   0x7ffff7fae630 <__tls_get_addr@plt>
   0x00007ffff7f8a105 <+1253>:	mov    ecx,DWORD PTR [rbp-0x120]
   0x00007ffff7f8a10b <+1259>:	mov    DWORD PTR [rax+0x10],ecx
   0x00007ffff7f8a111 <+1265>:	mov    al,BYTE PTR [rbp-0x31]
   0x00007ffff7f8a114 <+1268>:	add    al,0x1
   0x00007ffff7f8a116 <+1270>:	mov    BYTE PTR [rbp-0x119],al
   0x00007ffff7f8a11c <+1276>:	setb   al
   0x00007ffff7f8a11f <+1279>:	test   al,0x1
   0x00007ffff7f8a121 <+1281>:	jne    0x7ffff7f8a127 <heap.SmpAllocator.alloc+1287>
   0x00007ffff7f8a123 <+1283>:	jmp    0x7ffff7f8a130 <heap.SmpAllocator.alloc+1296>
   0x00007ffff7f8a125 <+1285>:	jmp    0x7ffff7f8a0eb <heap.SmpAllocator.alloc+1227>
   0x00007ffff7f8a127 <+1287>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a12b <+1291>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a130 <+1296>:	mov    al,BYTE PTR [rbp-0x119]
   0x00007ffff7f8a136 <+1302>:	mov    BYTE PTR [rbp-0x31],al
   0x00007ffff7f8a139 <+1305>:	jmp    0x7ffff7f89d0f <heap.SmpAllocator.alloc+239>
End of assembler dump.
warning: Currently logging to gdb.c.  Turn the logging off and on to make the new setting effective.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[New Thread 0x7ffff78bf6c0 (LWP 2898)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff78bf6c0 (LWP 2898)]
0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Breakpoint 1 at 0x7ffff7f8a3ae: file /usr/lib/zig/std/heap/SmpAllocator.zig, line 89.
Breakpoint 2 at 0x7ffff7f8a0f0: file /usr/lib/zig/std/heap/SmpAllocator.zig, line 168.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".

Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=1032, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$1 = 1

Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=32, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$2 = 2
[New Thread 0x7ffff78bf6c0 (LWP 2900)]
[Switching to Thread 0x7ffff78bf6c0 (LWP 2900)]

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=21, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$3 = 1

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=107, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$4 = 2

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=14, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$5 = 3

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=37, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$6 = 4

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=14, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$7 = 5

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=20, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$8 = 6

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=16, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$9 = 7

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=23, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$10 = 8

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=15, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$11 = 9

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=96, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$12 = 10

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=15, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$13 = 11

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=199, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$14 = 0

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=15, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$15 = 1

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=55, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$16 = 2

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
warning: Currently logging to gdb.c.  Turn the logging off and on to make the new setting effective.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[New Thread 0x7ffff78bf6c0 (LWP 2947)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff78bf6c0 (LWP 2947)]
0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Breakpoint 1 at 0x7ffff7f8a3ae: file /usr/lib/zig/std/heap/SmpAllocator.zig, line 89.
Breakpoint 2 at 0x7ffff7f8a0f0: file /usr/lib/zig/std/heap/SmpAllocator.zig, line 168.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".

Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=1032, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$1 = 1

Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=32, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$2 = 2
[New Thread 0x7ffff78bf6c0 (LWP 2949)]
[Switching to Thread 0x7ffff78bf6c0 (LWP 2949)]

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=21, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$3 = 1

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=107, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$4 = 2

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=14, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$5 = 3

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=37, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$6 = 4

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=14, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$7 = 5

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=20, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$8 = 6

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=16, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$9 = 7

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=23, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$10 = 8

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=15, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$11 = 9

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=96, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$12 = 10

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=15, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$13 = 11

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=199, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$14 = 0

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=15, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$15 = 1

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=55, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$16 = 2

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
warning: Currently logging to gdb.c.  Turn the logging off and on to make the new setting effective.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[New Thread 0x7ffff78bf6c0 (LWP 3003)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff78bf6c0 (LWP 3003)]
0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Breakpoint 1 at 0x7ffff7f8a3ae: file /usr/lib/zig/std/heap/SmpAllocator.zig, line 89.
Breakpoint 2 at 0x7ffff7f8a0f0: file /usr/lib/zig/std/heap/SmpAllocator.zig, line 168.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".

Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=1032, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$1 = 1
Dump of assembler code for function heap.SmpAllocator.alloc:
   0x00007ffff7f89c20 <+0>:	push   rbp
   0x00007ffff7f89c21 <+1>:	mov    rbp,rsp
   0x00007ffff7f89c24 <+4>:	sub    rsp,0x120
   0x00007ffff7f89c2b <+11>:	mov    eax,ecx
   0x00007ffff7f89c2d <+13>:	mov    QWORD PTR [rbp-0x88],rdx
   0x00007ffff7f89c34 <+20>:	mov    rcx,rsi
   0x00007ffff7f89c37 <+23>:	mov    rsi,QWORD PTR [rbp-0x88]
   0x00007ffff7f89c3e <+30>:	mov    QWORD PTR [rbp-0x80],rdi
   0x00007ffff7f89c42 <+34>:	mov    BYTE PTR [rbp-0x71],al
   0x00007ffff7f89c45 <+37>:	mov    QWORD PTR [rbp-0x68],rcx
   0x00007ffff7f89c49 <+41>:	mov    QWORD PTR [rbp-0x60],rsi
   0x00007ffff7f89c4d <+45>:	mov    cl,al
   0x00007ffff7f89c4f <+47>:	and    cl,0x3f
   0x00007ffff7f89c52 <+50>:	mov    BYTE PTR [rbp-0x51],cl
   0x00007ffff7f89c55 <+53>:	mov    QWORD PTR [rbp-0x50],r8
   0x00007ffff7f89c59 <+57>:	movzx  edx,al
   0x00007ffff7f89c5c <+60>:	call   0x7ffff7f8a140 <heap.SmpAllocator.sizeClassIndex>
   0x00007ffff7f89c61 <+65>:	mov    QWORD PTR [rbp-0x70],rax
   0x00007ffff7f89c65 <+69>:	mov    QWORD PTR [rbp-0x48],rax
   0x00007ffff7f89c69 <+73>:	cmp    rax,0xd
   0x00007ffff7f89c6d <+77>:	jae    0x7ffff7f89c91 <heap.SmpAllocator.alloc+113>
   0x00007ffff7f89c6f <+79>:	jmp    0x7ffff7f89cb0 <heap.SmpAllocator.alloc+144>
   0x00007ffff7f89c71 <+81>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89c75 <+85>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89c79 <+89>:	call   0x7ffff7f8a200 <heap.SmpAllocator.slotSize>
   0x00007ffff7f89c7e <+94>:	mov    QWORD PTR [rbp-0x90],rax
   0x00007ffff7f89c85 <+101>:	mov    QWORD PTR [rbp-0x40],rax
   0x00007ffff7f89c89 <+105>:	cmp    rax,0x0
   0x00007ffff7f89c8d <+109>:	jne    0x7ffff7f89ce9 <heap.SmpAllocator.alloc+201>
   0x00007ffff7f89c8f <+111>:	jmp    0x7ffff7f89ceb <heap.SmpAllocator.alloc+203>
   0x00007ffff7f89c91 <+113>:	mov    rsi,QWORD PTR [rbp-0x88]
   0x00007ffff7f89c98 <+120>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89c9c <+124>:	mov    al,BYTE PTR [rbp-0x71]
   0x00007ffff7f89c9f <+127>:	movzx  edx,al
   0x00007ffff7f89ca2 <+130>:	call   0x7ffff7f889a0 <heap.PageAllocator.map>
   0x00007ffff7f89ca7 <+135>:	add    rsp,0x120
   0x00007ffff7f89cae <+142>:	pop    rbp
   0x00007ffff7f89caf <+143>:	ret
   0x00007ffff7f89cb0 <+144>:	jmp    0x7ffff7f89c71 <heap.SmpAllocator.alloc+81>
   0x00007ffff7f89cb2 <+146>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cb6 <+150>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89cbd <+157>:	mov    eax,0x10000
   0x00007ffff7f89cc2 <+162>:	xor    edx,edx
   0x00007ffff7f89cc4 <+164>:	div    rcx
   0x00007ffff7f89cc7 <+167>:	cmp    rdx,0x0
   0x00007ffff7f89ccb <+171>:	sete   al
   0x00007ffff7f89cce <+174>:	movzx  esi,al
   0x00007ffff7f89cd1 <+177>:	call   0x7ffff7ef2790 <debug.assert>
   0x00007ffff7f89cd6 <+182>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cda <+186>:	mov    BYTE PTR [rbp-0x31],0x0
   0x00007ffff7f89cde <+190>:	call   0x7ffff7f8a260 <heap.SmpAllocator.Thread.lock>
   0x00007ffff7f89ce3 <+195>:	mov    QWORD PTR [rbp-0x30],rax
   0x00007ffff7f89ce7 <+199>:	jmp    0x7ffff7f89cf4 <heap.SmpAllocator.alloc+212>
   0x00007ffff7f89ce9 <+201>:	jmp    0x7ffff7f89cb2 <heap.SmpAllocator.alloc+146>
   0x00007ffff7f89ceb <+203>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cef <+207>:	call   0x7ffff7f10e70 <debug.FullPanic((function 'defaultPanic')).divideByZero>
   0x00007ffff7f89cf4 <+212>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89cf8 <+216>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89cfc <+220>:	add    rcx,0x68
   0x00007ffff7f89d00 <+224>:	mov    QWORD PTR [rbp-0x98],rcx
   0x00007ffff7f89d07 <+231>:	cmp    rax,0xd
   0x00007ffff7f89d0b <+235>:	jb     0x7ffff7f89d33 <heap.SmpAllocator.alloc+275>
   0x00007ffff7f89d0d <+237>:	jmp    0x7ffff7f89d35 <heap.SmpAllocator.alloc+277>
   0x00007ffff7f89d0f <+239>:	jmp    0x7ffff7f89cf4 <heap.SmpAllocator.alloc+212>
   0x00007ffff7f89d11 <+241>:	mov    rax,QWORD PTR [rbp-0x98]
   0x00007ffff7f89d18 <+248>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d1c <+252>:	mov    rax,QWORD PTR [rax+rcx*8]
   0x00007ffff7f89d20 <+256>:	mov    QWORD PTR [rbp-0xa0],rax
   0x00007ffff7f89d27 <+263>:	mov    QWORD PTR [rbp-0x28],rax
   0x00007ffff7f89d2b <+267>:	cmp    rax,0x0
   0x00007ffff7f89d2f <+271>:	jne    0x7ffff7f89d65 <heap.SmpAllocator.alloc+325>
   0x00007ffff7f89d31 <+273>:	jmp    0x7ffff7f89d74 <heap.SmpAllocator.alloc+340>
   0x00007ffff7f89d33 <+275>:	jmp    0x7ffff7f89d11 <heap.SmpAllocator.alloc+241>
   0x00007ffff7f89d35 <+277>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d39 <+281>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89d3d <+285>:	mov    edx,0xd
   0x00007ffff7f89d42 <+290>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89d47 <+295>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d4b <+299>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89d4f <+303>:	mov    QWORD PTR [rbp-0xa8],rcx
   0x00007ffff7f89d56 <+310>:	cmp    rax,0xd
   0x00007ffff7f89d5a <+314>:	jb     0x7ffff7f89e37 <heap.SmpAllocator.alloc+535>
   0x00007ffff7f89d60 <+320>:	jmp    0x7ffff7f89e39 <heap.SmpAllocator.alloc+537>
   0x00007ffff7f89d65 <+325>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d6c <+332>:	cmp    rax,0x0
   0x00007ffff7f89d70 <+336>:	jne    0x7ffff7f89d89 <heap.SmpAllocator.alloc+361>
   0x00007ffff7f89d72 <+338>:	jmp    0x7ffff7f89d8b <heap.SmpAllocator.alloc+363>
   0x00007ffff7f89d74 <+340>:	jmp    0x7ffff7f89d47 <heap.SmpAllocator.alloc+295>
   0x00007ffff7f89d76 <+342>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d7d <+349>:	and    rax,0x7
   0x00007ffff7f89d81 <+353>:	cmp    rax,0x0
   0x00007ffff7f89d85 <+357>:	je     0x7ffff7f89dba <heap.SmpAllocator.alloc+410>
   0x00007ffff7f89d87 <+359>:	jmp    0x7ffff7f89dbc <heap.SmpAllocator.alloc+412>
   0x00007ffff7f89d89 <+361>:	jmp    0x7ffff7f89d76 <heap.SmpAllocator.alloc+342>
   0x00007ffff7f89d8b <+363>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89d8f <+367>:	call   0x7ffff7efa8d0 <debug.FullPanic((function 'defaultPanic')).castToNull>
   0x00007ffff7f89d94 <+372>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d98 <+376>:	mov    rcx,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d9f <+383>:	mov    QWORD PTR [rbp-0x20],rcx
   0x00007ffff7f89da3 <+387>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89da7 <+391>:	add    rcx,0x68
   0x00007ffff7f89dab <+395>:	mov    QWORD PTR [rbp-0xb0],rcx
   0x00007ffff7f89db2 <+402>:	cmp    rax,0xd
   0x00007ffff7f89db6 <+406>:	jb     0x7ffff7f89dfb <heap.SmpAllocator.alloc+475>
   0x00007ffff7f89db8 <+408>:	jmp    0x7ffff7f89dfd <heap.SmpAllocator.alloc+477>
   0x00007ffff7f89dba <+410>:	jmp    0x7ffff7f89d94 <heap.SmpAllocator.alloc+372>
   0x00007ffff7f89dbc <+412>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89dc0 <+416>:	call   0x7ffff7ef5d30 <debug.FullPanic((function 'defaultPanic')).incorrectAlignment>
   0x00007ffff7f89dc5 <+421>:	mov    rdx,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89dcc <+428>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89dd0 <+432>:	mov    rax,QWORD PTR [rbp-0xb0]
   0x00007ffff7f89dd7 <+439>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89ddb <+443>:	mov    rdx,QWORD PTR [rdx]
   0x00007ffff7f89dde <+446>:	mov    QWORD PTR [rax+rcx*8],rdx
   0x00007ffff7f89de2 <+450>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89de6 <+454>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89deb <+459>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89df2 <+466>:	add    rsp,0x120
   0x00007ffff7f89df9 <+473>:	pop    rbp
   0x00007ffff7f89dfa <+474>:	ret
   0x00007ffff7f89dfb <+475>:	jmp    0x7ffff7f89dc5 <heap.SmpAllocator.alloc+421>
   0x00007ffff7f89dfd <+477>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e01 <+481>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89e05 <+485>:	mov    edx,0xd
   0x00007ffff7f89e0a <+490>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89e0f <+495>:	mov    rax,QWORD PTR [rbp-0xa8]
   0x00007ffff7f89e16 <+502>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e1a <+506>:	mov    rax,QWORD PTR [rax+rcx*8]
   0x00007ffff7f89e1e <+510>:	mov    QWORD PTR [rbp-0xb8],rax
   0x00007ffff7f89e25 <+517>:	mov    QWORD PTR [rbp-0x18],rax
   0x00007ffff7f89e29 <+521>:	and    rax,0xffff
   0x00007ffff7f89e2f <+527>:	cmp    rax,0x0
   0x00007ffff7f89e33 <+531>:	jne    0x7ffff7f89e5a <heap.SmpAllocator.alloc+570>
   0x00007ffff7f89e35 <+533>:	jmp    0x7ffff7f89e71 <heap.SmpAllocator.alloc+593>
   0x00007ffff7f89e37 <+535>:	jmp    0x7ffff7f89e0f <heap.SmpAllocator.alloc+495>
   0x00007ffff7f89e39 <+537>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e3d <+541>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89e41 <+545>:	mov    edx,0xd
   0x00007ffff7f89e46 <+550>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89e4b <+555>:	cmp    BYTE PTR [rbp-0x31],0x1
   0x00007ffff7f89e4f <+559>:	jae    0x7ffff7f89f42 <heap.SmpAllocator.alloc+802>
   0x00007ffff7f89e55 <+565>:	jmp    0x7ffff7f89f70 <heap.SmpAllocator.alloc+848>
   0x00007ffff7f89e5a <+570>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e5e <+574>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89e62 <+578>:	mov    QWORD PTR [rbp-0xc0],rcx
   0x00007ffff7f89e69 <+585>:	cmp    rax,0xd
   0x00007ffff7f89e6d <+589>:	jb     0x7ffff7f89eab <heap.SmpAllocator.alloc+651>
   0x00007ffff7f89e6f <+591>:	jmp    0x7ffff7f89ead <heap.SmpAllocator.alloc+653>
   0x00007ffff7f89e71 <+593>:	jmp    0x7ffff7f89e4b <heap.SmpAllocator.alloc+555>
   0x00007ffff7f89e73 <+595>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89e7a <+602>:	mov    rax,QWORD PTR [rbp-0xb8]
   0x00007ffff7f89e81 <+609>:	mov    rdx,QWORD PTR [rbp-0xc0]
   0x00007ffff7f89e88 <+616>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e8c <+620>:	shl    rsi,0x3
   0x00007ffff7f89e90 <+624>:	add    rdx,rsi
   0x00007ffff7f89e93 <+627>:	mov    QWORD PTR [rbp-0xd0],rdx
   0x00007ffff7f89e9a <+634>:	add    rax,rcx
   0x00007ffff7f89e9d <+637>:	mov    QWORD PTR [rbp-0xc8],rax
   0x00007ffff7f89ea4 <+644>:	setb   al
   0x00007ffff7f89ea7 <+647>:	jb     0x7ffff7f89ebf <heap.SmpAllocator.alloc+671>
   0x00007ffff7f89ea9 <+649>:	jmp    0x7ffff7f89ec8 <heap.SmpAllocator.alloc+680>
   0x00007ffff7f89eab <+651>:	jmp    0x7ffff7f89e73 <heap.SmpAllocator.alloc+595>
   0x00007ffff7f89ead <+653>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89eb1 <+657>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89eb5 <+661>:	mov    edx,0xd
   0x00007ffff7f89eba <+666>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89ebf <+671>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89ec3 <+675>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f89ec8 <+680>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89ecc <+684>:	mov    rax,QWORD PTR [rbp-0xd0]
   0x00007ffff7f89ed3 <+691>:	mov    rcx,QWORD PTR [rbp-0xc8]
   0x00007ffff7f89eda <+698>:	mov    QWORD PTR [rax],rcx
   0x00007ffff7f89edd <+701>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89ee1 <+705>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89ee6 <+710>:	mov    rax,QWORD PTR [rbp-0xb8]
   0x00007ffff7f89eed <+717>:	add    rsp,0x120
   0x00007ffff7f89ef4 <+724>:	pop    rbp
   0x00007ffff7f89ef5 <+725>:	ret
   0x00007ffff7f89ef6 <+726>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89efa <+730>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89efe <+734>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89f03 <+739>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f07 <+743>:	call   0x7ffff7f8a410 <heap.SmpAllocator.getCpuCount>
   0x00007ffff7f89f0c <+748>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f10 <+752>:	mov    ecx,eax
   0x00007ffff7f89f12 <+754>:	mov    DWORD PTR [rbp-0xd4],ecx
   0x00007ffff7f89f18 <+760>:	mov    DWORD PTR [rbp-0x8],eax
   0x00007ffff7f89f1b <+763>:	test   eax,eax
   0x00007ffff7f89f1d <+765>:	setne  al
   0x00007ffff7f89f20 <+768>:	movzx  esi,al
   0x00007ffff7f89f23 <+771>:	call   0x7ffff7ef2790 <debug.assert>
   0x00007ffff7f89f28 <+776>:	lea    rdi,[rip+0x27bf1]        # 0x7ffff7fb1b20
   0x00007ffff7f89f2f <+783>:	call   0x7ffff7fae630 <__tls_get_addr@plt>
   0x00007ffff7f89f34 <+788>:	mov    eax,DWORD PTR [rax+0x10]
   0x00007ffff7f89f3a <+794>:	mov    DWORD PTR [rbp-0x4],eax
   0x00007ffff7f89f3d <+797>:	jmp    0x7ffff7f8a046 <heap.SmpAllocator.alloc+1062>
   0x00007ffff7f89f42 <+802>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f46 <+806>:	mov    esi,0x10000
   0x00007ffff7f89f4b <+811>:	call   0x7ffff7f18cd0 <mem.Alignment.fromByteUnits>
   0x00007ffff7f89f50 <+816>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f54 <+820>:	movzx  edx,al
   0x00007ffff7f89f57 <+823>:	mov    esi,0x10000
   0x00007ffff7f89f5c <+828>:	call   0x7ffff7f889a0 <heap.PageAllocator.map>
   0x00007ffff7f89f61 <+833>:	mov    QWORD PTR [rbp-0xe0],rax
   0x00007ffff7f89f68 <+840>:	cmp    rax,0x0
   0x00007ffff7f89f6c <+844>:	jne    0x7ffff7f89f9b <heap.SmpAllocator.alloc+891>
   0x00007ffff7f89f6e <+846>:	jmp    0x7ffff7f89fab <heap.SmpAllocator.alloc+907>
   0x00007ffff7f89f70 <+848>:	jmp    0x7ffff7f89ef6 <heap.SmpAllocator.alloc+726>
   0x00007ffff7f89f72 <+850>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89f76 <+854>:	mov    rcx,QWORD PTR [rbp-0xf8]
   0x00007ffff7f89f7d <+861>:	mov    QWORD PTR [rbp-0xf0],rcx
   0x00007ffff7f89f84 <+868>:	mov    QWORD PTR [rbp-0x10],rcx
   0x00007ffff7f89f88 <+872>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89f8c <+876>:	mov    QWORD PTR [rbp-0xe8],rcx
   0x00007ffff7f89f93 <+883>:	cmp    rax,0xd
   0x00007ffff7f89f97 <+887>:	jb     0x7ffff7f89ffb <heap.SmpAllocator.alloc+987>
   0x00007ffff7f89f99 <+889>:	jmp    0x7ffff7f89ffd <heap.SmpAllocator.alloc+989>
   0x00007ffff7f89f9b <+891>:	mov    rax,QWORD PTR [rbp-0xe0]
   0x00007ffff7f89fa2 <+898>:	mov    QWORD PTR [rbp-0xf8],rax
   0x00007ffff7f89fa9 <+905>:	jmp    0x7ffff7f89f72 <heap.SmpAllocator.alloc+850>
   0x00007ffff7f89fab <+907>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89faf <+911>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89fb3 <+915>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89fb8 <+920>:	xor    eax,eax
   0x00007ffff7f89fba <+922>:	add    rsp,0x120
   0x00007ffff7f89fc1 <+929>:	pop    rbp
   0x00007ffff7f89fc2 <+930>:	ret
   0x00007ffff7f89fc3 <+931>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89fca <+938>:	mov    rax,QWORD PTR [rbp-0xf0]
   0x00007ffff7f89fd1 <+945>:	mov    rdx,QWORD PTR [rbp-0xe8]
   0x00007ffff7f89fd8 <+952>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89fdc <+956>:	shl    rsi,0x3
   0x00007ffff7f89fe0 <+960>:	add    rdx,rsi
   0x00007ffff7f89fe3 <+963>:	mov    QWORD PTR [rbp-0x108],rdx
   0x00007ffff7f89fea <+970>:	add    rax,rcx
   0x00007ffff7f89fed <+973>:	mov    QWORD PTR [rbp-0x100],rax
   0x00007ffff7f89ff4 <+980>:	setb   al
   0x00007ffff7f89ff7 <+983>:	jb     0x7ffff7f8a00f <heap.SmpAllocator.alloc+1007>
   0x00007ffff7f89ff9 <+985>:	jmp    0x7ffff7f8a018 <heap.SmpAllocator.alloc+1016>
   0x00007ffff7f89ffb <+987>:	jmp    0x7ffff7f89fc3 <heap.SmpAllocator.alloc+931>
   0x00007ffff7f89ffd <+989>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f8a001 <+993>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a005 <+997>:	mov    edx,0xd
   0x00007ffff7f8a00a <+1002>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f8a00f <+1007>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a013 <+1011>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a018 <+1016>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a01c <+1020>:	mov    rax,QWORD PTR [rbp-0x108]
   0x00007ffff7f8a023 <+1027>:	mov    rcx,QWORD PTR [rbp-0x100]
   0x00007ffff7f8a02a <+1034>:	mov    QWORD PTR [rax],rcx
   0x00007ffff7f8a02d <+1037>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f8a031 <+1041>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f8a036 <+1046>:	mov    rax,QWORD PTR [rbp-0xf0]
   0x00007ffff7f8a03d <+1053>:	add    rsp,0x120
   0x00007ffff7f8a044 <+1060>:	pop    rbp
   0x00007ffff7f8a045 <+1061>:	ret
   0x00007ffff7f8a046 <+1062>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a049 <+1065>:	add    eax,0x1
   0x00007ffff7f8a04c <+1068>:	mov    DWORD PTR [rbp-0x10c],eax
   0x00007ffff7f8a052 <+1074>:	setb   al
   0x00007ffff7f8a055 <+1077>:	jb     0x7ffff7f8a059 <heap.SmpAllocator.alloc+1081>
   0x00007ffff7f8a057 <+1079>:	jmp    0x7ffff7f8a062 <heap.SmpAllocator.alloc+1090>
   0x00007ffff7f8a059 <+1081>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a05d <+1085>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a062 <+1090>:	mov    eax,DWORD PTR [rbp-0xd4]
   0x00007ffff7f8a068 <+1096>:	cmp    eax,0x0
   0x00007ffff7f8a06b <+1099>:	jne    0x7ffff7f8a096 <heap.SmpAllocator.alloc+1142>
   0x00007ffff7f8a06d <+1101>:	jmp    0x7ffff7f8a098 <heap.SmpAllocator.alloc+1144>
   0x00007ffff7f8a06f <+1103>:	mov    ecx,DWORD PTR [rbp-0xd4]
   0x00007ffff7f8a075 <+1109>:	mov    eax,DWORD PTR [rbp-0x10c]
   0x00007ffff7f8a07b <+1115>:	xor    edx,edx
   0x00007ffff7f8a07d <+1117>:	div    ecx
   0x00007ffff7f8a07f <+1119>:	mov    DWORD PTR [rbp-0x4],edx
   0x00007ffff7f8a082 <+1122>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a085 <+1125>:	mov    QWORD PTR [rbp-0x118],rax
   0x00007ffff7f8a08c <+1132>:	cmp    rax,0x80
   0x00007ffff7f8a092 <+1138>:	jb     0x7ffff7f8a0d4 <heap.SmpAllocator.alloc+1204>
   0x00007ffff7f8a094 <+1140>:	jmp    0x7ffff7f8a0d6 <heap.SmpAllocator.alloc+1206>
   0x00007ffff7f8a096 <+1142>:	jmp    0x7ffff7f8a06f <heap.SmpAllocator.alloc+1103>
   0x00007ffff7f8a098 <+1144>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a09c <+1148>:	call   0x7ffff7f10e70 <debug.FullPanic((function 'defaultPanic')).divideByZero>
   0x00007ffff7f8a0a1 <+1153>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a0a5 <+1157>:	mov    rcx,QWORD PTR [rbp-0x118]
   0x00007ffff7f8a0ac <+1164>:	lea    rax,[rip+0x29fcd]        # 0x7ffff7fb4080 <heap.SmpAllocator.global>
   0x00007ffff7f8a0b3 <+1171>:	shl    rcx,0x8
   0x00007ffff7f8a0b7 <+1175>:	add    rax,rcx
   0x00007ffff7f8a0ba <+1178>:	mov    QWORD PTR [rbp-0x30],rax
   0x00007ffff7f8a0be <+1182>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f8a0c2 <+1186>:	add    rsi,0xd0
   0x00007ffff7f8a0c9 <+1193>:	call   0x7ffff7f8a4e0 <Thread.Mutex.tryLock>
   0x00007ffff7f8a0ce <+1198>:	test   al,0x1
   0x00007ffff7f8a0d0 <+1200>:	jne    0x7ffff7f8a0f0 <heap.SmpAllocator.alloc+1232>
   0x00007ffff7f8a0d2 <+1202>:	jmp    0x7ffff7f8a125 <heap.SmpAllocator.alloc+1285>
   0x00007ffff7f8a0d4 <+1204>:	jmp    0x7ffff7f8a0a1 <heap.SmpAllocator.alloc+1153>
   0x00007ffff7f8a0d6 <+1206>:	mov    rsi,QWORD PTR [rbp-0x118]
   0x00007ffff7f8a0dd <+1213>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a0e1 <+1217>:	mov    edx,0x80
   0x00007ffff7f8a0e6 <+1222>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f8a0eb <+1227>:	jmp    0x7ffff7f8a046 <heap.SmpAllocator.alloc+1062>
=> 0x00007ffff7f8a0f0 <+1232>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a0f3 <+1235>:	mov    DWORD PTR [rbp-0x120],eax
   0x00007ffff7f8a0f9 <+1241>:	lea    rdi,[rip+0x27a20]        # 0x7ffff7fb1b20
   0x00007ffff7f8a100 <+1248>:	call   0x7ffff7fae630 <__tls_get_addr@plt>
   0x00007ffff7f8a105 <+1253>:	mov    ecx,DWORD PTR [rbp-0x120]
   0x00007ffff7f8a10b <+1259>:	mov    DWORD PTR [rax+0x10],ecx
   0x00007ffff7f8a111 <+1265>:	mov    al,BYTE PTR [rbp-0x31]
   0x00007ffff7f8a114 <+1268>:	add    al,0x1
   0x00007ffff7f8a116 <+1270>:	mov    BYTE PTR [rbp-0x119],al
   0x00007ffff7f8a11c <+1276>:	setb   al
   0x00007ffff7f8a11f <+1279>:	test   al,0x1
   0x00007ffff7f8a121 <+1281>:	jne    0x7ffff7f8a127 <heap.SmpAllocator.alloc+1287>
   0x00007ffff7f8a123 <+1283>:	jmp    0x7ffff7f8a130 <heap.SmpAllocator.alloc+1296>
   0x00007ffff7f8a125 <+1285>:	jmp    0x7ffff7f8a0eb <heap.SmpAllocator.alloc+1227>
   0x00007ffff7f8a127 <+1287>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a12b <+1291>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a130 <+1296>:	mov    al,BYTE PTR [rbp-0x119]
   0x00007ffff7f8a136 <+1302>:	mov    BYTE PTR [rbp-0x31],al
   0x00007ffff7f8a139 <+1305>:	jmp    0x7ffff7f89d0f <heap.SmpAllocator.alloc+239>
End of assembler dump.
0x00007ffff7f8a0f3	168	                thread_index = index;
0x00007ffff7f8a0f9	168	                thread_index = index;
0x00007ffff7f8a100	168	                thread_index = index;
0x00007ffff7f8a105	168	                thread_index = index;
0x00007ffff7f8a10b	168	                thread_index = index;
Dump of assembler code for function heap.SmpAllocator.alloc:
   0x00007ffff7f89c20 <+0>:	push   rbp
   0x00007ffff7f89c21 <+1>:	mov    rbp,rsp
   0x00007ffff7f89c24 <+4>:	sub    rsp,0x120
   0x00007ffff7f89c2b <+11>:	mov    eax,ecx
   0x00007ffff7f89c2d <+13>:	mov    QWORD PTR [rbp-0x88],rdx
   0x00007ffff7f89c34 <+20>:	mov    rcx,rsi
   0x00007ffff7f89c37 <+23>:	mov    rsi,QWORD PTR [rbp-0x88]
   0x00007ffff7f89c3e <+30>:	mov    QWORD PTR [rbp-0x80],rdi
   0x00007ffff7f89c42 <+34>:	mov    BYTE PTR [rbp-0x71],al
   0x00007ffff7f89c45 <+37>:	mov    QWORD PTR [rbp-0x68],rcx
   0x00007ffff7f89c49 <+41>:	mov    QWORD PTR [rbp-0x60],rsi
   0x00007ffff7f89c4d <+45>:	mov    cl,al
   0x00007ffff7f89c4f <+47>:	and    cl,0x3f
   0x00007ffff7f89c52 <+50>:	mov    BYTE PTR [rbp-0x51],cl
   0x00007ffff7f89c55 <+53>:	mov    QWORD PTR [rbp-0x50],r8
   0x00007ffff7f89c59 <+57>:	movzx  edx,al
   0x00007ffff7f89c5c <+60>:	call   0x7ffff7f8a140 <heap.SmpAllocator.sizeClassIndex>
   0x00007ffff7f89c61 <+65>:	mov    QWORD PTR [rbp-0x70],rax
   0x00007ffff7f89c65 <+69>:	mov    QWORD PTR [rbp-0x48],rax
   0x00007ffff7f89c69 <+73>:	cmp    rax,0xd
   0x00007ffff7f89c6d <+77>:	jae    0x7ffff7f89c91 <heap.SmpAllocator.alloc+113>
   0x00007ffff7f89c6f <+79>:	jmp    0x7ffff7f89cb0 <heap.SmpAllocator.alloc+144>
   0x00007ffff7f89c71 <+81>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89c75 <+85>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89c79 <+89>:	call   0x7ffff7f8a200 <heap.SmpAllocator.slotSize>
   0x00007ffff7f89c7e <+94>:	mov    QWORD PTR [rbp-0x90],rax
   0x00007ffff7f89c85 <+101>:	mov    QWORD PTR [rbp-0x40],rax
   0x00007ffff7f89c89 <+105>:	cmp    rax,0x0
   0x00007ffff7f89c8d <+109>:	jne    0x7ffff7f89ce9 <heap.SmpAllocator.alloc+201>
   0x00007ffff7f89c8f <+111>:	jmp    0x7ffff7f89ceb <heap.SmpAllocator.alloc+203>
   0x00007ffff7f89c91 <+113>:	mov    rsi,QWORD PTR [rbp-0x88]
   0x00007ffff7f89c98 <+120>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89c9c <+124>:	mov    al,BYTE PTR [rbp-0x71]
   0x00007ffff7f89c9f <+127>:	movzx  edx,al
   0x00007ffff7f89ca2 <+130>:	call   0x7ffff7f889a0 <heap.PageAllocator.map>
   0x00007ffff7f89ca7 <+135>:	add    rsp,0x120
   0x00007ffff7f89cae <+142>:	pop    rbp
   0x00007ffff7f89caf <+143>:	ret
   0x00007ffff7f89cb0 <+144>:	jmp    0x7ffff7f89c71 <heap.SmpAllocator.alloc+81>
   0x00007ffff7f89cb2 <+146>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cb6 <+150>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89cbd <+157>:	mov    eax,0x10000
   0x00007ffff7f89cc2 <+162>:	xor    edx,edx
   0x00007ffff7f89cc4 <+164>:	div    rcx
   0x00007ffff7f89cc7 <+167>:	cmp    rdx,0x0
   0x00007ffff7f89ccb <+171>:	sete   al
   0x00007ffff7f89cce <+174>:	movzx  esi,al
   0x00007ffff7f89cd1 <+177>:	call   0x7ffff7ef2790 <debug.assert>
   0x00007ffff7f89cd6 <+182>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cda <+186>:	mov    BYTE PTR [rbp-0x31],0x0
   0x00007ffff7f89cde <+190>:	call   0x7ffff7f8a260 <heap.SmpAllocator.Thread.lock>
   0x00007ffff7f89ce3 <+195>:	mov    QWORD PTR [rbp-0x30],rax
   0x00007ffff7f89ce7 <+199>:	jmp    0x7ffff7f89cf4 <heap.SmpAllocator.alloc+212>
   0x00007ffff7f89ce9 <+201>:	jmp    0x7ffff7f89cb2 <heap.SmpAllocator.alloc+146>
   0x00007ffff7f89ceb <+203>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cef <+207>:	call   0x7ffff7f10e70 <debug.FullPanic((function 'defaultPanic')).divideByZero>
   0x00007ffff7f89cf4 <+212>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89cf8 <+216>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89cfc <+220>:	add    rcx,0x68
   0x00007ffff7f89d00 <+224>:	mov    QWORD PTR [rbp-0x98],rcx
   0x00007ffff7f89d07 <+231>:	cmp    rax,0xd
   0x00007ffff7f89d0b <+235>:	jb     0x7ffff7f89d33 <heap.SmpAllocator.alloc+275>
   0x00007ffff7f89d0d <+237>:	jmp    0x7ffff7f89d35 <heap.SmpAllocator.alloc+277>
   0x00007ffff7f89d0f <+239>:	jmp    0x7ffff7f89cf4 <heap.SmpAllocator.alloc+212>
   0x00007ffff7f89d11 <+241>:	mov    rax,QWORD PTR [rbp-0x98]
   0x00007ffff7f89d18 <+248>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d1c <+252>:	mov    rax,QWORD PTR [rax+rcx*8]
   0x00007ffff7f89d20 <+256>:	mov    QWORD PTR [rbp-0xa0],rax
   0x00007ffff7f89d27 <+263>:	mov    QWORD PTR [rbp-0x28],rax
   0x00007ffff7f89d2b <+267>:	cmp    rax,0x0
   0x00007ffff7f89d2f <+271>:	jne    0x7ffff7f89d65 <heap.SmpAllocator.alloc+325>
   0x00007ffff7f89d31 <+273>:	jmp    0x7ffff7f89d74 <heap.SmpAllocator.alloc+340>
   0x00007ffff7f89d33 <+275>:	jmp    0x7ffff7f89d11 <heap.SmpAllocator.alloc+241>
   0x00007ffff7f89d35 <+277>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d39 <+281>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89d3d <+285>:	mov    edx,0xd
   0x00007ffff7f89d42 <+290>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89d47 <+295>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d4b <+299>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89d4f <+303>:	mov    QWORD PTR [rbp-0xa8],rcx
   0x00007ffff7f89d56 <+310>:	cmp    rax,0xd
   0x00007ffff7f89d5a <+314>:	jb     0x7ffff7f89e37 <heap.SmpAllocator.alloc+535>
   0x00007ffff7f89d60 <+320>:	jmp    0x7ffff7f89e39 <heap.SmpAllocator.alloc+537>
   0x00007ffff7f89d65 <+325>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d6c <+332>:	cmp    rax,0x0
   0x00007ffff7f89d70 <+336>:	jne    0x7ffff7f89d89 <heap.SmpAllocator.alloc+361>
   0x00007ffff7f89d72 <+338>:	jmp    0x7ffff7f89d8b <heap.SmpAllocator.alloc+363>
   0x00007ffff7f89d74 <+340>:	jmp    0x7ffff7f89d47 <heap.SmpAllocator.alloc+295>
   0x00007ffff7f89d76 <+342>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d7d <+349>:	and    rax,0x7
   0x00007ffff7f89d81 <+353>:	cmp    rax,0x0
   0x00007ffff7f89d85 <+357>:	je     0x7ffff7f89dba <heap.SmpAllocator.alloc+410>
   0x00007ffff7f89d87 <+359>:	jmp    0x7ffff7f89dbc <heap.SmpAllocator.alloc+412>
   0x00007ffff7f89d89 <+361>:	jmp    0x7ffff7f89d76 <heap.SmpAllocator.alloc+342>
   0x00007ffff7f89d8b <+363>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89d8f <+367>:	call   0x7ffff7efa8d0 <debug.FullPanic((function 'defaultPanic')).castToNull>
   0x00007ffff7f89d94 <+372>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d98 <+376>:	mov    rcx,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d9f <+383>:	mov    QWORD PTR [rbp-0x20],rcx
   0x00007ffff7f89da3 <+387>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89da7 <+391>:	add    rcx,0x68
   0x00007ffff7f89dab <+395>:	mov    QWORD PTR [rbp-0xb0],rcx
   0x00007ffff7f89db2 <+402>:	cmp    rax,0xd
   0x00007ffff7f89db6 <+406>:	jb     0x7ffff7f89dfb <heap.SmpAllocator.alloc+475>
   0x00007ffff7f89db8 <+408>:	jmp    0x7ffff7f89dfd <heap.SmpAllocator.alloc+477>
   0x00007ffff7f89dba <+410>:	jmp    0x7ffff7f89d94 <heap.SmpAllocator.alloc+372>
   0x00007ffff7f89dbc <+412>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89dc0 <+416>:	call   0x7ffff7ef5d30 <debug.FullPanic((function 'defaultPanic')).incorrectAlignment>
   0x00007ffff7f89dc5 <+421>:	mov    rdx,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89dcc <+428>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89dd0 <+432>:	mov    rax,QWORD PTR [rbp-0xb0]
   0x00007ffff7f89dd7 <+439>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89ddb <+443>:	mov    rdx,QWORD PTR [rdx]
   0x00007ffff7f89dde <+446>:	mov    QWORD PTR [rax+rcx*8],rdx
   0x00007ffff7f89de2 <+450>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89de6 <+454>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89deb <+459>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89df2 <+466>:	add    rsp,0x120
   0x00007ffff7f89df9 <+473>:	pop    rbp
   0x00007ffff7f89dfa <+474>:	ret
   0x00007ffff7f89dfb <+475>:	jmp    0x7ffff7f89dc5 <heap.SmpAllocator.alloc+421>
   0x00007ffff7f89dfd <+477>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e01 <+481>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89e05 <+485>:	mov    edx,0xd
   0x00007ffff7f89e0a <+490>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89e0f <+495>:	mov    rax,QWORD PTR [rbp-0xa8]
   0x00007ffff7f89e16 <+502>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e1a <+506>:	mov    rax,QWORD PTR [rax+rcx*8]
   0x00007ffff7f89e1e <+510>:	mov    QWORD PTR [rbp-0xb8],rax
   0x00007ffff7f89e25 <+517>:	mov    QWORD PTR [rbp-0x18],rax
   0x00007ffff7f89e29 <+521>:	and    rax,0xffff
   0x00007ffff7f89e2f <+527>:	cmp    rax,0x0
   0x00007ffff7f89e33 <+531>:	jne    0x7ffff7f89e5a <heap.SmpAllocator.alloc+570>
   0x00007ffff7f89e35 <+533>:	jmp    0x7ffff7f89e71 <heap.SmpAllocator.alloc+593>
   0x00007ffff7f89e37 <+535>:	jmp    0x7ffff7f89e0f <heap.SmpAllocator.alloc+495>
   0x00007ffff7f89e39 <+537>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e3d <+541>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89e41 <+545>:	mov    edx,0xd
   0x00007ffff7f89e46 <+550>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89e4b <+555>:	cmp    BYTE PTR [rbp-0x31],0x1
   0x00007ffff7f89e4f <+559>:	jae    0x7ffff7f89f42 <heap.SmpAllocator.alloc+802>
   0x00007ffff7f89e55 <+565>:	jmp    0x7ffff7f89f70 <heap.SmpAllocator.alloc+848>
   0x00007ffff7f89e5a <+570>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e5e <+574>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89e62 <+578>:	mov    QWORD PTR [rbp-0xc0],rcx
   0x00007ffff7f89e69 <+585>:	cmp    rax,0xd
   0x00007ffff7f89e6d <+589>:	jb     0x7ffff7f89eab <heap.SmpAllocator.alloc+651>
   0x00007ffff7f89e6f <+591>:	jmp    0x7ffff7f89ead <heap.SmpAllocator.alloc+653>
   0x00007ffff7f89e71 <+593>:	jmp    0x7ffff7f89e4b <heap.SmpAllocator.alloc+555>
   0x00007ffff7f89e73 <+595>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89e7a <+602>:	mov    rax,QWORD PTR [rbp-0xb8]
   0x00007ffff7f89e81 <+609>:	mov    rdx,QWORD PTR [rbp-0xc0]
   0x00007ffff7f89e88 <+616>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e8c <+620>:	shl    rsi,0x3
   0x00007ffff7f89e90 <+624>:	add    rdx,rsi
   0x00007ffff7f89e93 <+627>:	mov    QWORD PTR [rbp-0xd0],rdx
   0x00007ffff7f89e9a <+634>:	add    rax,rcx
   0x00007ffff7f89e9d <+637>:	mov    QWORD PTR [rbp-0xc8],rax
   0x00007ffff7f89ea4 <+644>:	setb   al
   0x00007ffff7f89ea7 <+647>:	jb     0x7ffff7f89ebf <heap.SmpAllocator.alloc+671>
   0x00007ffff7f89ea9 <+649>:	jmp    0x7ffff7f89ec8 <heap.SmpAllocator.alloc+680>
   0x00007ffff7f89eab <+651>:	jmp    0x7ffff7f89e73 <heap.SmpAllocator.alloc+595>
   0x00007ffff7f89ead <+653>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89eb1 <+657>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89eb5 <+661>:	mov    edx,0xd
   0x00007ffff7f89eba <+666>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89ebf <+671>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89ec3 <+675>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f89ec8 <+680>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89ecc <+684>:	mov    rax,QWORD PTR [rbp-0xd0]
   0x00007ffff7f89ed3 <+691>:	mov    rcx,QWORD PTR [rbp-0xc8]
   0x00007ffff7f89eda <+698>:	mov    QWORD PTR [rax],rcx
   0x00007ffff7f89edd <+701>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89ee1 <+705>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89ee6 <+710>:	mov    rax,QWORD PTR [rbp-0xb8]
   0x00007ffff7f89eed <+717>:	add    rsp,0x120
   0x00007ffff7f89ef4 <+724>:	pop    rbp
   0x00007ffff7f89ef5 <+725>:	ret
   0x00007ffff7f89ef6 <+726>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89efa <+730>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89efe <+734>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89f03 <+739>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f07 <+743>:	call   0x7ffff7f8a410 <heap.SmpAllocator.getCpuCount>
   0x00007ffff7f89f0c <+748>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f10 <+752>:	mov    ecx,eax
   0x00007ffff7f89f12 <+754>:	mov    DWORD PTR [rbp-0xd4],ecx
   0x00007ffff7f89f18 <+760>:	mov    DWORD PTR [rbp-0x8],eax
   0x00007ffff7f89f1b <+763>:	test   eax,eax
   0x00007ffff7f89f1d <+765>:	setne  al
   0x00007ffff7f89f20 <+768>:	movzx  esi,al
   0x00007ffff7f89f23 <+771>:	call   0x7ffff7ef2790 <debug.assert>
   0x00007ffff7f89f28 <+776>:	lea    rdi,[rip+0x27bf1]        # 0x7ffff7fb1b20
   0x00007ffff7f89f2f <+783>:	call   0x7ffff7fae630 <__tls_get_addr@plt>
   0x00007ffff7f89f34 <+788>:	mov    eax,DWORD PTR [rax+0x10]
   0x00007ffff7f89f3a <+794>:	mov    DWORD PTR [rbp-0x4],eax
   0x00007ffff7f89f3d <+797>:	jmp    0x7ffff7f8a046 <heap.SmpAllocator.alloc+1062>
   0x00007ffff7f89f42 <+802>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f46 <+806>:	mov    esi,0x10000
   0x00007ffff7f89f4b <+811>:	call   0x7ffff7f18cd0 <mem.Alignment.fromByteUnits>
   0x00007ffff7f89f50 <+816>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f54 <+820>:	movzx  edx,al
   0x00007ffff7f89f57 <+823>:	mov    esi,0x10000
   0x00007ffff7f89f5c <+828>:	call   0x7ffff7f889a0 <heap.PageAllocator.map>
   0x00007ffff7f89f61 <+833>:	mov    QWORD PTR [rbp-0xe0],rax
   0x00007ffff7f89f68 <+840>:	cmp    rax,0x0
   0x00007ffff7f89f6c <+844>:	jne    0x7ffff7f89f9b <heap.SmpAllocator.alloc+891>
   0x00007ffff7f89f6e <+846>:	jmp    0x7ffff7f89fab <heap.SmpAllocator.alloc+907>
   0x00007ffff7f89f70 <+848>:	jmp    0x7ffff7f89ef6 <heap.SmpAllocator.alloc+726>
   0x00007ffff7f89f72 <+850>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89f76 <+854>:	mov    rcx,QWORD PTR [rbp-0xf8]
   0x00007ffff7f89f7d <+861>:	mov    QWORD PTR [rbp-0xf0],rcx
   0x00007ffff7f89f84 <+868>:	mov    QWORD PTR [rbp-0x10],rcx
   0x00007ffff7f89f88 <+872>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89f8c <+876>:	mov    QWORD PTR [rbp-0xe8],rcx
   0x00007ffff7f89f93 <+883>:	cmp    rax,0xd
   0x00007ffff7f89f97 <+887>:	jb     0x7ffff7f89ffb <heap.SmpAllocator.alloc+987>
   0x00007ffff7f89f99 <+889>:	jmp    0x7ffff7f89ffd <heap.SmpAllocator.alloc+989>
   0x00007ffff7f89f9b <+891>:	mov    rax,QWORD PTR [rbp-0xe0]
   0x00007ffff7f89fa2 <+898>:	mov    QWORD PTR [rbp-0xf8],rax
   0x00007ffff7f89fa9 <+905>:	jmp    0x7ffff7f89f72 <heap.SmpAllocator.alloc+850>
   0x00007ffff7f89fab <+907>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89faf <+911>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89fb3 <+915>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89fb8 <+920>:	xor    eax,eax
   0x00007ffff7f89fba <+922>:	add    rsp,0x120
   0x00007ffff7f89fc1 <+929>:	pop    rbp
   0x00007ffff7f89fc2 <+930>:	ret
   0x00007ffff7f89fc3 <+931>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89fca <+938>:	mov    rax,QWORD PTR [rbp-0xf0]
   0x00007ffff7f89fd1 <+945>:	mov    rdx,QWORD PTR [rbp-0xe8]
   0x00007ffff7f89fd8 <+952>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89fdc <+956>:	shl    rsi,0x3
   0x00007ffff7f89fe0 <+960>:	add    rdx,rsi
   0x00007ffff7f89fe3 <+963>:	mov    QWORD PTR [rbp-0x108],rdx
   0x00007ffff7f89fea <+970>:	add    rax,rcx
   0x00007ffff7f89fed <+973>:	mov    QWORD PTR [rbp-0x100],rax
   0x00007ffff7f89ff4 <+980>:	setb   al
   0x00007ffff7f89ff7 <+983>:	jb     0x7ffff7f8a00f <heap.SmpAllocator.alloc+1007>
   0x00007ffff7f89ff9 <+985>:	jmp    0x7ffff7f8a018 <heap.SmpAllocator.alloc+1016>
   0x00007ffff7f89ffb <+987>:	jmp    0x7ffff7f89fc3 <heap.SmpAllocator.alloc+931>
   0x00007ffff7f89ffd <+989>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f8a001 <+993>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a005 <+997>:	mov    edx,0xd
   0x00007ffff7f8a00a <+1002>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f8a00f <+1007>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a013 <+1011>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a018 <+1016>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a01c <+1020>:	mov    rax,QWORD PTR [rbp-0x108]
   0x00007ffff7f8a023 <+1027>:	mov    rcx,QWORD PTR [rbp-0x100]
   0x00007ffff7f8a02a <+1034>:	mov    QWORD PTR [rax],rcx
   0x00007ffff7f8a02d <+1037>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f8a031 <+1041>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f8a036 <+1046>:	mov    rax,QWORD PTR [rbp-0xf0]
   0x00007ffff7f8a03d <+1053>:	add    rsp,0x120
   0x00007ffff7f8a044 <+1060>:	pop    rbp
   0x00007ffff7f8a045 <+1061>:	ret
   0x00007ffff7f8a046 <+1062>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a049 <+1065>:	add    eax,0x1
   0x00007ffff7f8a04c <+1068>:	mov    DWORD PTR [rbp-0x10c],eax
   0x00007ffff7f8a052 <+1074>:	setb   al
   0x00007ffff7f8a055 <+1077>:	jb     0x7ffff7f8a059 <heap.SmpAllocator.alloc+1081>
   0x00007ffff7f8a057 <+1079>:	jmp    0x7ffff7f8a062 <heap.SmpAllocator.alloc+1090>
   0x00007ffff7f8a059 <+1081>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a05d <+1085>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a062 <+1090>:	mov    eax,DWORD PTR [rbp-0xd4]
   0x00007ffff7f8a068 <+1096>:	cmp    eax,0x0
   0x00007ffff7f8a06b <+1099>:	jne    0x7ffff7f8a096 <heap.SmpAllocator.alloc+1142>
   0x00007ffff7f8a06d <+1101>:	jmp    0x7ffff7f8a098 <heap.SmpAllocator.alloc+1144>
   0x00007ffff7f8a06f <+1103>:	mov    ecx,DWORD PTR [rbp-0xd4]
   0x00007ffff7f8a075 <+1109>:	mov    eax,DWORD PTR [rbp-0x10c]
   0x00007ffff7f8a07b <+1115>:	xor    edx,edx
   0x00007ffff7f8a07d <+1117>:	div    ecx
   0x00007ffff7f8a07f <+1119>:	mov    DWORD PTR [rbp-0x4],edx
   0x00007ffff7f8a082 <+1122>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a085 <+1125>:	mov    QWORD PTR [rbp-0x118],rax
   0x00007ffff7f8a08c <+1132>:	cmp    rax,0x80
   0x00007ffff7f8a092 <+1138>:	jb     0x7ffff7f8a0d4 <heap.SmpAllocator.alloc+1204>
   0x00007ffff7f8a094 <+1140>:	jmp    0x7ffff7f8a0d6 <heap.SmpAllocator.alloc+1206>
   0x00007ffff7f8a096 <+1142>:	jmp    0x7ffff7f8a06f <heap.SmpAllocator.alloc+1103>
   0x00007ffff7f8a098 <+1144>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a09c <+1148>:	call   0x7ffff7f10e70 <debug.FullPanic((function 'defaultPanic')).divideByZero>
   0x00007ffff7f8a0a1 <+1153>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a0a5 <+1157>:	mov    rcx,QWORD PTR [rbp-0x118]
   0x00007ffff7f8a0ac <+1164>:	lea    rax,[rip+0x29fcd]        # 0x7ffff7fb4080 <heap.SmpAllocator.global>
   0x00007ffff7f8a0b3 <+1171>:	shl    rcx,0x8
   0x00007ffff7f8a0b7 <+1175>:	add    rax,rcx
   0x00007ffff7f8a0ba <+1178>:	mov    QWORD PTR [rbp-0x30],rax
   0x00007ffff7f8a0be <+1182>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f8a0c2 <+1186>:	add    rsi,0xd0
   0x00007ffff7f8a0c9 <+1193>:	call   0x7ffff7f8a4e0 <Thread.Mutex.tryLock>
   0x00007ffff7f8a0ce <+1198>:	test   al,0x1
   0x00007ffff7f8a0d0 <+1200>:	jne    0x7ffff7f8a0f0 <heap.SmpAllocator.alloc+1232>
   0x00007ffff7f8a0d2 <+1202>:	jmp    0x7ffff7f8a125 <heap.SmpAllocator.alloc+1285>
   0x00007ffff7f8a0d4 <+1204>:	jmp    0x7ffff7f8a0a1 <heap.SmpAllocator.alloc+1153>
   0x00007ffff7f8a0d6 <+1206>:	mov    rsi,QWORD PTR [rbp-0x118]
   0x00007ffff7f8a0dd <+1213>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a0e1 <+1217>:	mov    edx,0x80
   0x00007ffff7f8a0e6 <+1222>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f8a0eb <+1227>:	jmp    0x7ffff7f8a046 <heap.SmpAllocator.alloc+1062>
   0x00007ffff7f8a0f0 <+1232>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a0f3 <+1235>:	mov    DWORD PTR [rbp-0x120],eax
   0x00007ffff7f8a0f9 <+1241>:	lea    rdi,[rip+0x27a20]        # 0x7ffff7fb1b20
   0x00007ffff7f8a100 <+1248>:	call   0x7ffff7fae630 <__tls_get_addr@plt>
   0x00007ffff7f8a105 <+1253>:	mov    ecx,DWORD PTR [rbp-0x120]
=> 0x00007ffff7f8a10b <+1259>:	mov    DWORD PTR [rax+0x10],ecx
   0x00007ffff7f8a111 <+1265>:	mov    al,BYTE PTR [rbp-0x31]
   0x00007ffff7f8a114 <+1268>:	add    al,0x1
   0x00007ffff7f8a116 <+1270>:	mov    BYTE PTR [rbp-0x119],al
   0x00007ffff7f8a11c <+1276>:	setb   al
   0x00007ffff7f8a11f <+1279>:	test   al,0x1
   0x00007ffff7f8a121 <+1281>:	jne    0x7ffff7f8a127 <heap.SmpAllocator.alloc+1287>
   0x00007ffff7f8a123 <+1283>:	jmp    0x7ffff7f8a130 <heap.SmpAllocator.alloc+1296>
   0x00007ffff7f8a125 <+1285>:	jmp    0x7ffff7f8a0eb <heap.SmpAllocator.alloc+1227>
   0x00007ffff7f8a127 <+1287>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a12b <+1291>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a130 <+1296>:	mov    al,BYTE PTR [rbp-0x119]
   0x00007ffff7f8a136 <+1302>:	mov    BYTE PTR [rbp-0x31],al
   0x00007ffff7f8a139 <+1305>:	jmp    0x7ffff7f89d0f <heap.SmpAllocator.alloc+239>
End of assembler dump.
#0  0x00007ffff7f8a10b in heap.SmpAllocator.alloc (context=0x0, len=1032, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
#1  0x00007ffff7f346ba in mem.Allocator.rawAlloc () at /usr/lib/zig/std/mem/Allocator.zig:129
#2  mem.Allocator.allocBytesWithAlignment__anon_14706 (self=..., byte_count=1032, return_address=140737353643937) at /usr/lib/zig/std/mem/Allocator.zig:269
#3  0x00007ffff7f26313 in mem.Allocator.allocWithSizeAndAlignment__anon_11852 (self=..., n=1032, return_address=140737353643937) at /usr/lib/zig/std/mem/Allocator.zig:260
#4  0x00007ffff7f0ec22 in mem.Allocator.allocAdvancedWithRetAddr () at /usr/lib/zig/std/mem/Allocator.zig:254
#5  mem.Allocator.alloc__anon_8671 (self=..., n=1032) at /usr/lib/zig/std/mem/Allocator.zig:178
#6  0x00007ffff7f877a1 in root.internal_malloc (len=1024, zeroed=false) at root.zig:12
#7  0x00007ffff7f876fb in root.malloc (len=1024) at root.zig:28
#8  0x00007ffff7967924 in __GI__IO_file_doallocate (fp=0x7ffff7ad15c0 <_IO_2_1_stdout_>) at filedoalloc.c:101
#9  0x00007ffff7977134 in __GI__IO_doallocbuf (fp=0x7ffff7ad15c0 <_IO_2_1_stdout_>) at /usr/src/debug/glibc/glibc/libio/libioP.h:1041
#10 __GI__IO_doallocbuf (fp=fp@entry=0x7ffff7ad15c0 <_IO_2_1_stdout_>) at genops.c:368
#11 0x00007ffff7975178 in _IO_new_file_overflow (f=0x7ffff7ad15c0 <_IO_2_1_stdout_>, ch=-1) at fileops.c:746
#12 0x00007ffff7975c98 in _IO_new_file_xsputn (f=0x7ffff7ad15c0 <_IO_2_1_stdout_>, data=<optimized out>, n=25) at /usr/src/debug/glibc/glibc/libio/libioP.h:1041
#13 _IO_new_file_xsputn (f=0x7ffff7ad15c0 <_IO_2_1_stdout_>, data=<optimized out>, n=25) at fileops.c:1198
#14 0x00007ffff7942709 in __printf_buffer_flush_to_file (buf=buf@entry=0x7ffffffd7e80) at ../libio/libioP.h:1041
#15 0x00007ffff79427cc in __printf_buffer_to_file_done (buf=buf@entry=0x7ffffffd7e80) at printf_buffer_to_file.c:120
#16 0x00007ffff794e1ec in __vfprintf_internal (s=0x7ffff7ad15c0 <_IO_2_1_stdout_>, format=0x55555555d11e "about to run thread %zd...\n", ap=ap@entry=0x7ffffffd7f80, mode_flags=mode_flags@entry=0) at vfprintf-internal.c:1545
#17 0x00007ffff7941eb3 in __printf (format=<optimized out>) at printf.c:33
#18 0x0000555555556e82 in runTest<NewDeleteAllocatorForTest> (startupParams=0x7ffffffd8a30) at allocator_tester.cpp:82
#19 0x00005555555569f5 in main (argc=2, argv=0x7fffffffd7a8) at allocator_tester.cpp:141
169	                search_count += 1;
$2 = 1
No symbol "ecx" in current context.
$3 = 140737352615784
$4 = 0
0x0:	Cannot access memory at address 0x0
Item count other than 1 is meaningless in "print" command.
   0x0:	Cannot access memory at address 0x0
$5 = 0
$6 = 2130771968
Dump of assembler code for function heap.SmpAllocator.alloc:
   0x00007ffff7f89c20 <+0>:	push   rbp
   0x00007ffff7f89c21 <+1>:	mov    rbp,rsp
   0x00007ffff7f89c24 <+4>:	sub    rsp,0x120
   0x00007ffff7f89c2b <+11>:	mov    eax,ecx
   0x00007ffff7f89c2d <+13>:	mov    QWORD PTR [rbp-0x88],rdx
   0x00007ffff7f89c34 <+20>:	mov    rcx,rsi
   0x00007ffff7f89c37 <+23>:	mov    rsi,QWORD PTR [rbp-0x88]
   0x00007ffff7f89c3e <+30>:	mov    QWORD PTR [rbp-0x80],rdi
   0x00007ffff7f89c42 <+34>:	mov    BYTE PTR [rbp-0x71],al
   0x00007ffff7f89c45 <+37>:	mov    QWORD PTR [rbp-0x68],rcx
   0x00007ffff7f89c49 <+41>:	mov    QWORD PTR [rbp-0x60],rsi
   0x00007ffff7f89c4d <+45>:	mov    cl,al
   0x00007ffff7f89c4f <+47>:	and    cl,0x3f
   0x00007ffff7f89c52 <+50>:	mov    BYTE PTR [rbp-0x51],cl
   0x00007ffff7f89c55 <+53>:	mov    QWORD PTR [rbp-0x50],r8
   0x00007ffff7f89c59 <+57>:	movzx  edx,al
   0x00007ffff7f89c5c <+60>:	call   0x7ffff7f8a140 <heap.SmpAllocator.sizeClassIndex>
   0x00007ffff7f89c61 <+65>:	mov    QWORD PTR [rbp-0x70],rax
   0x00007ffff7f89c65 <+69>:	mov    QWORD PTR [rbp-0x48],rax
   0x00007ffff7f89c69 <+73>:	cmp    rax,0xd
   0x00007ffff7f89c6d <+77>:	jae    0x7ffff7f89c91 <heap.SmpAllocator.alloc+113>
   0x00007ffff7f89c6f <+79>:	jmp    0x7ffff7f89cb0 <heap.SmpAllocator.alloc+144>
   0x00007ffff7f89c71 <+81>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89c75 <+85>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89c79 <+89>:	call   0x7ffff7f8a200 <heap.SmpAllocator.slotSize>
   0x00007ffff7f89c7e <+94>:	mov    QWORD PTR [rbp-0x90],rax
   0x00007ffff7f89c85 <+101>:	mov    QWORD PTR [rbp-0x40],rax
   0x00007ffff7f89c89 <+105>:	cmp    rax,0x0
   0x00007ffff7f89c8d <+109>:	jne    0x7ffff7f89ce9 <heap.SmpAllocator.alloc+201>
   0x00007ffff7f89c8f <+111>:	jmp    0x7ffff7f89ceb <heap.SmpAllocator.alloc+203>
   0x00007ffff7f89c91 <+113>:	mov    rsi,QWORD PTR [rbp-0x88]
   0x00007ffff7f89c98 <+120>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89c9c <+124>:	mov    al,BYTE PTR [rbp-0x71]
   0x00007ffff7f89c9f <+127>:	movzx  edx,al
   0x00007ffff7f89ca2 <+130>:	call   0x7ffff7f889a0 <heap.PageAllocator.map>
   0x00007ffff7f89ca7 <+135>:	add    rsp,0x120
   0x00007ffff7f89cae <+142>:	pop    rbp
   0x00007ffff7f89caf <+143>:	ret
   0x00007ffff7f89cb0 <+144>:	jmp    0x7ffff7f89c71 <heap.SmpAllocator.alloc+81>
   0x00007ffff7f89cb2 <+146>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cb6 <+150>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89cbd <+157>:	mov    eax,0x10000
   0x00007ffff7f89cc2 <+162>:	xor    edx,edx
   0x00007ffff7f89cc4 <+164>:	div    rcx
   0x00007ffff7f89cc7 <+167>:	cmp    rdx,0x0
   0x00007ffff7f89ccb <+171>:	sete   al
   0x00007ffff7f89cce <+174>:	movzx  esi,al
   0x00007ffff7f89cd1 <+177>:	call   0x7ffff7ef2790 <debug.assert>
   0x00007ffff7f89cd6 <+182>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cda <+186>:	mov    BYTE PTR [rbp-0x31],0x0
   0x00007ffff7f89cde <+190>:	call   0x7ffff7f8a260 <heap.SmpAllocator.Thread.lock>
   0x00007ffff7f89ce3 <+195>:	mov    QWORD PTR [rbp-0x30],rax
   0x00007ffff7f89ce7 <+199>:	jmp    0x7ffff7f89cf4 <heap.SmpAllocator.alloc+212>
   0x00007ffff7f89ce9 <+201>:	jmp    0x7ffff7f89cb2 <heap.SmpAllocator.alloc+146>
   0x00007ffff7f89ceb <+203>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cef <+207>:	call   0x7ffff7f10e70 <debug.FullPanic((function 'defaultPanic')).divideByZero>
   0x00007ffff7f89cf4 <+212>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89cf8 <+216>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89cfc <+220>:	add    rcx,0x68
   0x00007ffff7f89d00 <+224>:	mov    QWORD PTR [rbp-0x98],rcx
   0x00007ffff7f89d07 <+231>:	cmp    rax,0xd
   0x00007ffff7f89d0b <+235>:	jb     0x7ffff7f89d33 <heap.SmpAllocator.alloc+275>
   0x00007ffff7f89d0d <+237>:	jmp    0x7ffff7f89d35 <heap.SmpAllocator.alloc+277>
   0x00007ffff7f89d0f <+239>:	jmp    0x7ffff7f89cf4 <heap.SmpAllocator.alloc+212>
   0x00007ffff7f89d11 <+241>:	mov    rax,QWORD PTR [rbp-0x98]
   0x00007ffff7f89d18 <+248>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d1c <+252>:	mov    rax,QWORD PTR [rax+rcx*8]
   0x00007ffff7f89d20 <+256>:	mov    QWORD PTR [rbp-0xa0],rax
   0x00007ffff7f89d27 <+263>:	mov    QWORD PTR [rbp-0x28],rax
   0x00007ffff7f89d2b <+267>:	cmp    rax,0x0
   0x00007ffff7f89d2f <+271>:	jne    0x7ffff7f89d65 <heap.SmpAllocator.alloc+325>
   0x00007ffff7f89d31 <+273>:	jmp    0x7ffff7f89d74 <heap.SmpAllocator.alloc+340>
   0x00007ffff7f89d33 <+275>:	jmp    0x7ffff7f89d11 <heap.SmpAllocator.alloc+241>
   0x00007ffff7f89d35 <+277>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d39 <+281>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89d3d <+285>:	mov    edx,0xd
   0x00007ffff7f89d42 <+290>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89d47 <+295>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d4b <+299>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89d4f <+303>:	mov    QWORD PTR [rbp-0xa8],rcx
   0x00007ffff7f89d56 <+310>:	cmp    rax,0xd
   0x00007ffff7f89d5a <+314>:	jb     0x7ffff7f89e37 <heap.SmpAllocator.alloc+535>
   0x00007ffff7f89d60 <+320>:	jmp    0x7ffff7f89e39 <heap.SmpAllocator.alloc+537>
   0x00007ffff7f89d65 <+325>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d6c <+332>:	cmp    rax,0x0
   0x00007ffff7f89d70 <+336>:	jne    0x7ffff7f89d89 <heap.SmpAllocator.alloc+361>
   0x00007ffff7f89d72 <+338>:	jmp    0x7ffff7f89d8b <heap.SmpAllocator.alloc+363>
   0x00007ffff7f89d74 <+340>:	jmp    0x7ffff7f89d47 <heap.SmpAllocator.alloc+295>
   0x00007ffff7f89d76 <+342>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d7d <+349>:	and    rax,0x7
   0x00007ffff7f89d81 <+353>:	cmp    rax,0x0
   0x00007ffff7f89d85 <+357>:	je     0x7ffff7f89dba <heap.SmpAllocator.alloc+410>
   0x00007ffff7f89d87 <+359>:	jmp    0x7ffff7f89dbc <heap.SmpAllocator.alloc+412>
   0x00007ffff7f89d89 <+361>:	jmp    0x7ffff7f89d76 <heap.SmpAllocator.alloc+342>
   0x00007ffff7f89d8b <+363>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89d8f <+367>:	call   0x7ffff7efa8d0 <debug.FullPanic((function 'defaultPanic')).castToNull>
   0x00007ffff7f89d94 <+372>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d98 <+376>:	mov    rcx,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d9f <+383>:	mov    QWORD PTR [rbp-0x20],rcx
   0x00007ffff7f89da3 <+387>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89da7 <+391>:	add    rcx,0x68
   0x00007ffff7f89dab <+395>:	mov    QWORD PTR [rbp-0xb0],rcx
   0x00007ffff7f89db2 <+402>:	cmp    rax,0xd
   0x00007ffff7f89db6 <+406>:	jb     0x7ffff7f89dfb <heap.SmpAllocator.alloc+475>
   0x00007ffff7f89db8 <+408>:	jmp    0x7ffff7f89dfd <heap.SmpAllocator.alloc+477>
   0x00007ffff7f89dba <+410>:	jmp    0x7ffff7f89d94 <heap.SmpAllocator.alloc+372>
   0x00007ffff7f89dbc <+412>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89dc0 <+416>:	call   0x7ffff7ef5d30 <debug.FullPanic((function 'defaultPanic')).incorrectAlignment>
   0x00007ffff7f89dc5 <+421>:	mov    rdx,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89dcc <+428>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89dd0 <+432>:	mov    rax,QWORD PTR [rbp-0xb0]
   0x00007ffff7f89dd7 <+439>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89ddb <+443>:	mov    rdx,QWORD PTR [rdx]
   0x00007ffff7f89dde <+446>:	mov    QWORD PTR [rax+rcx*8],rdx
   0x00007ffff7f89de2 <+450>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89de6 <+454>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89deb <+459>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89df2 <+466>:	add    rsp,0x120
   0x00007ffff7f89df9 <+473>:	pop    rbp
   0x00007ffff7f89dfa <+474>:	ret
   0x00007ffff7f89dfb <+475>:	jmp    0x7ffff7f89dc5 <heap.SmpAllocator.alloc+421>
   0x00007ffff7f89dfd <+477>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e01 <+481>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89e05 <+485>:	mov    edx,0xd
   0x00007ffff7f89e0a <+490>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89e0f <+495>:	mov    rax,QWORD PTR [rbp-0xa8]
   0x00007ffff7f89e16 <+502>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e1a <+506>:	mov    rax,QWORD PTR [rax+rcx*8]
   0x00007ffff7f89e1e <+510>:	mov    QWORD PTR [rbp-0xb8],rax
   0x00007ffff7f89e25 <+517>:	mov    QWORD PTR [rbp-0x18],rax
   0x00007ffff7f89e29 <+521>:	and    rax,0xffff
   0x00007ffff7f89e2f <+527>:	cmp    rax,0x0
   0x00007ffff7f89e33 <+531>:	jne    0x7ffff7f89e5a <heap.SmpAllocator.alloc+570>
   0x00007ffff7f89e35 <+533>:	jmp    0x7ffff7f89e71 <heap.SmpAllocator.alloc+593>
   0x00007ffff7f89e37 <+535>:	jmp    0x7ffff7f89e0f <heap.SmpAllocator.alloc+495>
   0x00007ffff7f89e39 <+537>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e3d <+541>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89e41 <+545>:	mov    edx,0xd
   0x00007ffff7f89e46 <+550>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89e4b <+555>:	cmp    BYTE PTR [rbp-0x31],0x1
   0x00007ffff7f89e4f <+559>:	jae    0x7ffff7f89f42 <heap.SmpAllocator.alloc+802>
   0x00007ffff7f89e55 <+565>:	jmp    0x7ffff7f89f70 <heap.SmpAllocator.alloc+848>
   0x00007ffff7f89e5a <+570>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e5e <+574>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89e62 <+578>:	mov    QWORD PTR [rbp-0xc0],rcx
   0x00007ffff7f89e69 <+585>:	cmp    rax,0xd
   0x00007ffff7f89e6d <+589>:	jb     0x7ffff7f89eab <heap.SmpAllocator.alloc+651>
   0x00007ffff7f89e6f <+591>:	jmp    0x7ffff7f89ead <heap.SmpAllocator.alloc+653>
   0x00007ffff7f89e71 <+593>:	jmp    0x7ffff7f89e4b <heap.SmpAllocator.alloc+555>
   0x00007ffff7f89e73 <+595>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89e7a <+602>:	mov    rax,QWORD PTR [rbp-0xb8]
   0x00007ffff7f89e81 <+609>:	mov    rdx,QWORD PTR [rbp-0xc0]
   0x00007ffff7f89e88 <+616>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e8c <+620>:	shl    rsi,0x3
   0x00007ffff7f89e90 <+624>:	add    rdx,rsi
   0x00007ffff7f89e93 <+627>:	mov    QWORD PTR [rbp-0xd0],rdx
   0x00007ffff7f89e9a <+634>:	add    rax,rcx
   0x00007ffff7f89e9d <+637>:	mov    QWORD PTR [rbp-0xc8],rax
   0x00007ffff7f89ea4 <+644>:	setb   al
   0x00007ffff7f89ea7 <+647>:	jb     0x7ffff7f89ebf <heap.SmpAllocator.alloc+671>
   0x00007ffff7f89ea9 <+649>:	jmp    0x7ffff7f89ec8 <heap.SmpAllocator.alloc+680>
   0x00007ffff7f89eab <+651>:	jmp    0x7ffff7f89e73 <heap.SmpAllocator.alloc+595>
   0x00007ffff7f89ead <+653>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89eb1 <+657>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89eb5 <+661>:	mov    edx,0xd
   0x00007ffff7f89eba <+666>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89ebf <+671>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89ec3 <+675>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f89ec8 <+680>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89ecc <+684>:	mov    rax,QWORD PTR [rbp-0xd0]
   0x00007ffff7f89ed3 <+691>:	mov    rcx,QWORD PTR [rbp-0xc8]
   0x00007ffff7f89eda <+698>:	mov    QWORD PTR [rax],rcx
   0x00007ffff7f89edd <+701>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89ee1 <+705>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89ee6 <+710>:	mov    rax,QWORD PTR [rbp-0xb8]
   0x00007ffff7f89eed <+717>:	add    rsp,0x120
   0x00007ffff7f89ef4 <+724>:	pop    rbp
   0x00007ffff7f89ef5 <+725>:	ret
   0x00007ffff7f89ef6 <+726>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89efa <+730>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89efe <+734>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89f03 <+739>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f07 <+743>:	call   0x7ffff7f8a410 <heap.SmpAllocator.getCpuCount>
   0x00007ffff7f89f0c <+748>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f10 <+752>:	mov    ecx,eax
   0x00007ffff7f89f12 <+754>:	mov    DWORD PTR [rbp-0xd4],ecx
   0x00007ffff7f89f18 <+760>:	mov    DWORD PTR [rbp-0x8],eax
   0x00007ffff7f89f1b <+763>:	test   eax,eax
   0x00007ffff7f89f1d <+765>:	setne  al
   0x00007ffff7f89f20 <+768>:	movzx  esi,al
   0x00007ffff7f89f23 <+771>:	call   0x7ffff7ef2790 <debug.assert>
   0x00007ffff7f89f28 <+776>:	lea    rdi,[rip+0x27bf1]        # 0x7ffff7fb1b20
   0x00007ffff7f89f2f <+783>:	call   0x7ffff7fae630 <__tls_get_addr@plt>
   0x00007ffff7f89f34 <+788>:	mov    eax,DWORD PTR [rax+0x10]
   0x00007ffff7f89f3a <+794>:	mov    DWORD PTR [rbp-0x4],eax
   0x00007ffff7f89f3d <+797>:	jmp    0x7ffff7f8a046 <heap.SmpAllocator.alloc+1062>
   0x00007ffff7f89f42 <+802>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f46 <+806>:	mov    esi,0x10000
   0x00007ffff7f89f4b <+811>:	call   0x7ffff7f18cd0 <mem.Alignment.fromByteUnits>
   0x00007ffff7f89f50 <+816>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f54 <+820>:	movzx  edx,al
   0x00007ffff7f89f57 <+823>:	mov    esi,0x10000
   0x00007ffff7f89f5c <+828>:	call   0x7ffff7f889a0 <heap.PageAllocator.map>
   0x00007ffff7f89f61 <+833>:	mov    QWORD PTR [rbp-0xe0],rax
   0x00007ffff7f89f68 <+840>:	cmp    rax,0x0
   0x00007ffff7f89f6c <+844>:	jne    0x7ffff7f89f9b <heap.SmpAllocator.alloc+891>
   0x00007ffff7f89f6e <+846>:	jmp    0x7ffff7f89fab <heap.SmpAllocator.alloc+907>
   0x00007ffff7f89f70 <+848>:	jmp    0x7ffff7f89ef6 <heap.SmpAllocator.alloc+726>
   0x00007ffff7f89f72 <+850>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89f76 <+854>:	mov    rcx,QWORD PTR [rbp-0xf8]
   0x00007ffff7f89f7d <+861>:	mov    QWORD PTR [rbp-0xf0],rcx
   0x00007ffff7f89f84 <+868>:	mov    QWORD PTR [rbp-0x10],rcx
   0x00007ffff7f89f88 <+872>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89f8c <+876>:	mov    QWORD PTR [rbp-0xe8],rcx
   0x00007ffff7f89f93 <+883>:	cmp    rax,0xd
   0x00007ffff7f89f97 <+887>:	jb     0x7ffff7f89ffb <heap.SmpAllocator.alloc+987>
   0x00007ffff7f89f99 <+889>:	jmp    0x7ffff7f89ffd <heap.SmpAllocator.alloc+989>
   0x00007ffff7f89f9b <+891>:	mov    rax,QWORD PTR [rbp-0xe0]
   0x00007ffff7f89fa2 <+898>:	mov    QWORD PTR [rbp-0xf8],rax
   0x00007ffff7f89fa9 <+905>:	jmp    0x7ffff7f89f72 <heap.SmpAllocator.alloc+850>
   0x00007ffff7f89fab <+907>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89faf <+911>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89fb3 <+915>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89fb8 <+920>:	xor    eax,eax
   0x00007ffff7f89fba <+922>:	add    rsp,0x120
   0x00007ffff7f89fc1 <+929>:	pop    rbp
   0x00007ffff7f89fc2 <+930>:	ret
   0x00007ffff7f89fc3 <+931>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89fca <+938>:	mov    rax,QWORD PTR [rbp-0xf0]
   0x00007ffff7f89fd1 <+945>:	mov    rdx,QWORD PTR [rbp-0xe8]
   0x00007ffff7f89fd8 <+952>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89fdc <+956>:	shl    rsi,0x3
   0x00007ffff7f89fe0 <+960>:	add    rdx,rsi
   0x00007ffff7f89fe3 <+963>:	mov    QWORD PTR [rbp-0x108],rdx
   0x00007ffff7f89fea <+970>:	add    rax,rcx
   0x00007ffff7f89fed <+973>:	mov    QWORD PTR [rbp-0x100],rax
   0x00007ffff7f89ff4 <+980>:	setb   al
   0x00007ffff7f89ff7 <+983>:	jb     0x7ffff7f8a00f <heap.SmpAllocator.alloc+1007>
   0x00007ffff7f89ff9 <+985>:	jmp    0x7ffff7f8a018 <heap.SmpAllocator.alloc+1016>
   0x00007ffff7f89ffb <+987>:	jmp    0x7ffff7f89fc3 <heap.SmpAllocator.alloc+931>
   0x00007ffff7f89ffd <+989>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f8a001 <+993>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a005 <+997>:	mov    edx,0xd
   0x00007ffff7f8a00a <+1002>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f8a00f <+1007>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a013 <+1011>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a018 <+1016>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a01c <+1020>:	mov    rax,QWORD PTR [rbp-0x108]
   0x00007ffff7f8a023 <+1027>:	mov    rcx,QWORD PTR [rbp-0x100]
   0x00007ffff7f8a02a <+1034>:	mov    QWORD PTR [rax],rcx
   0x00007ffff7f8a02d <+1037>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f8a031 <+1041>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f8a036 <+1046>:	mov    rax,QWORD PTR [rbp-0xf0]
   0x00007ffff7f8a03d <+1053>:	add    rsp,0x120
   0x00007ffff7f8a044 <+1060>:	pop    rbp
   0x00007ffff7f8a045 <+1061>:	ret
   0x00007ffff7f8a046 <+1062>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a049 <+1065>:	add    eax,0x1
   0x00007ffff7f8a04c <+1068>:	mov    DWORD PTR [rbp-0x10c],eax
   0x00007ffff7f8a052 <+1074>:	setb   al
   0x00007ffff7f8a055 <+1077>:	jb     0x7ffff7f8a059 <heap.SmpAllocator.alloc+1081>
   0x00007ffff7f8a057 <+1079>:	jmp    0x7ffff7f8a062 <heap.SmpAllocator.alloc+1090>
   0x00007ffff7f8a059 <+1081>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a05d <+1085>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a062 <+1090>:	mov    eax,DWORD PTR [rbp-0xd4]
   0x00007ffff7f8a068 <+1096>:	cmp    eax,0x0
   0x00007ffff7f8a06b <+1099>:	jne    0x7ffff7f8a096 <heap.SmpAllocator.alloc+1142>
   0x00007ffff7f8a06d <+1101>:	jmp    0x7ffff7f8a098 <heap.SmpAllocator.alloc+1144>
   0x00007ffff7f8a06f <+1103>:	mov    ecx,DWORD PTR [rbp-0xd4]
   0x00007ffff7f8a075 <+1109>:	mov    eax,DWORD PTR [rbp-0x10c]
   0x00007ffff7f8a07b <+1115>:	xor    edx,edx
   0x00007ffff7f8a07d <+1117>:	div    ecx
   0x00007ffff7f8a07f <+1119>:	mov    DWORD PTR [rbp-0x4],edx
   0x00007ffff7f8a082 <+1122>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a085 <+1125>:	mov    QWORD PTR [rbp-0x118],rax
   0x00007ffff7f8a08c <+1132>:	cmp    rax,0x80
   0x00007ffff7f8a092 <+1138>:	jb     0x7ffff7f8a0d4 <heap.SmpAllocator.alloc+1204>
   0x00007ffff7f8a094 <+1140>:	jmp    0x7ffff7f8a0d6 <heap.SmpAllocator.alloc+1206>
   0x00007ffff7f8a096 <+1142>:	jmp    0x7ffff7f8a06f <heap.SmpAllocator.alloc+1103>
   0x00007ffff7f8a098 <+1144>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a09c <+1148>:	call   0x7ffff7f10e70 <debug.FullPanic((function 'defaultPanic')).divideByZero>
   0x00007ffff7f8a0a1 <+1153>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a0a5 <+1157>:	mov    rcx,QWORD PTR [rbp-0x118]
   0x00007ffff7f8a0ac <+1164>:	lea    rax,[rip+0x29fcd]        # 0x7ffff7fb4080 <heap.SmpAllocator.global>
   0x00007ffff7f8a0b3 <+1171>:	shl    rcx,0x8
   0x00007ffff7f8a0b7 <+1175>:	add    rax,rcx
   0x00007ffff7f8a0ba <+1178>:	mov    QWORD PTR [rbp-0x30],rax
   0x00007ffff7f8a0be <+1182>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f8a0c2 <+1186>:	add    rsi,0xd0
   0x00007ffff7f8a0c9 <+1193>:	call   0x7ffff7f8a4e0 <Thread.Mutex.tryLock>
   0x00007ffff7f8a0ce <+1198>:	test   al,0x1
   0x00007ffff7f8a0d0 <+1200>:	jne    0x7ffff7f8a0f0 <heap.SmpAllocator.alloc+1232>
   0x00007ffff7f8a0d2 <+1202>:	jmp    0x7ffff7f8a125 <heap.SmpAllocator.alloc+1285>
   0x00007ffff7f8a0d4 <+1204>:	jmp    0x7ffff7f8a0a1 <heap.SmpAllocator.alloc+1153>
   0x00007ffff7f8a0d6 <+1206>:	mov    rsi,QWORD PTR [rbp-0x118]
   0x00007ffff7f8a0dd <+1213>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a0e1 <+1217>:	mov    edx,0x80
   0x00007ffff7f8a0e6 <+1222>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f8a0eb <+1227>:	jmp    0x7ffff7f8a046 <heap.SmpAllocator.alloc+1062>
   0x00007ffff7f8a0f0 <+1232>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a0f3 <+1235>:	mov    DWORD PTR [rbp-0x120],eax
   0x00007ffff7f8a0f9 <+1241>:	lea    rdi,[rip+0x27a20]        # 0x7ffff7fb1b20
   0x00007ffff7f8a100 <+1248>:	call   0x7ffff7fae630 <__tls_get_addr@plt>
   0x00007ffff7f8a105 <+1253>:	mov    ecx,DWORD PTR [rbp-0x120]
   0x00007ffff7f8a10b <+1259>:	mov    DWORD PTR [rax+0x10],ecx
=> 0x00007ffff7f8a111 <+1265>:	mov    al,BYTE PTR [rbp-0x31]
   0x00007ffff7f8a114 <+1268>:	add    al,0x1
   0x00007ffff7f8a116 <+1270>:	mov    BYTE PTR [rbp-0x119],al
   0x00007ffff7f8a11c <+1276>:	setb   al
   0x00007ffff7f8a11f <+1279>:	test   al,0x1
   0x00007ffff7f8a121 <+1281>:	jne    0x7ffff7f8a127 <heap.SmpAllocator.alloc+1287>
   0x00007ffff7f8a123 <+1283>:	jmp    0x7ffff7f8a130 <heap.SmpAllocator.alloc+1296>
   0x00007ffff7f8a125 <+1285>:	jmp    0x7ffff7f8a0eb <heap.SmpAllocator.alloc+1227>
   0x00007ffff7f8a127 <+1287>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a12b <+1291>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a130 <+1296>:	mov    al,BYTE PTR [rbp-0x119]
   0x00007ffff7f8a136 <+1302>:	mov    BYTE PTR [rbp-0x31],al
   0x00007ffff7f8a139 <+1305>:	jmp    0x7ffff7f89d0f <heap.SmpAllocator.alloc+239>
End of assembler dump.
warning: Currently logging to gdb.c.  Turn the logging off and on to make the new setting effective.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[New Thread 0x7ffff78bf6c0 (LWP 3328)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff78bf6c0 (LWP 3328)]
0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Breakpoint 1 at 0x7ffff7f8a3ae: file /usr/lib/zig/std/heap/SmpAllocator.zig, line 89.
Breakpoint 2 at 0x7ffff7f8a0f0: file /usr/lib/zig/std/heap/SmpAllocator.zig, line 168.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".

Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=1032, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
$1 = 1
#0  heap.SmpAllocator.alloc (context=0x0, len=1032, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
#1  0x00007ffff7f346ba in mem.Allocator.rawAlloc () at /usr/lib/zig/std/mem/Allocator.zig:129
#2  mem.Allocator.allocBytesWithAlignment__anon_14706 (self=..., byte_count=1032, return_address=140737353643937) at /usr/lib/zig/std/mem/Allocator.zig:269
#3  0x00007ffff7f26313 in mem.Allocator.allocWithSizeAndAlignment__anon_11852 (self=..., n=1032, return_address=140737353643937) at /usr/lib/zig/std/mem/Allocator.zig:260
#4  0x00007ffff7f0ec22 in mem.Allocator.allocAdvancedWithRetAddr () at /usr/lib/zig/std/mem/Allocator.zig:254
#5  mem.Allocator.alloc__anon_8671 (self=..., n=1032) at /usr/lib/zig/std/mem/Allocator.zig:178
#6  0x00007ffff7f877a1 in root.internal_malloc (len=1024, zeroed=false) at root.zig:12
#7  0x00007ffff7f876fb in root.malloc (len=1024) at root.zig:28
#8  0x00007ffff7967924 in __GI__IO_file_doallocate (fp=0x7ffff7ad15c0 <_IO_2_1_stdout_>) at filedoalloc.c:101
#9  0x00007ffff7977134 in __GI__IO_doallocbuf (fp=0x7ffff7ad15c0 <_IO_2_1_stdout_>) at /usr/src/debug/glibc/glibc/libio/libioP.h:1041
#10 __GI__IO_doallocbuf (fp=fp@entry=0x7ffff7ad15c0 <_IO_2_1_stdout_>) at genops.c:368
#11 0x00007ffff7975178 in _IO_new_file_overflow (f=0x7ffff7ad15c0 <_IO_2_1_stdout_>, ch=-1) at fileops.c:746
#12 0x00007ffff7975c98 in _IO_new_file_xsputn (f=0x7ffff7ad15c0 <_IO_2_1_stdout_>, data=<optimized out>, n=25) at /usr/src/debug/glibc/glibc/libio/libioP.h:1041
#13 _IO_new_file_xsputn (f=0x7ffff7ad15c0 <_IO_2_1_stdout_>, data=<optimized out>, n=25) at fileops.c:1198
#14 0x00007ffff7942709 in __printf_buffer_flush_to_file (buf=buf@entry=0x7ffffffd7e80) at ../libio/libioP.h:1041
#15 0x00007ffff79427cc in __printf_buffer_to_file_done (buf=buf@entry=0x7ffffffd7e80) at printf_buffer_to_file.c:120
#16 0x00007ffff794e1ec in __vfprintf_internal (s=0x7ffff7ad15c0 <_IO_2_1_stdout_>, format=0x55555555d11e "about to run thread %zd...\n", ap=ap@entry=0x7ffffffd7f80, mode_flags=mode_flags@entry=0) at vfprintf-internal.c:1545
#17 0x00007ffff7941eb3 in __printf (format=<optimized out>) at printf.c:33
#18 0x0000555555556e82 in runTest<NewDeleteAllocatorForTest> (startupParams=0x7ffffffd8a30) at allocator_tester.cpp:82
#19 0x00005555555569f5 in main (argc=2, argv=0x7fffffffd7a8) at allocator_tester.cpp:141
Dump of assembler code for function heap.SmpAllocator.alloc:
   0x00007ffff7f89c20 <+0>:	push   rbp
   0x00007ffff7f89c21 <+1>:	mov    rbp,rsp
   0x00007ffff7f89c24 <+4>:	sub    rsp,0x120
   0x00007ffff7f89c2b <+11>:	mov    eax,ecx
   0x00007ffff7f89c2d <+13>:	mov    QWORD PTR [rbp-0x88],rdx
   0x00007ffff7f89c34 <+20>:	mov    rcx,rsi
   0x00007ffff7f89c37 <+23>:	mov    rsi,QWORD PTR [rbp-0x88]
   0x00007ffff7f89c3e <+30>:	mov    QWORD PTR [rbp-0x80],rdi
   0x00007ffff7f89c42 <+34>:	mov    BYTE PTR [rbp-0x71],al
   0x00007ffff7f89c45 <+37>:	mov    QWORD PTR [rbp-0x68],rcx
   0x00007ffff7f89c49 <+41>:	mov    QWORD PTR [rbp-0x60],rsi
   0x00007ffff7f89c4d <+45>:	mov    cl,al
   0x00007ffff7f89c4f <+47>:	and    cl,0x3f
   0x00007ffff7f89c52 <+50>:	mov    BYTE PTR [rbp-0x51],cl
   0x00007ffff7f89c55 <+53>:	mov    QWORD PTR [rbp-0x50],r8
   0x00007ffff7f89c59 <+57>:	movzx  edx,al
   0x00007ffff7f89c5c <+60>:	call   0x7ffff7f8a140 <heap.SmpAllocator.sizeClassIndex>
   0x00007ffff7f89c61 <+65>:	mov    QWORD PTR [rbp-0x70],rax
   0x00007ffff7f89c65 <+69>:	mov    QWORD PTR [rbp-0x48],rax
   0x00007ffff7f89c69 <+73>:	cmp    rax,0xd
   0x00007ffff7f89c6d <+77>:	jae    0x7ffff7f89c91 <heap.SmpAllocator.alloc+113>
   0x00007ffff7f89c6f <+79>:	jmp    0x7ffff7f89cb0 <heap.SmpAllocator.alloc+144>
   0x00007ffff7f89c71 <+81>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89c75 <+85>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89c79 <+89>:	call   0x7ffff7f8a200 <heap.SmpAllocator.slotSize>
   0x00007ffff7f89c7e <+94>:	mov    QWORD PTR [rbp-0x90],rax
   0x00007ffff7f89c85 <+101>:	mov    QWORD PTR [rbp-0x40],rax
   0x00007ffff7f89c89 <+105>:	cmp    rax,0x0
   0x00007ffff7f89c8d <+109>:	jne    0x7ffff7f89ce9 <heap.SmpAllocator.alloc+201>
   0x00007ffff7f89c8f <+111>:	jmp    0x7ffff7f89ceb <heap.SmpAllocator.alloc+203>
   0x00007ffff7f89c91 <+113>:	mov    rsi,QWORD PTR [rbp-0x88]
   0x00007ffff7f89c98 <+120>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89c9c <+124>:	mov    al,BYTE PTR [rbp-0x71]
   0x00007ffff7f89c9f <+127>:	movzx  edx,al
   0x00007ffff7f89ca2 <+130>:	call   0x7ffff7f889a0 <heap.PageAllocator.map>
   0x00007ffff7f89ca7 <+135>:	add    rsp,0x120
   0x00007ffff7f89cae <+142>:	pop    rbp
   0x00007ffff7f89caf <+143>:	ret
   0x00007ffff7f89cb0 <+144>:	jmp    0x7ffff7f89c71 <heap.SmpAllocator.alloc+81>
   0x00007ffff7f89cb2 <+146>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cb6 <+150>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89cbd <+157>:	mov    eax,0x10000
   0x00007ffff7f89cc2 <+162>:	xor    edx,edx
   0x00007ffff7f89cc4 <+164>:	div    rcx
   0x00007ffff7f89cc7 <+167>:	cmp    rdx,0x0
   0x00007ffff7f89ccb <+171>:	sete   al
   0x00007ffff7f89cce <+174>:	movzx  esi,al
   0x00007ffff7f89cd1 <+177>:	call   0x7ffff7ef2790 <debug.assert>
   0x00007ffff7f89cd6 <+182>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cda <+186>:	mov    BYTE PTR [rbp-0x31],0x0
   0x00007ffff7f89cde <+190>:	call   0x7ffff7f8a260 <heap.SmpAllocator.Thread.lock>
   0x00007ffff7f89ce3 <+195>:	mov    QWORD PTR [rbp-0x30],rax
   0x00007ffff7f89ce7 <+199>:	jmp    0x7ffff7f89cf4 <heap.SmpAllocator.alloc+212>
   0x00007ffff7f89ce9 <+201>:	jmp    0x7ffff7f89cb2 <heap.SmpAllocator.alloc+146>
   0x00007ffff7f89ceb <+203>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cef <+207>:	call   0x7ffff7f10e70 <debug.FullPanic((function 'defaultPanic')).divideByZero>
   0x00007ffff7f89cf4 <+212>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89cf8 <+216>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89cfc <+220>:	add    rcx,0x68
   0x00007ffff7f89d00 <+224>:	mov    QWORD PTR [rbp-0x98],rcx
   0x00007ffff7f89d07 <+231>:	cmp    rax,0xd
   0x00007ffff7f89d0b <+235>:	jb     0x7ffff7f89d33 <heap.SmpAllocator.alloc+275>
   0x00007ffff7f89d0d <+237>:	jmp    0x7ffff7f89d35 <heap.SmpAllocator.alloc+277>
   0x00007ffff7f89d0f <+239>:	jmp    0x7ffff7f89cf4 <heap.SmpAllocator.alloc+212>
   0x00007ffff7f89d11 <+241>:	mov    rax,QWORD PTR [rbp-0x98]
   0x00007ffff7f89d18 <+248>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d1c <+252>:	mov    rax,QWORD PTR [rax+rcx*8]
   0x00007ffff7f89d20 <+256>:	mov    QWORD PTR [rbp-0xa0],rax
   0x00007ffff7f89d27 <+263>:	mov    QWORD PTR [rbp-0x28],rax
   0x00007ffff7f89d2b <+267>:	cmp    rax,0x0
   0x00007ffff7f89d2f <+271>:	jne    0x7ffff7f89d65 <heap.SmpAllocator.alloc+325>
   0x00007ffff7f89d31 <+273>:	jmp    0x7ffff7f89d74 <heap.SmpAllocator.alloc+340>
   0x00007ffff7f89d33 <+275>:	jmp    0x7ffff7f89d11 <heap.SmpAllocator.alloc+241>
   0x00007ffff7f89d35 <+277>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d39 <+281>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89d3d <+285>:	mov    edx,0xd
   0x00007ffff7f89d42 <+290>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89d47 <+295>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d4b <+299>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89d4f <+303>:	mov    QWORD PTR [rbp-0xa8],rcx
   0x00007ffff7f89d56 <+310>:	cmp    rax,0xd
   0x00007ffff7f89d5a <+314>:	jb     0x7ffff7f89e37 <heap.SmpAllocator.alloc+535>
   0x00007ffff7f89d60 <+320>:	jmp    0x7ffff7f89e39 <heap.SmpAllocator.alloc+537>
   0x00007ffff7f89d65 <+325>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d6c <+332>:	cmp    rax,0x0
   0x00007ffff7f89d70 <+336>:	jne    0x7ffff7f89d89 <heap.SmpAllocator.alloc+361>
   0x00007ffff7f89d72 <+338>:	jmp    0x7ffff7f89d8b <heap.SmpAllocator.alloc+363>
   0x00007ffff7f89d74 <+340>:	jmp    0x7ffff7f89d47 <heap.SmpAllocator.alloc+295>
   0x00007ffff7f89d76 <+342>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d7d <+349>:	and    rax,0x7
   0x00007ffff7f89d81 <+353>:	cmp    rax,0x0
   0x00007ffff7f89d85 <+357>:	je     0x7ffff7f89dba <heap.SmpAllocator.alloc+410>
   0x00007ffff7f89d87 <+359>:	jmp    0x7ffff7f89dbc <heap.SmpAllocator.alloc+412>
   0x00007ffff7f89d89 <+361>:	jmp    0x7ffff7f89d76 <heap.SmpAllocator.alloc+342>
   0x00007ffff7f89d8b <+363>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89d8f <+367>:	call   0x7ffff7efa8d0 <debug.FullPanic((function 'defaultPanic')).castToNull>
   0x00007ffff7f89d94 <+372>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d98 <+376>:	mov    rcx,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d9f <+383>:	mov    QWORD PTR [rbp-0x20],rcx
   0x00007ffff7f89da3 <+387>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89da7 <+391>:	add    rcx,0x68
   0x00007ffff7f89dab <+395>:	mov    QWORD PTR [rbp-0xb0],rcx
   0x00007ffff7f89db2 <+402>:	cmp    rax,0xd
   0x00007ffff7f89db6 <+406>:	jb     0x7ffff7f89dfb <heap.SmpAllocator.alloc+475>
   0x00007ffff7f89db8 <+408>:	jmp    0x7ffff7f89dfd <heap.SmpAllocator.alloc+477>
   0x00007ffff7f89dba <+410>:	jmp    0x7ffff7f89d94 <heap.SmpAllocator.alloc+372>
   0x00007ffff7f89dbc <+412>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89dc0 <+416>:	call   0x7ffff7ef5d30 <debug.FullPanic((function 'defaultPanic')).incorrectAlignment>
   0x00007ffff7f89dc5 <+421>:	mov    rdx,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89dcc <+428>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89dd0 <+432>:	mov    rax,QWORD PTR [rbp-0xb0]
   0x00007ffff7f89dd7 <+439>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89ddb <+443>:	mov    rdx,QWORD PTR [rdx]
   0x00007ffff7f89dde <+446>:	mov    QWORD PTR [rax+rcx*8],rdx
   0x00007ffff7f89de2 <+450>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89de6 <+454>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89deb <+459>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89df2 <+466>:	add    rsp,0x120
   0x00007ffff7f89df9 <+473>:	pop    rbp
   0x00007ffff7f89dfa <+474>:	ret
   0x00007ffff7f89dfb <+475>:	jmp    0x7ffff7f89dc5 <heap.SmpAllocator.alloc+421>
   0x00007ffff7f89dfd <+477>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e01 <+481>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89e05 <+485>:	mov    edx,0xd
   0x00007ffff7f89e0a <+490>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89e0f <+495>:	mov    rax,QWORD PTR [rbp-0xa8]
   0x00007ffff7f89e16 <+502>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e1a <+506>:	mov    rax,QWORD PTR [rax+rcx*8]
   0x00007ffff7f89e1e <+510>:	mov    QWORD PTR [rbp-0xb8],rax
   0x00007ffff7f89e25 <+517>:	mov    QWORD PTR [rbp-0x18],rax
   0x00007ffff7f89e29 <+521>:	and    rax,0xffff
   0x00007ffff7f89e2f <+527>:	cmp    rax,0x0
   0x00007ffff7f89e33 <+531>:	jne    0x7ffff7f89e5a <heap.SmpAllocator.alloc+570>
   0x00007ffff7f89e35 <+533>:	jmp    0x7ffff7f89e71 <heap.SmpAllocator.alloc+593>
   0x00007ffff7f89e37 <+535>:	jmp    0x7ffff7f89e0f <heap.SmpAllocator.alloc+495>
   0x00007ffff7f89e39 <+537>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e3d <+541>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89e41 <+545>:	mov    edx,0xd
   0x00007ffff7f89e46 <+550>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89e4b <+555>:	cmp    BYTE PTR [rbp-0x31],0x1
   0x00007ffff7f89e4f <+559>:	jae    0x7ffff7f89f42 <heap.SmpAllocator.alloc+802>
   0x00007ffff7f89e55 <+565>:	jmp    0x7ffff7f89f70 <heap.SmpAllocator.alloc+848>
   0x00007ffff7f89e5a <+570>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e5e <+574>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89e62 <+578>:	mov    QWORD PTR [rbp-0xc0],rcx
   0x00007ffff7f89e69 <+585>:	cmp    rax,0xd
   0x00007ffff7f89e6d <+589>:	jb     0x7ffff7f89eab <heap.SmpAllocator.alloc+651>
   0x00007ffff7f89e6f <+591>:	jmp    0x7ffff7f89ead <heap.SmpAllocator.alloc+653>
   0x00007ffff7f89e71 <+593>:	jmp    0x7ffff7f89e4b <heap.SmpAllocator.alloc+555>
   0x00007ffff7f89e73 <+595>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89e7a <+602>:	mov    rax,QWORD PTR [rbp-0xb8]
   0x00007ffff7f89e81 <+609>:	mov    rdx,QWORD PTR [rbp-0xc0]
   0x00007ffff7f89e88 <+616>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e8c <+620>:	shl    rsi,0x3
   0x00007ffff7f89e90 <+624>:	add    rdx,rsi
   0x00007ffff7f89e93 <+627>:	mov    QWORD PTR [rbp-0xd0],rdx
   0x00007ffff7f89e9a <+634>:	add    rax,rcx
   0x00007ffff7f89e9d <+637>:	mov    QWORD PTR [rbp-0xc8],rax
   0x00007ffff7f89ea4 <+644>:	setb   al
   0x00007ffff7f89ea7 <+647>:	jb     0x7ffff7f89ebf <heap.SmpAllocator.alloc+671>
   0x00007ffff7f89ea9 <+649>:	jmp    0x7ffff7f89ec8 <heap.SmpAllocator.alloc+680>
   0x00007ffff7f89eab <+651>:	jmp    0x7ffff7f89e73 <heap.SmpAllocator.alloc+595>
   0x00007ffff7f89ead <+653>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89eb1 <+657>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89eb5 <+661>:	mov    edx,0xd
   0x00007ffff7f89eba <+666>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89ebf <+671>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89ec3 <+675>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f89ec8 <+680>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89ecc <+684>:	mov    rax,QWORD PTR [rbp-0xd0]
   0x00007ffff7f89ed3 <+691>:	mov    rcx,QWORD PTR [rbp-0xc8]
   0x00007ffff7f89eda <+698>:	mov    QWORD PTR [rax],rcx
   0x00007ffff7f89edd <+701>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89ee1 <+705>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89ee6 <+710>:	mov    rax,QWORD PTR [rbp-0xb8]
   0x00007ffff7f89eed <+717>:	add    rsp,0x120
   0x00007ffff7f89ef4 <+724>:	pop    rbp
   0x00007ffff7f89ef5 <+725>:	ret
   0x00007ffff7f89ef6 <+726>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89efa <+730>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89efe <+734>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89f03 <+739>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f07 <+743>:	call   0x7ffff7f8a410 <heap.SmpAllocator.getCpuCount>
   0x00007ffff7f89f0c <+748>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f10 <+752>:	mov    ecx,eax
   0x00007ffff7f89f12 <+754>:	mov    DWORD PTR [rbp-0xd4],ecx
   0x00007ffff7f89f18 <+760>:	mov    DWORD PTR [rbp-0x8],eax
   0x00007ffff7f89f1b <+763>:	test   eax,eax
   0x00007ffff7f89f1d <+765>:	setne  al
   0x00007ffff7f89f20 <+768>:	movzx  esi,al
   0x00007ffff7f89f23 <+771>:	call   0x7ffff7ef2790 <debug.assert>
   0x00007ffff7f89f28 <+776>:	lea    rdi,[rip+0x27bf1]        # 0x7ffff7fb1b20
   0x00007ffff7f89f2f <+783>:	call   0x7ffff7fae630 <__tls_get_addr@plt>
   0x00007ffff7f89f34 <+788>:	mov    eax,DWORD PTR [rax+0x10]
   0x00007ffff7f89f3a <+794>:	mov    DWORD PTR [rbp-0x4],eax
   0x00007ffff7f89f3d <+797>:	jmp    0x7ffff7f8a046 <heap.SmpAllocator.alloc+1062>
   0x00007ffff7f89f42 <+802>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f46 <+806>:	mov    esi,0x10000
   0x00007ffff7f89f4b <+811>:	call   0x7ffff7f18cd0 <mem.Alignment.fromByteUnits>
   0x00007ffff7f89f50 <+816>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f54 <+820>:	movzx  edx,al
   0x00007ffff7f89f57 <+823>:	mov    esi,0x10000
   0x00007ffff7f89f5c <+828>:	call   0x7ffff7f889a0 <heap.PageAllocator.map>
   0x00007ffff7f89f61 <+833>:	mov    QWORD PTR [rbp-0xe0],rax
   0x00007ffff7f89f68 <+840>:	cmp    rax,0x0
   0x00007ffff7f89f6c <+844>:	jne    0x7ffff7f89f9b <heap.SmpAllocator.alloc+891>
   0x00007ffff7f89f6e <+846>:	jmp    0x7ffff7f89fab <heap.SmpAllocator.alloc+907>
   0x00007ffff7f89f70 <+848>:	jmp    0x7ffff7f89ef6 <heap.SmpAllocator.alloc+726>
   0x00007ffff7f89f72 <+850>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89f76 <+854>:	mov    rcx,QWORD PTR [rbp-0xf8]
   0x00007ffff7f89f7d <+861>:	mov    QWORD PTR [rbp-0xf0],rcx
   0x00007ffff7f89f84 <+868>:	mov    QWORD PTR [rbp-0x10],rcx
   0x00007ffff7f89f88 <+872>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89f8c <+876>:	mov    QWORD PTR [rbp-0xe8],rcx
   0x00007ffff7f89f93 <+883>:	cmp    rax,0xd
   0x00007ffff7f89f97 <+887>:	jb     0x7ffff7f89ffb <heap.SmpAllocator.alloc+987>
   0x00007ffff7f89f99 <+889>:	jmp    0x7ffff7f89ffd <heap.SmpAllocator.alloc+989>
   0x00007ffff7f89f9b <+891>:	mov    rax,QWORD PTR [rbp-0xe0]
   0x00007ffff7f89fa2 <+898>:	mov    QWORD PTR [rbp-0xf8],rax
   0x00007ffff7f89fa9 <+905>:	jmp    0x7ffff7f89f72 <heap.SmpAllocator.alloc+850>
   0x00007ffff7f89fab <+907>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89faf <+911>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89fb3 <+915>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89fb8 <+920>:	xor    eax,eax
   0x00007ffff7f89fba <+922>:	add    rsp,0x120
   0x00007ffff7f89fc1 <+929>:	pop    rbp
   0x00007ffff7f89fc2 <+930>:	ret
   0x00007ffff7f89fc3 <+931>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89fca <+938>:	mov    rax,QWORD PTR [rbp-0xf0]
   0x00007ffff7f89fd1 <+945>:	mov    rdx,QWORD PTR [rbp-0xe8]
   0x00007ffff7f89fd8 <+952>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89fdc <+956>:	shl    rsi,0x3
   0x00007ffff7f89fe0 <+960>:	add    rdx,rsi
   0x00007ffff7f89fe3 <+963>:	mov    QWORD PTR [rbp-0x108],rdx
   0x00007ffff7f89fea <+970>:	add    rax,rcx
   0x00007ffff7f89fed <+973>:	mov    QWORD PTR [rbp-0x100],rax
   0x00007ffff7f89ff4 <+980>:	setb   al
   0x00007ffff7f89ff7 <+983>:	jb     0x7ffff7f8a00f <heap.SmpAllocator.alloc+1007>
   0x00007ffff7f89ff9 <+985>:	jmp    0x7ffff7f8a018 <heap.SmpAllocator.alloc+1016>
   0x00007ffff7f89ffb <+987>:	jmp    0x7ffff7f89fc3 <heap.SmpAllocator.alloc+931>
   0x00007ffff7f89ffd <+989>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f8a001 <+993>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a005 <+997>:	mov    edx,0xd
   0x00007ffff7f8a00a <+1002>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f8a00f <+1007>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a013 <+1011>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a018 <+1016>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a01c <+1020>:	mov    rax,QWORD PTR [rbp-0x108]
   0x00007ffff7f8a023 <+1027>:	mov    rcx,QWORD PTR [rbp-0x100]
   0x00007ffff7f8a02a <+1034>:	mov    QWORD PTR [rax],rcx
   0x00007ffff7f8a02d <+1037>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f8a031 <+1041>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f8a036 <+1046>:	mov    rax,QWORD PTR [rbp-0xf0]
   0x00007ffff7f8a03d <+1053>:	add    rsp,0x120
   0x00007ffff7f8a044 <+1060>:	pop    rbp
   0x00007ffff7f8a045 <+1061>:	ret
   0x00007ffff7f8a046 <+1062>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a049 <+1065>:	add    eax,0x1
   0x00007ffff7f8a04c <+1068>:	mov    DWORD PTR [rbp-0x10c],eax
   0x00007ffff7f8a052 <+1074>:	setb   al
   0x00007ffff7f8a055 <+1077>:	jb     0x7ffff7f8a059 <heap.SmpAllocator.alloc+1081>
   0x00007ffff7f8a057 <+1079>:	jmp    0x7ffff7f8a062 <heap.SmpAllocator.alloc+1090>
   0x00007ffff7f8a059 <+1081>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a05d <+1085>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a062 <+1090>:	mov    eax,DWORD PTR [rbp-0xd4]
   0x00007ffff7f8a068 <+1096>:	cmp    eax,0x0
   0x00007ffff7f8a06b <+1099>:	jne    0x7ffff7f8a096 <heap.SmpAllocator.alloc+1142>
   0x00007ffff7f8a06d <+1101>:	jmp    0x7ffff7f8a098 <heap.SmpAllocator.alloc+1144>
   0x00007ffff7f8a06f <+1103>:	mov    ecx,DWORD PTR [rbp-0xd4]
   0x00007ffff7f8a075 <+1109>:	mov    eax,DWORD PTR [rbp-0x10c]
   0x00007ffff7f8a07b <+1115>:	xor    edx,edx
   0x00007ffff7f8a07d <+1117>:	div    ecx
   0x00007ffff7f8a07f <+1119>:	mov    DWORD PTR [rbp-0x4],edx
   0x00007ffff7f8a082 <+1122>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a085 <+1125>:	mov    QWORD PTR [rbp-0x118],rax
   0x00007ffff7f8a08c <+1132>:	cmp    rax,0x80
   0x00007ffff7f8a092 <+1138>:	jb     0x7ffff7f8a0d4 <heap.SmpAllocator.alloc+1204>
   0x00007ffff7f8a094 <+1140>:	jmp    0x7ffff7f8a0d6 <heap.SmpAllocator.alloc+1206>
   0x00007ffff7f8a096 <+1142>:	jmp    0x7ffff7f8a06f <heap.SmpAllocator.alloc+1103>
   0x00007ffff7f8a098 <+1144>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a09c <+1148>:	call   0x7ffff7f10e70 <debug.FullPanic((function 'defaultPanic')).divideByZero>
   0x00007ffff7f8a0a1 <+1153>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a0a5 <+1157>:	mov    rcx,QWORD PTR [rbp-0x118]
   0x00007ffff7f8a0ac <+1164>:	lea    rax,[rip+0x29fcd]        # 0x7ffff7fb4080 <heap.SmpAllocator.global>
   0x00007ffff7f8a0b3 <+1171>:	shl    rcx,0x8
   0x00007ffff7f8a0b7 <+1175>:	add    rax,rcx
   0x00007ffff7f8a0ba <+1178>:	mov    QWORD PTR [rbp-0x30],rax
   0x00007ffff7f8a0be <+1182>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f8a0c2 <+1186>:	add    rsi,0xd0
   0x00007ffff7f8a0c9 <+1193>:	call   0x7ffff7f8a4e0 <Thread.Mutex.tryLock>
   0x00007ffff7f8a0ce <+1198>:	test   al,0x1
   0x00007ffff7f8a0d0 <+1200>:	jne    0x7ffff7f8a0f0 <heap.SmpAllocator.alloc+1232>
   0x00007ffff7f8a0d2 <+1202>:	jmp    0x7ffff7f8a125 <heap.SmpAllocator.alloc+1285>
   0x00007ffff7f8a0d4 <+1204>:	jmp    0x7ffff7f8a0a1 <heap.SmpAllocator.alloc+1153>
   0x00007ffff7f8a0d6 <+1206>:	mov    rsi,QWORD PTR [rbp-0x118]
   0x00007ffff7f8a0dd <+1213>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a0e1 <+1217>:	mov    edx,0x80
   0x00007ffff7f8a0e6 <+1222>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f8a0eb <+1227>:	jmp    0x7ffff7f8a046 <heap.SmpAllocator.alloc+1062>
=> 0x00007ffff7f8a0f0 <+1232>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a0f3 <+1235>:	mov    DWORD PTR [rbp-0x120],eax
   0x00007ffff7f8a0f9 <+1241>:	lea    rdi,[rip+0x27a20]        # 0x7ffff7fb1b20
   0x00007ffff7f8a100 <+1248>:	call   0x7ffff7fae630 <__tls_get_addr@plt>
   0x00007ffff7f8a105 <+1253>:	mov    ecx,DWORD PTR [rbp-0x120]
   0x00007ffff7f8a10b <+1259>:	mov    DWORD PTR [rax+0x10],ecx
   0x00007ffff7f8a111 <+1265>:	mov    al,BYTE PTR [rbp-0x31]
   0x00007ffff7f8a114 <+1268>:	add    al,0x1
   0x00007ffff7f8a116 <+1270>:	mov    BYTE PTR [rbp-0x119],al
   0x00007ffff7f8a11c <+1276>:	setb   al
   0x00007ffff7f8a11f <+1279>:	test   al,0x1
   0x00007ffff7f8a121 <+1281>:	jne    0x7ffff7f8a127 <heap.SmpAllocator.alloc+1287>
   0x00007ffff7f8a123 <+1283>:	jmp    0x7ffff7f8a130 <heap.SmpAllocator.alloc+1296>
   0x00007ffff7f8a125 <+1285>:	jmp    0x7ffff7f8a0eb <heap.SmpAllocator.alloc+1227>
   0x00007ffff7f8a127 <+1287>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a12b <+1291>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a130 <+1296>:	mov    al,BYTE PTR [rbp-0x119]
   0x00007ffff7f8a136 <+1302>:	mov    BYTE PTR [rbp-0x31],al
   0x00007ffff7f8a139 <+1305>:	jmp    0x7ffff7f89d0f <heap.SmpAllocator.alloc+239>
End of assembler dump.
#0  heap.SmpAllocator.alloc (context=0x0, len=1032, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
#1  0x00007ffff7f346ba in mem.Allocator.rawAlloc () at /usr/lib/zig/std/mem/Allocator.zig:129
#2  mem.Allocator.allocBytesWithAlignment__anon_14706 (self=..., byte_count=1032, return_address=140737353643937) at /usr/lib/zig/std/mem/Allocator.zig:269
#3  0x00007ffff7f26313 in mem.Allocator.allocWithSizeAndAlignment__anon_11852 (self=..., n=1032, return_address=140737353643937) at /usr/lib/zig/std/mem/Allocator.zig:260
#4  0x00007ffff7f0ec22 in mem.Allocator.allocAdvancedWithRetAddr () at /usr/lib/zig/std/mem/Allocator.zig:254
#5  mem.Allocator.alloc__anon_8671 (self=..., n=1032) at /usr/lib/zig/std/mem/Allocator.zig:178
#6  0x00007ffff7f877a1 in root.internal_malloc (len=1024, zeroed=false) at root.zig:12
#7  0x00007ffff7f876fb in root.malloc (len=1024) at root.zig:28
#8  0x00007ffff7967924 in __GI__IO_file_doallocate (fp=0x7ffff7ad15c0 <_IO_2_1_stdout_>) at filedoalloc.c:101
#9  0x00007ffff7977134 in __GI__IO_doallocbuf (fp=0x7ffff7ad15c0 <_IO_2_1_stdout_>) at /usr/src/debug/glibc/glibc/libio/libioP.h:1041
#10 __GI__IO_doallocbuf (fp=fp@entry=0x7ffff7ad15c0 <_IO_2_1_stdout_>) at genops.c:368
#11 0x00007ffff7975178 in _IO_new_file_overflow (f=0x7ffff7ad15c0 <_IO_2_1_stdout_>, ch=-1) at fileops.c:746
#12 0x00007ffff7975c98 in _IO_new_file_xsputn (f=0x7ffff7ad15c0 <_IO_2_1_stdout_>, data=<optimized out>, n=25) at /usr/src/debug/glibc/glibc/libio/libioP.h:1041
#13 _IO_new_file_xsputn (f=0x7ffff7ad15c0 <_IO_2_1_stdout_>, data=<optimized out>, n=25) at fileops.c:1198
#14 0x00007ffff7942709 in __printf_buffer_flush_to_file (buf=buf@entry=0x7ffffffd7e80) at ../libio/libioP.h:1041
#15 0x00007ffff79427cc in __printf_buffer_to_file_done (buf=buf@entry=0x7ffffffd7e80) at printf_buffer_to_file.c:120
#16 0x00007ffff794e1ec in __vfprintf_internal (s=0x7ffff7ad15c0 <_IO_2_1_stdout_>, format=0x55555555d11e "about to run thread %zd...\n", ap=ap@entry=0x7ffffffd7f80, mode_flags=mode_flags@entry=0) at vfprintf-internal.c:1545
#17 0x00007ffff7941eb3 in __printf (format=<optimized out>) at printf.c:33
#18 0x0000555555556e82 in runTest<NewDeleteAllocatorForTest> (startupParams=0x7ffffffd8a30) at allocator_tester.cpp:82
#19 0x00005555555569f5 in main (argc=2, argv=0x7fffffffd7a8) at allocator_tester.cpp:141
0x00007ffff7f8a0f3	168	                thread_index = index;
0x00007ffff7f8a0f9	168	                thread_index = index;
0x00007ffff7f8a100	168	                thread_index = index;
0x00007ffff7f8a105	168	                thread_index = index;
0x00007ffff7f8a10b	168	                thread_index = index;
169	                search_count += 1;
$2 = 140737352615784
$3 = 1
Hardware access (read/write) watchpoint 3: (u64)*0x7ffff7e8c778
Hardware access (read/write) watchpoint 4: (u64)*0x7ffff7e8c778
Breakpoint 5 at 0x7ffff7f8a111: file /usr/lib/zig/std/heap/SmpAllocator.zig, line 169.
Continuing.

Hardware access (read/write) watchpoint 4: (u64)*0x7ffff7e8c778

Value = 1
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Hardware access (read/write) watchpoint 4: (u64)*0x7ffff7e8c778

Value = 1
0x00007ffff7f89f3a in heap.SmpAllocator.alloc (context=0x0, len=32, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:163
163	        var index = thread_index;
Continuing.

Hardware access (read/write) watchpoint 4: (u64)*0x7ffff7e8c778

Old value = 1
New value = 2

Breakpoint 5, heap.SmpAllocator.alloc (context=0x0, len=32, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:169
169	                search_count += 1;
Continuing.

Hardware access (read/write) watchpoint 4: (u64)*0x7ffff7e8c778

Value = 2
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.
[New Thread 0x7ffff78bf6c0 (LWP 3389)]
[Switching to Thread 0x7ffff78bf6c0 (LWP 3389)]

Thread 2 "a.out" hit Breakpoint 5, heap.SmpAllocator.alloc (context=0x0, len=21, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:169
169	                search_count += 1;
Hardware access (read/write) watchpoint 6: (u64)*0x7ffff7e8c778
Continuing.

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
warning: Currently logging to gdb.c.  Turn the logging off and on to make the new setting effective.
/home/feniljain/test.gdb:17: Error in sourced command file:
No symbol "u64" in current context.
warning: Currently logging to gdb.c.  Turn the logging off and on to make the new setting effective.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[New Thread 0x7ffff78bf6c0 (LWP 3484)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff78bf6c0 (LWP 3484)]
0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Hardware access (read/write) watchpoint 1: (u64)*0x7ffff7e8c778
Error in re-setting breakpoint 1: No symbol "u64" in current context.
Error in re-setting breakpoint 1: No symbol "u64" in current context.
Error in re-setting breakpoint 1: No symbol "u64" in current context.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".

Hardware access (read/write) watchpoint 1: (u64)*0x7ffff7e8c778

Value = 0
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
warning: Currently logging to gdb.c.  Turn the logging off and on to make the new setting effective.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[New Thread 0x7ffff78bf6c0 (LWP 3531)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff78bf6c0 (LWP 3531)]
0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Hardware access (read/write) watchpoint 1: (unsigned long long)*0x7ffff7e8c778
Downloading 12.39 K source file /usr/src/debug/glibc/glibc/string/../sysdeps/x86_64/multiarch/../multiarch/memset-vec-unaligned-erms.S
[#############################################################################################################] 100% (12.39 K)                                                                                                                                
Hardware access (read/write) watchpoint 1: (unsigned long long)*0x7ffff7e8c778

Value = 0
memset () at ../sysdeps/x86_64/multiarch/../multiarch/memset-vec-unaligned-erms.S:151
151		VMOVU	%VMM(0), (%rdi)
Continuing.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".

Hardware access (read/write) watchpoint 1: (unsigned long long)*0x7ffff7e8c778

Value = 0
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Hardware access (read/write) watchpoint 1: (unsigned long long)*0x7ffff7e8c778

Value = 0
0x00007ffff7f89f3a in heap.SmpAllocator.alloc (context=0x0, len=1032, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:163
163	        var index = thread_index;
Continuing.

Hardware access (read/write) watchpoint 1: (unsigned long long)*0x7ffff7e8c778

Old value = 0
New value = 1
heap.SmpAllocator.alloc (context=0x0, len=1032, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:169
169	                search_count += 1;
  Id   Target Id                                Frame 
* 1    Thread 0x7ffff7e8c780 (LWP 3532) "a.out" heap.SmpAllocator.alloc (context=0x0, len=1032, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:169
Continuing.

Hardware access (read/write) watchpoint 1: (unsigned long long)*0x7ffff7e8c778

Value = 1
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Hardware access (read/write) watchpoint 1: (unsigned long long)*0x7ffff7e8c778

Value = 1
0x00007ffff7f89f3a in heap.SmpAllocator.alloc (context=0x0, len=32, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:163
163	        var index = thread_index;
Continuing.

Hardware access (read/write) watchpoint 1: (unsigned long long)*0x7ffff7e8c778

Old value = 1
New value = 2
heap.SmpAllocator.alloc (context=0x0, len=32, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:169
169	                search_count += 1;
Continuing.

Hardware access (read/write) watchpoint 1: (unsigned long long)*0x7ffff7e8c778

Value = 2
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
  Id   Target Id                                Frame 
* 1    Thread 0x7ffff7e8c780 (LWP 3532) "a.out" 0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
Continuing.
[New Thread 0x7ffff78bf6c0 (LWP 3538)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff78bf6c0 (LWP 3538)]
0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
  Id   Target Id                                Frame 
  1    Thread 0x7ffff7e8c780 (LWP 3532) "a.out" __syscall_cancel_arch () at ../sysdeps/unix/sysv/linux/x86_64/syscall_cancel.S:56
* 2    Thread 0x7ffff78bf6c0 (LWP 3538) "a.out" 0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
warning: Currently logging to gdb.c.  Turn the logging off and on to make the new setting effective.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[New Thread 0x7ffff78bf6c0 (LWP 4467)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff78bf6c0 (LWP 4467)]
0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Breakpoint 1 at 0x7ffff7f8a3ae: file /usr/lib/zig/std/heap/SmpAllocator.zig, line 89.
Breakpoint 2 at 0x7ffff7f8a0f0: file /usr/lib/zig/std/heap/SmpAllocator.zig, line 168.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".

Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=1032, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Continuing.

Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=32, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Continuing.
[New Thread 0x7ffff78bf6c0 (LWP 4469)]
[Switching to Thread 0x7ffff78bf6c0 (LWP 4469)]

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=21, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Continuing.

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=107, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Dump of assembler code for function heap.SmpAllocator.alloc:
   0x00007ffff7f89c20 <+0>:	push   rbp
   0x00007ffff7f89c21 <+1>:	mov    rbp,rsp
   0x00007ffff7f89c24 <+4>:	sub    rsp,0x120
   0x00007ffff7f89c2b <+11>:	mov    eax,ecx
   0x00007ffff7f89c2d <+13>:	mov    QWORD PTR [rbp-0x88],rdx
   0x00007ffff7f89c34 <+20>:	mov    rcx,rsi
   0x00007ffff7f89c37 <+23>:	mov    rsi,QWORD PTR [rbp-0x88]
   0x00007ffff7f89c3e <+30>:	mov    QWORD PTR [rbp-0x80],rdi
   0x00007ffff7f89c42 <+34>:	mov    BYTE PTR [rbp-0x71],al
   0x00007ffff7f89c45 <+37>:	mov    QWORD PTR [rbp-0x68],rcx
   0x00007ffff7f89c49 <+41>:	mov    QWORD PTR [rbp-0x60],rsi
   0x00007ffff7f89c4d <+45>:	mov    cl,al
   0x00007ffff7f89c4f <+47>:	and    cl,0x3f
   0x00007ffff7f89c52 <+50>:	mov    BYTE PTR [rbp-0x51],cl
   0x00007ffff7f89c55 <+53>:	mov    QWORD PTR [rbp-0x50],r8
   0x00007ffff7f89c59 <+57>:	movzx  edx,al
   0x00007ffff7f89c5c <+60>:	call   0x7ffff7f8a140 <heap.SmpAllocator.sizeClassIndex>
   0x00007ffff7f89c61 <+65>:	mov    QWORD PTR [rbp-0x70],rax
   0x00007ffff7f89c65 <+69>:	mov    QWORD PTR [rbp-0x48],rax
   0x00007ffff7f89c69 <+73>:	cmp    rax,0xd
   0x00007ffff7f89c6d <+77>:	jae    0x7ffff7f89c91 <heap.SmpAllocator.alloc+113>
   0x00007ffff7f89c6f <+79>:	jmp    0x7ffff7f89cb0 <heap.SmpAllocator.alloc+144>
   0x00007ffff7f89c71 <+81>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89c75 <+85>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89c79 <+89>:	call   0x7ffff7f8a200 <heap.SmpAllocator.slotSize>
   0x00007ffff7f89c7e <+94>:	mov    QWORD PTR [rbp-0x90],rax
   0x00007ffff7f89c85 <+101>:	mov    QWORD PTR [rbp-0x40],rax
   0x00007ffff7f89c89 <+105>:	cmp    rax,0x0
   0x00007ffff7f89c8d <+109>:	jne    0x7ffff7f89ce9 <heap.SmpAllocator.alloc+201>
   0x00007ffff7f89c8f <+111>:	jmp    0x7ffff7f89ceb <heap.SmpAllocator.alloc+203>
   0x00007ffff7f89c91 <+113>:	mov    rsi,QWORD PTR [rbp-0x88]
   0x00007ffff7f89c98 <+120>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89c9c <+124>:	mov    al,BYTE PTR [rbp-0x71]
   0x00007ffff7f89c9f <+127>:	movzx  edx,al
   0x00007ffff7f89ca2 <+130>:	call   0x7ffff7f889a0 <heap.PageAllocator.map>
   0x00007ffff7f89ca7 <+135>:	add    rsp,0x120
   0x00007ffff7f89cae <+142>:	pop    rbp
   0x00007ffff7f89caf <+143>:	ret
   0x00007ffff7f89cb0 <+144>:	jmp    0x7ffff7f89c71 <heap.SmpAllocator.alloc+81>
   0x00007ffff7f89cb2 <+146>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cb6 <+150>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89cbd <+157>:	mov    eax,0x10000
   0x00007ffff7f89cc2 <+162>:	xor    edx,edx
   0x00007ffff7f89cc4 <+164>:	div    rcx
   0x00007ffff7f89cc7 <+167>:	cmp    rdx,0x0
   0x00007ffff7f89ccb <+171>:	sete   al
   0x00007ffff7f89cce <+174>:	movzx  esi,al
   0x00007ffff7f89cd1 <+177>:	call   0x7ffff7ef2790 <debug.assert>
   0x00007ffff7f89cd6 <+182>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cda <+186>:	mov    BYTE PTR [rbp-0x31],0x0
   0x00007ffff7f89cde <+190>:	call   0x7ffff7f8a260 <heap.SmpAllocator.Thread.lock>
   0x00007ffff7f89ce3 <+195>:	mov    QWORD PTR [rbp-0x30],rax
   0x00007ffff7f89ce7 <+199>:	jmp    0x7ffff7f89cf4 <heap.SmpAllocator.alloc+212>
   0x00007ffff7f89ce9 <+201>:	jmp    0x7ffff7f89cb2 <heap.SmpAllocator.alloc+146>
   0x00007ffff7f89ceb <+203>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cef <+207>:	call   0x7ffff7f10e70 <debug.FullPanic((function 'defaultPanic')).divideByZero>
   0x00007ffff7f89cf4 <+212>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89cf8 <+216>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89cfc <+220>:	add    rcx,0x68
   0x00007ffff7f89d00 <+224>:	mov    QWORD PTR [rbp-0x98],rcx
   0x00007ffff7f89d07 <+231>:	cmp    rax,0xd
   0x00007ffff7f89d0b <+235>:	jb     0x7ffff7f89d33 <heap.SmpAllocator.alloc+275>
   0x00007ffff7f89d0d <+237>:	jmp    0x7ffff7f89d35 <heap.SmpAllocator.alloc+277>
   0x00007ffff7f89d0f <+239>:	jmp    0x7ffff7f89cf4 <heap.SmpAllocator.alloc+212>
   0x00007ffff7f89d11 <+241>:	mov    rax,QWORD PTR [rbp-0x98]
   0x00007ffff7f89d18 <+248>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d1c <+252>:	mov    rax,QWORD PTR [rax+rcx*8]
   0x00007ffff7f89d20 <+256>:	mov    QWORD PTR [rbp-0xa0],rax
   0x00007ffff7f89d27 <+263>:	mov    QWORD PTR [rbp-0x28],rax
   0x00007ffff7f89d2b <+267>:	cmp    rax,0x0
   0x00007ffff7f89d2f <+271>:	jne    0x7ffff7f89d65 <heap.SmpAllocator.alloc+325>
   0x00007ffff7f89d31 <+273>:	jmp    0x7ffff7f89d74 <heap.SmpAllocator.alloc+340>
   0x00007ffff7f89d33 <+275>:	jmp    0x7ffff7f89d11 <heap.SmpAllocator.alloc+241>
   0x00007ffff7f89d35 <+277>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d39 <+281>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89d3d <+285>:	mov    edx,0xd
   0x00007ffff7f89d42 <+290>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89d47 <+295>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d4b <+299>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89d4f <+303>:	mov    QWORD PTR [rbp-0xa8],rcx
   0x00007ffff7f89d56 <+310>:	cmp    rax,0xd
   0x00007ffff7f89d5a <+314>:	jb     0x7ffff7f89e37 <heap.SmpAllocator.alloc+535>
   0x00007ffff7f89d60 <+320>:	jmp    0x7ffff7f89e39 <heap.SmpAllocator.alloc+537>
   0x00007ffff7f89d65 <+325>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d6c <+332>:	cmp    rax,0x0
   0x00007ffff7f89d70 <+336>:	jne    0x7ffff7f89d89 <heap.SmpAllocator.alloc+361>
   0x00007ffff7f89d72 <+338>:	jmp    0x7ffff7f89d8b <heap.SmpAllocator.alloc+363>
   0x00007ffff7f89d74 <+340>:	jmp    0x7ffff7f89d47 <heap.SmpAllocator.alloc+295>
   0x00007ffff7f89d76 <+342>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d7d <+349>:	and    rax,0x7
   0x00007ffff7f89d81 <+353>:	cmp    rax,0x0
   0x00007ffff7f89d85 <+357>:	je     0x7ffff7f89dba <heap.SmpAllocator.alloc+410>
   0x00007ffff7f89d87 <+359>:	jmp    0x7ffff7f89dbc <heap.SmpAllocator.alloc+412>
   0x00007ffff7f89d89 <+361>:	jmp    0x7ffff7f89d76 <heap.SmpAllocator.alloc+342>
   0x00007ffff7f89d8b <+363>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89d8f <+367>:	call   0x7ffff7efa8d0 <debug.FullPanic((function 'defaultPanic')).castToNull>
   0x00007ffff7f89d94 <+372>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d98 <+376>:	mov    rcx,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d9f <+383>:	mov    QWORD PTR [rbp-0x20],rcx
   0x00007ffff7f89da3 <+387>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89da7 <+391>:	add    rcx,0x68
   0x00007ffff7f89dab <+395>:	mov    QWORD PTR [rbp-0xb0],rcx
   0x00007ffff7f89db2 <+402>:	cmp    rax,0xd
   0x00007ffff7f89db6 <+406>:	jb     0x7ffff7f89dfb <heap.SmpAllocator.alloc+475>
   0x00007ffff7f89db8 <+408>:	jmp    0x7ffff7f89dfd <heap.SmpAllocator.alloc+477>
   0x00007ffff7f89dba <+410>:	jmp    0x7ffff7f89d94 <heap.SmpAllocator.alloc+372>
   0x00007ffff7f89dbc <+412>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89dc0 <+416>:	call   0x7ffff7ef5d30 <debug.FullPanic((function 'defaultPanic')).incorrectAlignment>
   0x00007ffff7f89dc5 <+421>:	mov    rdx,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89dcc <+428>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89dd0 <+432>:	mov    rax,QWORD PTR [rbp-0xb0]
   0x00007ffff7f89dd7 <+439>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89ddb <+443>:	mov    rdx,QWORD PTR [rdx]
   0x00007ffff7f89dde <+446>:	mov    QWORD PTR [rax+rcx*8],rdx
   0x00007ffff7f89de2 <+450>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89de6 <+454>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89deb <+459>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89df2 <+466>:	add    rsp,0x120
   0x00007ffff7f89df9 <+473>:	pop    rbp
   0x00007ffff7f89dfa <+474>:	ret
   0x00007ffff7f89dfb <+475>:	jmp    0x7ffff7f89dc5 <heap.SmpAllocator.alloc+421>
   0x00007ffff7f89dfd <+477>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e01 <+481>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89e05 <+485>:	mov    edx,0xd
   0x00007ffff7f89e0a <+490>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89e0f <+495>:	mov    rax,QWORD PTR [rbp-0xa8]
   0x00007ffff7f89e16 <+502>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e1a <+506>:	mov    rax,QWORD PTR [rax+rcx*8]
   0x00007ffff7f89e1e <+510>:	mov    QWORD PTR [rbp-0xb8],rax
   0x00007ffff7f89e25 <+517>:	mov    QWORD PTR [rbp-0x18],rax
   0x00007ffff7f89e29 <+521>:	and    rax,0xffff
   0x00007ffff7f89e2f <+527>:	cmp    rax,0x0
   0x00007ffff7f89e33 <+531>:	jne    0x7ffff7f89e5a <heap.SmpAllocator.alloc+570>
   0x00007ffff7f89e35 <+533>:	jmp    0x7ffff7f89e71 <heap.SmpAllocator.alloc+593>
   0x00007ffff7f89e37 <+535>:	jmp    0x7ffff7f89e0f <heap.SmpAllocator.alloc+495>
   0x00007ffff7f89e39 <+537>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e3d <+541>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89e41 <+545>:	mov    edx,0xd
   0x00007ffff7f89e46 <+550>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89e4b <+555>:	cmp    BYTE PTR [rbp-0x31],0x1
   0x00007ffff7f89e4f <+559>:	jae    0x7ffff7f89f42 <heap.SmpAllocator.alloc+802>
   0x00007ffff7f89e55 <+565>:	jmp    0x7ffff7f89f70 <heap.SmpAllocator.alloc+848>
   0x00007ffff7f89e5a <+570>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e5e <+574>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89e62 <+578>:	mov    QWORD PTR [rbp-0xc0],rcx
   0x00007ffff7f89e69 <+585>:	cmp    rax,0xd
   0x00007ffff7f89e6d <+589>:	jb     0x7ffff7f89eab <heap.SmpAllocator.alloc+651>
   0x00007ffff7f89e6f <+591>:	jmp    0x7ffff7f89ead <heap.SmpAllocator.alloc+653>
   0x00007ffff7f89e71 <+593>:	jmp    0x7ffff7f89e4b <heap.SmpAllocator.alloc+555>
   0x00007ffff7f89e73 <+595>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89e7a <+602>:	mov    rax,QWORD PTR [rbp-0xb8]
   0x00007ffff7f89e81 <+609>:	mov    rdx,QWORD PTR [rbp-0xc0]
   0x00007ffff7f89e88 <+616>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e8c <+620>:	shl    rsi,0x3
   0x00007ffff7f89e90 <+624>:	add    rdx,rsi
   0x00007ffff7f89e93 <+627>:	mov    QWORD PTR [rbp-0xd0],rdx
   0x00007ffff7f89e9a <+634>:	add    rax,rcx
   0x00007ffff7f89e9d <+637>:	mov    QWORD PTR [rbp-0xc8],rax
   0x00007ffff7f89ea4 <+644>:	setb   al
   0x00007ffff7f89ea7 <+647>:	jb     0x7ffff7f89ebf <heap.SmpAllocator.alloc+671>
   0x00007ffff7f89ea9 <+649>:	jmp    0x7ffff7f89ec8 <heap.SmpAllocator.alloc+680>
   0x00007ffff7f89eab <+651>:	jmp    0x7ffff7f89e73 <heap.SmpAllocator.alloc+595>
   0x00007ffff7f89ead <+653>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89eb1 <+657>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89eb5 <+661>:	mov    edx,0xd
   0x00007ffff7f89eba <+666>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89ebf <+671>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89ec3 <+675>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f89ec8 <+680>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89ecc <+684>:	mov    rax,QWORD PTR [rbp-0xd0]
   0x00007ffff7f89ed3 <+691>:	mov    rcx,QWORD PTR [rbp-0xc8]
   0x00007ffff7f89eda <+698>:	mov    QWORD PTR [rax],rcx
   0x00007ffff7f89edd <+701>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89ee1 <+705>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89ee6 <+710>:	mov    rax,QWORD PTR [rbp-0xb8]
   0x00007ffff7f89eed <+717>:	add    rsp,0x120
   0x00007ffff7f89ef4 <+724>:	pop    rbp
   0x00007ffff7f89ef5 <+725>:	ret
   0x00007ffff7f89ef6 <+726>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89efa <+730>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89efe <+734>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89f03 <+739>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f07 <+743>:	call   0x7ffff7f8a410 <heap.SmpAllocator.getCpuCount>
   0x00007ffff7f89f0c <+748>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f10 <+752>:	mov    ecx,eax
   0x00007ffff7f89f12 <+754>:	mov    DWORD PTR [rbp-0xd4],ecx
   0x00007ffff7f89f18 <+760>:	mov    DWORD PTR [rbp-0x8],eax
   0x00007ffff7f89f1b <+763>:	test   eax,eax
   0x00007ffff7f89f1d <+765>:	setne  al
   0x00007ffff7f89f20 <+768>:	movzx  esi,al
   0x00007ffff7f89f23 <+771>:	call   0x7ffff7ef2790 <debug.assert>
   0x00007ffff7f89f28 <+776>:	lea    rdi,[rip+0x27bf1]        # 0x7ffff7fb1b20
   0x00007ffff7f89f2f <+783>:	call   0x7ffff7fae630 <__tls_get_addr@plt>
   0x00007ffff7f89f34 <+788>:	mov    eax,DWORD PTR [rax+0x10]
   0x00007ffff7f89f3a <+794>:	mov    DWORD PTR [rbp-0x4],eax
   0x00007ffff7f89f3d <+797>:	jmp    0x7ffff7f8a046 <heap.SmpAllocator.alloc+1062>
   0x00007ffff7f89f42 <+802>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f46 <+806>:	mov    esi,0x10000
   0x00007ffff7f89f4b <+811>:	call   0x7ffff7f18cd0 <mem.Alignment.fromByteUnits>
   0x00007ffff7f89f50 <+816>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f54 <+820>:	movzx  edx,al
   0x00007ffff7f89f57 <+823>:	mov    esi,0x10000
   0x00007ffff7f89f5c <+828>:	call   0x7ffff7f889a0 <heap.PageAllocator.map>
   0x00007ffff7f89f61 <+833>:	mov    QWORD PTR [rbp-0xe0],rax
   0x00007ffff7f89f68 <+840>:	cmp    rax,0x0
   0x00007ffff7f89f6c <+844>:	jne    0x7ffff7f89f9b <heap.SmpAllocator.alloc+891>
   0x00007ffff7f89f6e <+846>:	jmp    0x7ffff7f89fab <heap.SmpAllocator.alloc+907>
   0x00007ffff7f89f70 <+848>:	jmp    0x7ffff7f89ef6 <heap.SmpAllocator.alloc+726>
   0x00007ffff7f89f72 <+850>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89f76 <+854>:	mov    rcx,QWORD PTR [rbp-0xf8]
   0x00007ffff7f89f7d <+861>:	mov    QWORD PTR [rbp-0xf0],rcx
   0x00007ffff7f89f84 <+868>:	mov    QWORD PTR [rbp-0x10],rcx
   0x00007ffff7f89f88 <+872>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89f8c <+876>:	mov    QWORD PTR [rbp-0xe8],rcx
   0x00007ffff7f89f93 <+883>:	cmp    rax,0xd
   0x00007ffff7f89f97 <+887>:	jb     0x7ffff7f89ffb <heap.SmpAllocator.alloc+987>
   0x00007ffff7f89f99 <+889>:	jmp    0x7ffff7f89ffd <heap.SmpAllocator.alloc+989>
   0x00007ffff7f89f9b <+891>:	mov    rax,QWORD PTR [rbp-0xe0]
   0x00007ffff7f89fa2 <+898>:	mov    QWORD PTR [rbp-0xf8],rax
   0x00007ffff7f89fa9 <+905>:	jmp    0x7ffff7f89f72 <heap.SmpAllocator.alloc+850>
   0x00007ffff7f89fab <+907>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89faf <+911>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89fb3 <+915>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89fb8 <+920>:	xor    eax,eax
   0x00007ffff7f89fba <+922>:	add    rsp,0x120
   0x00007ffff7f89fc1 <+929>:	pop    rbp
   0x00007ffff7f89fc2 <+930>:	ret
   0x00007ffff7f89fc3 <+931>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89fca <+938>:	mov    rax,QWORD PTR [rbp-0xf0]
   0x00007ffff7f89fd1 <+945>:	mov    rdx,QWORD PTR [rbp-0xe8]
   0x00007ffff7f89fd8 <+952>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89fdc <+956>:	shl    rsi,0x3
   0x00007ffff7f89fe0 <+960>:	add    rdx,rsi
   0x00007ffff7f89fe3 <+963>:	mov    QWORD PTR [rbp-0x108],rdx
   0x00007ffff7f89fea <+970>:	add    rax,rcx
   0x00007ffff7f89fed <+973>:	mov    QWORD PTR [rbp-0x100],rax
   0x00007ffff7f89ff4 <+980>:	setb   al
   0x00007ffff7f89ff7 <+983>:	jb     0x7ffff7f8a00f <heap.SmpAllocator.alloc+1007>
   0x00007ffff7f89ff9 <+985>:	jmp    0x7ffff7f8a018 <heap.SmpAllocator.alloc+1016>
   0x00007ffff7f89ffb <+987>:	jmp    0x7ffff7f89fc3 <heap.SmpAllocator.alloc+931>
   0x00007ffff7f89ffd <+989>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f8a001 <+993>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a005 <+997>:	mov    edx,0xd
   0x00007ffff7f8a00a <+1002>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f8a00f <+1007>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a013 <+1011>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a018 <+1016>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a01c <+1020>:	mov    rax,QWORD PTR [rbp-0x108]
   0x00007ffff7f8a023 <+1027>:	mov    rcx,QWORD PTR [rbp-0x100]
   0x00007ffff7f8a02a <+1034>:	mov    QWORD PTR [rax],rcx
   0x00007ffff7f8a02d <+1037>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f8a031 <+1041>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f8a036 <+1046>:	mov    rax,QWORD PTR [rbp-0xf0]
   0x00007ffff7f8a03d <+1053>:	add    rsp,0x120
   0x00007ffff7f8a044 <+1060>:	pop    rbp
   0x00007ffff7f8a045 <+1061>:	ret
   0x00007ffff7f8a046 <+1062>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a049 <+1065>:	add    eax,0x1
   0x00007ffff7f8a04c <+1068>:	mov    DWORD PTR [rbp-0x10c],eax
   0x00007ffff7f8a052 <+1074>:	setb   al
   0x00007ffff7f8a055 <+1077>:	jb     0x7ffff7f8a059 <heap.SmpAllocator.alloc+1081>
   0x00007ffff7f8a057 <+1079>:	jmp    0x7ffff7f8a062 <heap.SmpAllocator.alloc+1090>
   0x00007ffff7f8a059 <+1081>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a05d <+1085>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a062 <+1090>:	mov    eax,DWORD PTR [rbp-0xd4]
   0x00007ffff7f8a068 <+1096>:	cmp    eax,0x0
   0x00007ffff7f8a06b <+1099>:	jne    0x7ffff7f8a096 <heap.SmpAllocator.alloc+1142>
   0x00007ffff7f8a06d <+1101>:	jmp    0x7ffff7f8a098 <heap.SmpAllocator.alloc+1144>
   0x00007ffff7f8a06f <+1103>:	mov    ecx,DWORD PTR [rbp-0xd4]
   0x00007ffff7f8a075 <+1109>:	mov    eax,DWORD PTR [rbp-0x10c]
   0x00007ffff7f8a07b <+1115>:	xor    edx,edx
   0x00007ffff7f8a07d <+1117>:	div    ecx
   0x00007ffff7f8a07f <+1119>:	mov    DWORD PTR [rbp-0x4],edx
   0x00007ffff7f8a082 <+1122>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a085 <+1125>:	mov    QWORD PTR [rbp-0x118],rax
   0x00007ffff7f8a08c <+1132>:	cmp    rax,0x80
   0x00007ffff7f8a092 <+1138>:	jb     0x7ffff7f8a0d4 <heap.SmpAllocator.alloc+1204>
   0x00007ffff7f8a094 <+1140>:	jmp    0x7ffff7f8a0d6 <heap.SmpAllocator.alloc+1206>
   0x00007ffff7f8a096 <+1142>:	jmp    0x7ffff7f8a06f <heap.SmpAllocator.alloc+1103>
   0x00007ffff7f8a098 <+1144>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a09c <+1148>:	call   0x7ffff7f10e70 <debug.FullPanic((function 'defaultPanic')).divideByZero>
   0x00007ffff7f8a0a1 <+1153>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a0a5 <+1157>:	mov    rcx,QWORD PTR [rbp-0x118]
   0x00007ffff7f8a0ac <+1164>:	lea    rax,[rip+0x29fcd]        # 0x7ffff7fb4080 <heap.SmpAllocator.global>
   0x00007ffff7f8a0b3 <+1171>:	shl    rcx,0x8
   0x00007ffff7f8a0b7 <+1175>:	add    rax,rcx
   0x00007ffff7f8a0ba <+1178>:	mov    QWORD PTR [rbp-0x30],rax
   0x00007ffff7f8a0be <+1182>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f8a0c2 <+1186>:	add    rsi,0xd0
   0x00007ffff7f8a0c9 <+1193>:	call   0x7ffff7f8a4e0 <Thread.Mutex.tryLock>
   0x00007ffff7f8a0ce <+1198>:	test   al,0x1
   0x00007ffff7f8a0d0 <+1200>:	jne    0x7ffff7f8a0f0 <heap.SmpAllocator.alloc+1232>
   0x00007ffff7f8a0d2 <+1202>:	jmp    0x7ffff7f8a125 <heap.SmpAllocator.alloc+1285>
   0x00007ffff7f8a0d4 <+1204>:	jmp    0x7ffff7f8a0a1 <heap.SmpAllocator.alloc+1153>
   0x00007ffff7f8a0d6 <+1206>:	mov    rsi,QWORD PTR [rbp-0x118]
   0x00007ffff7f8a0dd <+1213>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a0e1 <+1217>:	mov    edx,0x80
   0x00007ffff7f8a0e6 <+1222>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f8a0eb <+1227>:	jmp    0x7ffff7f8a046 <heap.SmpAllocator.alloc+1062>
=> 0x00007ffff7f8a0f0 <+1232>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a0f3 <+1235>:	mov    DWORD PTR [rbp-0x120],eax
   0x00007ffff7f8a0f9 <+1241>:	lea    rdi,[rip+0x27a20]        # 0x7ffff7fb1b20
   0x00007ffff7f8a100 <+1248>:	call   0x7ffff7fae630 <__tls_get_addr@plt>
   0x00007ffff7f8a105 <+1253>:	mov    ecx,DWORD PTR [rbp-0x120]
   0x00007ffff7f8a10b <+1259>:	mov    DWORD PTR [rax+0x10],ecx
   0x00007ffff7f8a111 <+1265>:	mov    al,BYTE PTR [rbp-0x31]
   0x00007ffff7f8a114 <+1268>:	add    al,0x1
   0x00007ffff7f8a116 <+1270>:	mov    BYTE PTR [rbp-0x119],al
   0x00007ffff7f8a11c <+1276>:	setb   al
   0x00007ffff7f8a11f <+1279>:	test   al,0x1
   0x00007ffff7f8a121 <+1281>:	jne    0x7ffff7f8a127 <heap.SmpAllocator.alloc+1287>
   0x00007ffff7f8a123 <+1283>:	jmp    0x7ffff7f8a130 <heap.SmpAllocator.alloc+1296>
   0x00007ffff7f8a125 <+1285>:	jmp    0x7ffff7f8a0eb <heap.SmpAllocator.alloc+1227>
   0x00007ffff7f8a127 <+1287>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a12b <+1291>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a130 <+1296>:	mov    al,BYTE PTR [rbp-0x119]
   0x00007ffff7f8a136 <+1302>:	mov    BYTE PTR [rbp-0x31],al
   0x00007ffff7f8a139 <+1305>:	jmp    0x7ffff7f89d0f <heap.SmpAllocator.alloc+239>
End of assembler dump.
warning: Currently logging to gdb.c.  Turn the logging off and on to make the new setting effective.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[New Thread 0x7ffff78bf6c0 (LWP 4694)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff78bf6c0 (LWP 4694)]
0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Breakpoint 1 at 0x7ffff7f8a3ae: file /usr/lib/zig/std/heap/SmpAllocator.zig, line 89.
Breakpoint 2 at 0x7ffff7f8a0f0: file /usr/lib/zig/std/heap/SmpAllocator.zig, line 168.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".

Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=1032, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Continuing.

Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=32, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Continuing.
[New Thread 0x7ffff78bf6c0 (LWP 4699)]
[Switching to Thread 0x7ffff78bf6c0 (LWP 4699)]

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=21, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Dump of assembler code for function heap.SmpAllocator.alloc:
   0x00007ffff7f89c20 <+0>:	push   rbp
   0x00007ffff7f89c21 <+1>:	mov    rbp,rsp
   0x00007ffff7f89c24 <+4>:	sub    rsp,0x120
   0x00007ffff7f89c2b <+11>:	mov    eax,ecx
   0x00007ffff7f89c2d <+13>:	mov    QWORD PTR [rbp-0x88],rdx
   0x00007ffff7f89c34 <+20>:	mov    rcx,rsi
   0x00007ffff7f89c37 <+23>:	mov    rsi,QWORD PTR [rbp-0x88]
   0x00007ffff7f89c3e <+30>:	mov    QWORD PTR [rbp-0x80],rdi
   0x00007ffff7f89c42 <+34>:	mov    BYTE PTR [rbp-0x71],al
   0x00007ffff7f89c45 <+37>:	mov    QWORD PTR [rbp-0x68],rcx
   0x00007ffff7f89c49 <+41>:	mov    QWORD PTR [rbp-0x60],rsi
   0x00007ffff7f89c4d <+45>:	mov    cl,al
   0x00007ffff7f89c4f <+47>:	and    cl,0x3f
   0x00007ffff7f89c52 <+50>:	mov    BYTE PTR [rbp-0x51],cl
   0x00007ffff7f89c55 <+53>:	mov    QWORD PTR [rbp-0x50],r8
   0x00007ffff7f89c59 <+57>:	movzx  edx,al
   0x00007ffff7f89c5c <+60>:	call   0x7ffff7f8a140 <heap.SmpAllocator.sizeClassIndex>
   0x00007ffff7f89c61 <+65>:	mov    QWORD PTR [rbp-0x70],rax
   0x00007ffff7f89c65 <+69>:	mov    QWORD PTR [rbp-0x48],rax
   0x00007ffff7f89c69 <+73>:	cmp    rax,0xd
   0x00007ffff7f89c6d <+77>:	jae    0x7ffff7f89c91 <heap.SmpAllocator.alloc+113>
   0x00007ffff7f89c6f <+79>:	jmp    0x7ffff7f89cb0 <heap.SmpAllocator.alloc+144>
   0x00007ffff7f89c71 <+81>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89c75 <+85>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89c79 <+89>:	call   0x7ffff7f8a200 <heap.SmpAllocator.slotSize>
   0x00007ffff7f89c7e <+94>:	mov    QWORD PTR [rbp-0x90],rax
   0x00007ffff7f89c85 <+101>:	mov    QWORD PTR [rbp-0x40],rax
   0x00007ffff7f89c89 <+105>:	cmp    rax,0x0
   0x00007ffff7f89c8d <+109>:	jne    0x7ffff7f89ce9 <heap.SmpAllocator.alloc+201>
   0x00007ffff7f89c8f <+111>:	jmp    0x7ffff7f89ceb <heap.SmpAllocator.alloc+203>
   0x00007ffff7f89c91 <+113>:	mov    rsi,QWORD PTR [rbp-0x88]
   0x00007ffff7f89c98 <+120>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89c9c <+124>:	mov    al,BYTE PTR [rbp-0x71]
   0x00007ffff7f89c9f <+127>:	movzx  edx,al
   0x00007ffff7f89ca2 <+130>:	call   0x7ffff7f889a0 <heap.PageAllocator.map>
   0x00007ffff7f89ca7 <+135>:	add    rsp,0x120
   0x00007ffff7f89cae <+142>:	pop    rbp
   0x00007ffff7f89caf <+143>:	ret
   0x00007ffff7f89cb0 <+144>:	jmp    0x7ffff7f89c71 <heap.SmpAllocator.alloc+81>
   0x00007ffff7f89cb2 <+146>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cb6 <+150>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89cbd <+157>:	mov    eax,0x10000
   0x00007ffff7f89cc2 <+162>:	xor    edx,edx
   0x00007ffff7f89cc4 <+164>:	div    rcx
   0x00007ffff7f89cc7 <+167>:	cmp    rdx,0x0
   0x00007ffff7f89ccb <+171>:	sete   al
   0x00007ffff7f89cce <+174>:	movzx  esi,al
   0x00007ffff7f89cd1 <+177>:	call   0x7ffff7ef2790 <debug.assert>
   0x00007ffff7f89cd6 <+182>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cda <+186>:	mov    BYTE PTR [rbp-0x31],0x0
   0x00007ffff7f89cde <+190>:	call   0x7ffff7f8a260 <heap.SmpAllocator.Thread.lock>
   0x00007ffff7f89ce3 <+195>:	mov    QWORD PTR [rbp-0x30],rax
   0x00007ffff7f89ce7 <+199>:	jmp    0x7ffff7f89cf4 <heap.SmpAllocator.alloc+212>
   0x00007ffff7f89ce9 <+201>:	jmp    0x7ffff7f89cb2 <heap.SmpAllocator.alloc+146>
   0x00007ffff7f89ceb <+203>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cef <+207>:	call   0x7ffff7f10e70 <debug.FullPanic((function 'defaultPanic')).divideByZero>
   0x00007ffff7f89cf4 <+212>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89cf8 <+216>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89cfc <+220>:	add    rcx,0x68
   0x00007ffff7f89d00 <+224>:	mov    QWORD PTR [rbp-0x98],rcx
   0x00007ffff7f89d07 <+231>:	cmp    rax,0xd
   0x00007ffff7f89d0b <+235>:	jb     0x7ffff7f89d33 <heap.SmpAllocator.alloc+275>
   0x00007ffff7f89d0d <+237>:	jmp    0x7ffff7f89d35 <heap.SmpAllocator.alloc+277>
   0x00007ffff7f89d0f <+239>:	jmp    0x7ffff7f89cf4 <heap.SmpAllocator.alloc+212>
   0x00007ffff7f89d11 <+241>:	mov    rax,QWORD PTR [rbp-0x98]
   0x00007ffff7f89d18 <+248>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d1c <+252>:	mov    rax,QWORD PTR [rax+rcx*8]
   0x00007ffff7f89d20 <+256>:	mov    QWORD PTR [rbp-0xa0],rax
   0x00007ffff7f89d27 <+263>:	mov    QWORD PTR [rbp-0x28],rax
   0x00007ffff7f89d2b <+267>:	cmp    rax,0x0
   0x00007ffff7f89d2f <+271>:	jne    0x7ffff7f89d65 <heap.SmpAllocator.alloc+325>
   0x00007ffff7f89d31 <+273>:	jmp    0x7ffff7f89d74 <heap.SmpAllocator.alloc+340>
   0x00007ffff7f89d33 <+275>:	jmp    0x7ffff7f89d11 <heap.SmpAllocator.alloc+241>
   0x00007ffff7f89d35 <+277>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d39 <+281>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89d3d <+285>:	mov    edx,0xd
   0x00007ffff7f89d42 <+290>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89d47 <+295>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d4b <+299>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89d4f <+303>:	mov    QWORD PTR [rbp-0xa8],rcx
   0x00007ffff7f89d56 <+310>:	cmp    rax,0xd
   0x00007ffff7f89d5a <+314>:	jb     0x7ffff7f89e37 <heap.SmpAllocator.alloc+535>
   0x00007ffff7f89d60 <+320>:	jmp    0x7ffff7f89e39 <heap.SmpAllocator.alloc+537>
   0x00007ffff7f89d65 <+325>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d6c <+332>:	cmp    rax,0x0
   0x00007ffff7f89d70 <+336>:	jne    0x7ffff7f89d89 <heap.SmpAllocator.alloc+361>
   0x00007ffff7f89d72 <+338>:	jmp    0x7ffff7f89d8b <heap.SmpAllocator.alloc+363>
   0x00007ffff7f89d74 <+340>:	jmp    0x7ffff7f89d47 <heap.SmpAllocator.alloc+295>
   0x00007ffff7f89d76 <+342>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d7d <+349>:	and    rax,0x7
   0x00007ffff7f89d81 <+353>:	cmp    rax,0x0
   0x00007ffff7f89d85 <+357>:	je     0x7ffff7f89dba <heap.SmpAllocator.alloc+410>
   0x00007ffff7f89d87 <+359>:	jmp    0x7ffff7f89dbc <heap.SmpAllocator.alloc+412>
   0x00007ffff7f89d89 <+361>:	jmp    0x7ffff7f89d76 <heap.SmpAllocator.alloc+342>
   0x00007ffff7f89d8b <+363>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89d8f <+367>:	call   0x7ffff7efa8d0 <debug.FullPanic((function 'defaultPanic')).castToNull>
   0x00007ffff7f89d94 <+372>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d98 <+376>:	mov    rcx,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d9f <+383>:	mov    QWORD PTR [rbp-0x20],rcx
   0x00007ffff7f89da3 <+387>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89da7 <+391>:	add    rcx,0x68
   0x00007ffff7f89dab <+395>:	mov    QWORD PTR [rbp-0xb0],rcx
   0x00007ffff7f89db2 <+402>:	cmp    rax,0xd
   0x00007ffff7f89db6 <+406>:	jb     0x7ffff7f89dfb <heap.SmpAllocator.alloc+475>
   0x00007ffff7f89db8 <+408>:	jmp    0x7ffff7f89dfd <heap.SmpAllocator.alloc+477>
   0x00007ffff7f89dba <+410>:	jmp    0x7ffff7f89d94 <heap.SmpAllocator.alloc+372>
   0x00007ffff7f89dbc <+412>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89dc0 <+416>:	call   0x7ffff7ef5d30 <debug.FullPanic((function 'defaultPanic')).incorrectAlignment>
   0x00007ffff7f89dc5 <+421>:	mov    rdx,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89dcc <+428>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89dd0 <+432>:	mov    rax,QWORD PTR [rbp-0xb0]
   0x00007ffff7f89dd7 <+439>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89ddb <+443>:	mov    rdx,QWORD PTR [rdx]
   0x00007ffff7f89dde <+446>:	mov    QWORD PTR [rax+rcx*8],rdx
   0x00007ffff7f89de2 <+450>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89de6 <+454>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89deb <+459>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89df2 <+466>:	add    rsp,0x120
   0x00007ffff7f89df9 <+473>:	pop    rbp
   0x00007ffff7f89dfa <+474>:	ret
   0x00007ffff7f89dfb <+475>:	jmp    0x7ffff7f89dc5 <heap.SmpAllocator.alloc+421>
   0x00007ffff7f89dfd <+477>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e01 <+481>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89e05 <+485>:	mov    edx,0xd
   0x00007ffff7f89e0a <+490>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89e0f <+495>:	mov    rax,QWORD PTR [rbp-0xa8]
   0x00007ffff7f89e16 <+502>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e1a <+506>:	mov    rax,QWORD PTR [rax+rcx*8]
   0x00007ffff7f89e1e <+510>:	mov    QWORD PTR [rbp-0xb8],rax
   0x00007ffff7f89e25 <+517>:	mov    QWORD PTR [rbp-0x18],rax
   0x00007ffff7f89e29 <+521>:	and    rax,0xffff
   0x00007ffff7f89e2f <+527>:	cmp    rax,0x0
   0x00007ffff7f89e33 <+531>:	jne    0x7ffff7f89e5a <heap.SmpAllocator.alloc+570>
   0x00007ffff7f89e35 <+533>:	jmp    0x7ffff7f89e71 <heap.SmpAllocator.alloc+593>
   0x00007ffff7f89e37 <+535>:	jmp    0x7ffff7f89e0f <heap.SmpAllocator.alloc+495>
   0x00007ffff7f89e39 <+537>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e3d <+541>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89e41 <+545>:	mov    edx,0xd
   0x00007ffff7f89e46 <+550>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89e4b <+555>:	cmp    BYTE PTR [rbp-0x31],0x1
   0x00007ffff7f89e4f <+559>:	jae    0x7ffff7f89f42 <heap.SmpAllocator.alloc+802>
   0x00007ffff7f89e55 <+565>:	jmp    0x7ffff7f89f70 <heap.SmpAllocator.alloc+848>
   0x00007ffff7f89e5a <+570>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e5e <+574>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89e62 <+578>:	mov    QWORD PTR [rbp-0xc0],rcx
   0x00007ffff7f89e69 <+585>:	cmp    rax,0xd
   0x00007ffff7f89e6d <+589>:	jb     0x7ffff7f89eab <heap.SmpAllocator.alloc+651>
   0x00007ffff7f89e6f <+591>:	jmp    0x7ffff7f89ead <heap.SmpAllocator.alloc+653>
   0x00007ffff7f89e71 <+593>:	jmp    0x7ffff7f89e4b <heap.SmpAllocator.alloc+555>
   0x00007ffff7f89e73 <+595>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89e7a <+602>:	mov    rax,QWORD PTR [rbp-0xb8]
   0x00007ffff7f89e81 <+609>:	mov    rdx,QWORD PTR [rbp-0xc0]
   0x00007ffff7f89e88 <+616>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e8c <+620>:	shl    rsi,0x3
   0x00007ffff7f89e90 <+624>:	add    rdx,rsi
   0x00007ffff7f89e93 <+627>:	mov    QWORD PTR [rbp-0xd0],rdx
   0x00007ffff7f89e9a <+634>:	add    rax,rcx
   0x00007ffff7f89e9d <+637>:	mov    QWORD PTR [rbp-0xc8],rax
   0x00007ffff7f89ea4 <+644>:	setb   al
   0x00007ffff7f89ea7 <+647>:	jb     0x7ffff7f89ebf <heap.SmpAllocator.alloc+671>
   0x00007ffff7f89ea9 <+649>:	jmp    0x7ffff7f89ec8 <heap.SmpAllocator.alloc+680>
   0x00007ffff7f89eab <+651>:	jmp    0x7ffff7f89e73 <heap.SmpAllocator.alloc+595>
   0x00007ffff7f89ead <+653>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89eb1 <+657>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89eb5 <+661>:	mov    edx,0xd
   0x00007ffff7f89eba <+666>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89ebf <+671>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89ec3 <+675>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f89ec8 <+680>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89ecc <+684>:	mov    rax,QWORD PTR [rbp-0xd0]
   0x00007ffff7f89ed3 <+691>:	mov    rcx,QWORD PTR [rbp-0xc8]
   0x00007ffff7f89eda <+698>:	mov    QWORD PTR [rax],rcx
   0x00007ffff7f89edd <+701>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89ee1 <+705>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89ee6 <+710>:	mov    rax,QWORD PTR [rbp-0xb8]
   0x00007ffff7f89eed <+717>:	add    rsp,0x120
   0x00007ffff7f89ef4 <+724>:	pop    rbp
   0x00007ffff7f89ef5 <+725>:	ret
   0x00007ffff7f89ef6 <+726>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89efa <+730>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89efe <+734>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89f03 <+739>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f07 <+743>:	call   0x7ffff7f8a410 <heap.SmpAllocator.getCpuCount>
   0x00007ffff7f89f0c <+748>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f10 <+752>:	mov    ecx,eax
   0x00007ffff7f89f12 <+754>:	mov    DWORD PTR [rbp-0xd4],ecx
   0x00007ffff7f89f18 <+760>:	mov    DWORD PTR [rbp-0x8],eax
   0x00007ffff7f89f1b <+763>:	test   eax,eax
   0x00007ffff7f89f1d <+765>:	setne  al
   0x00007ffff7f89f20 <+768>:	movzx  esi,al
   0x00007ffff7f89f23 <+771>:	call   0x7ffff7ef2790 <debug.assert>
   0x00007ffff7f89f28 <+776>:	lea    rdi,[rip+0x27bf1]        # 0x7ffff7fb1b20
   0x00007ffff7f89f2f <+783>:	call   0x7ffff7fae630 <__tls_get_addr@plt>
   0x00007ffff7f89f34 <+788>:	mov    eax,DWORD PTR [rax+0x10]
   0x00007ffff7f89f3a <+794>:	mov    DWORD PTR [rbp-0x4],eax
   0x00007ffff7f89f3d <+797>:	jmp    0x7ffff7f8a046 <heap.SmpAllocator.alloc+1062>
   0x00007ffff7f89f42 <+802>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f46 <+806>:	mov    esi,0x10000
   0x00007ffff7f89f4b <+811>:	call   0x7ffff7f18cd0 <mem.Alignment.fromByteUnits>
   0x00007ffff7f89f50 <+816>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f54 <+820>:	movzx  edx,al
   0x00007ffff7f89f57 <+823>:	mov    esi,0x10000
   0x00007ffff7f89f5c <+828>:	call   0x7ffff7f889a0 <heap.PageAllocator.map>
   0x00007ffff7f89f61 <+833>:	mov    QWORD PTR [rbp-0xe0],rax
   0x00007ffff7f89f68 <+840>:	cmp    rax,0x0
   0x00007ffff7f89f6c <+844>:	jne    0x7ffff7f89f9b <heap.SmpAllocator.alloc+891>
   0x00007ffff7f89f6e <+846>:	jmp    0x7ffff7f89fab <heap.SmpAllocator.alloc+907>
   0x00007ffff7f89f70 <+848>:	jmp    0x7ffff7f89ef6 <heap.SmpAllocator.alloc+726>
   0x00007ffff7f89f72 <+850>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89f76 <+854>:	mov    rcx,QWORD PTR [rbp-0xf8]
   0x00007ffff7f89f7d <+861>:	mov    QWORD PTR [rbp-0xf0],rcx
   0x00007ffff7f89f84 <+868>:	mov    QWORD PTR [rbp-0x10],rcx
   0x00007ffff7f89f88 <+872>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89f8c <+876>:	mov    QWORD PTR [rbp-0xe8],rcx
   0x00007ffff7f89f93 <+883>:	cmp    rax,0xd
   0x00007ffff7f89f97 <+887>:	jb     0x7ffff7f89ffb <heap.SmpAllocator.alloc+987>
   0x00007ffff7f89f99 <+889>:	jmp    0x7ffff7f89ffd <heap.SmpAllocator.alloc+989>
   0x00007ffff7f89f9b <+891>:	mov    rax,QWORD PTR [rbp-0xe0]
   0x00007ffff7f89fa2 <+898>:	mov    QWORD PTR [rbp-0xf8],rax
   0x00007ffff7f89fa9 <+905>:	jmp    0x7ffff7f89f72 <heap.SmpAllocator.alloc+850>
   0x00007ffff7f89fab <+907>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89faf <+911>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89fb3 <+915>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89fb8 <+920>:	xor    eax,eax
   0x00007ffff7f89fba <+922>:	add    rsp,0x120
   0x00007ffff7f89fc1 <+929>:	pop    rbp
   0x00007ffff7f89fc2 <+930>:	ret
   0x00007ffff7f89fc3 <+931>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89fca <+938>:	mov    rax,QWORD PTR [rbp-0xf0]
   0x00007ffff7f89fd1 <+945>:	mov    rdx,QWORD PTR [rbp-0xe8]
   0x00007ffff7f89fd8 <+952>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89fdc <+956>:	shl    rsi,0x3
   0x00007ffff7f89fe0 <+960>:	add    rdx,rsi
   0x00007ffff7f89fe3 <+963>:	mov    QWORD PTR [rbp-0x108],rdx
   0x00007ffff7f89fea <+970>:	add    rax,rcx
   0x00007ffff7f89fed <+973>:	mov    QWORD PTR [rbp-0x100],rax
   0x00007ffff7f89ff4 <+980>:	setb   al
   0x00007ffff7f89ff7 <+983>:	jb     0x7ffff7f8a00f <heap.SmpAllocator.alloc+1007>
   0x00007ffff7f89ff9 <+985>:	jmp    0x7ffff7f8a018 <heap.SmpAllocator.alloc+1016>
   0x00007ffff7f89ffb <+987>:	jmp    0x7ffff7f89fc3 <heap.SmpAllocator.alloc+931>
   0x00007ffff7f89ffd <+989>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f8a001 <+993>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a005 <+997>:	mov    edx,0xd
   0x00007ffff7f8a00a <+1002>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f8a00f <+1007>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a013 <+1011>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a018 <+1016>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a01c <+1020>:	mov    rax,QWORD PTR [rbp-0x108]
   0x00007ffff7f8a023 <+1027>:	mov    rcx,QWORD PTR [rbp-0x100]
   0x00007ffff7f8a02a <+1034>:	mov    QWORD PTR [rax],rcx
   0x00007ffff7f8a02d <+1037>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f8a031 <+1041>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f8a036 <+1046>:	mov    rax,QWORD PTR [rbp-0xf0]
   0x00007ffff7f8a03d <+1053>:	add    rsp,0x120
   0x00007ffff7f8a044 <+1060>:	pop    rbp
   0x00007ffff7f8a045 <+1061>:	ret
   0x00007ffff7f8a046 <+1062>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a049 <+1065>:	add    eax,0x1
   0x00007ffff7f8a04c <+1068>:	mov    DWORD PTR [rbp-0x10c],eax
   0x00007ffff7f8a052 <+1074>:	setb   al
   0x00007ffff7f8a055 <+1077>:	jb     0x7ffff7f8a059 <heap.SmpAllocator.alloc+1081>
   0x00007ffff7f8a057 <+1079>:	jmp    0x7ffff7f8a062 <heap.SmpAllocator.alloc+1090>
   0x00007ffff7f8a059 <+1081>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a05d <+1085>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a062 <+1090>:	mov    eax,DWORD PTR [rbp-0xd4]
   0x00007ffff7f8a068 <+1096>:	cmp    eax,0x0
   0x00007ffff7f8a06b <+1099>:	jne    0x7ffff7f8a096 <heap.SmpAllocator.alloc+1142>
   0x00007ffff7f8a06d <+1101>:	jmp    0x7ffff7f8a098 <heap.SmpAllocator.alloc+1144>
   0x00007ffff7f8a06f <+1103>:	mov    ecx,DWORD PTR [rbp-0xd4]
   0x00007ffff7f8a075 <+1109>:	mov    eax,DWORD PTR [rbp-0x10c]
   0x00007ffff7f8a07b <+1115>:	xor    edx,edx
   0x00007ffff7f8a07d <+1117>:	div    ecx
   0x00007ffff7f8a07f <+1119>:	mov    DWORD PTR [rbp-0x4],edx
   0x00007ffff7f8a082 <+1122>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a085 <+1125>:	mov    QWORD PTR [rbp-0x118],rax
   0x00007ffff7f8a08c <+1132>:	cmp    rax,0x80
   0x00007ffff7f8a092 <+1138>:	jb     0x7ffff7f8a0d4 <heap.SmpAllocator.alloc+1204>
   0x00007ffff7f8a094 <+1140>:	jmp    0x7ffff7f8a0d6 <heap.SmpAllocator.alloc+1206>
   0x00007ffff7f8a096 <+1142>:	jmp    0x7ffff7f8a06f <heap.SmpAllocator.alloc+1103>
   0x00007ffff7f8a098 <+1144>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a09c <+1148>:	call   0x7ffff7f10e70 <debug.FullPanic((function 'defaultPanic')).divideByZero>
   0x00007ffff7f8a0a1 <+1153>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a0a5 <+1157>:	mov    rcx,QWORD PTR [rbp-0x118]
   0x00007ffff7f8a0ac <+1164>:	lea    rax,[rip+0x29fcd]        # 0x7ffff7fb4080 <heap.SmpAllocator.global>
   0x00007ffff7f8a0b3 <+1171>:	shl    rcx,0x8
   0x00007ffff7f8a0b7 <+1175>:	add    rax,rcx
   0x00007ffff7f8a0ba <+1178>:	mov    QWORD PTR [rbp-0x30],rax
   0x00007ffff7f8a0be <+1182>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f8a0c2 <+1186>:	add    rsi,0xd0
   0x00007ffff7f8a0c9 <+1193>:	call   0x7ffff7f8a4e0 <Thread.Mutex.tryLock>
   0x00007ffff7f8a0ce <+1198>:	test   al,0x1
   0x00007ffff7f8a0d0 <+1200>:	jne    0x7ffff7f8a0f0 <heap.SmpAllocator.alloc+1232>
   0x00007ffff7f8a0d2 <+1202>:	jmp    0x7ffff7f8a125 <heap.SmpAllocator.alloc+1285>
   0x00007ffff7f8a0d4 <+1204>:	jmp    0x7ffff7f8a0a1 <heap.SmpAllocator.alloc+1153>
   0x00007ffff7f8a0d6 <+1206>:	mov    rsi,QWORD PTR [rbp-0x118]
   0x00007ffff7f8a0dd <+1213>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a0e1 <+1217>:	mov    edx,0x80
   0x00007ffff7f8a0e6 <+1222>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f8a0eb <+1227>:	jmp    0x7ffff7f8a046 <heap.SmpAllocator.alloc+1062>
=> 0x00007ffff7f8a0f0 <+1232>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a0f3 <+1235>:	mov    DWORD PTR [rbp-0x120],eax
   0x00007ffff7f8a0f9 <+1241>:	lea    rdi,[rip+0x27a20]        # 0x7ffff7fb1b20
   0x00007ffff7f8a100 <+1248>:	call   0x7ffff7fae630 <__tls_get_addr@plt>
   0x00007ffff7f8a105 <+1253>:	mov    ecx,DWORD PTR [rbp-0x120]
   0x00007ffff7f8a10b <+1259>:	mov    DWORD PTR [rax+0x10],ecx
   0x00007ffff7f8a111 <+1265>:	mov    al,BYTE PTR [rbp-0x31]
   0x00007ffff7f8a114 <+1268>:	add    al,0x1
   0x00007ffff7f8a116 <+1270>:	mov    BYTE PTR [rbp-0x119],al
   0x00007ffff7f8a11c <+1276>:	setb   al
   0x00007ffff7f8a11f <+1279>:	test   al,0x1
   0x00007ffff7f8a121 <+1281>:	jne    0x7ffff7f8a127 <heap.SmpAllocator.alloc+1287>
   0x00007ffff7f8a123 <+1283>:	jmp    0x7ffff7f8a130 <heap.SmpAllocator.alloc+1296>
   0x00007ffff7f8a125 <+1285>:	jmp    0x7ffff7f8a0eb <heap.SmpAllocator.alloc+1227>
   0x00007ffff7f8a127 <+1287>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a12b <+1291>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a130 <+1296>:	mov    al,BYTE PTR [rbp-0x119]
   0x00007ffff7f8a136 <+1302>:	mov    BYTE PTR [rbp-0x31],al
   0x00007ffff7f8a139 <+1305>:	jmp    0x7ffff7f89d0f <heap.SmpAllocator.alloc+239>
End of assembler dump.
  Id   Target Id                                Frame 
  1    Thread 0x7ffff7e8c780 (LWP 4695) "a.out" __syscall_cancel_arch () at ../sysdeps/unix/sysv/linux/x86_64/syscall_cancel.S:56
* 2    Thread 0x7ffff78bf6c0 (LWP 4699) "a.out" heap.SmpAllocator.alloc (context=0x0, len=21, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
169	                search_count += 1;
Dump of assembler code for function heap.SmpAllocator.alloc:
   0x00007ffff7f89c20 <+0>:	push   rbp
   0x00007ffff7f89c21 <+1>:	mov    rbp,rsp
   0x00007ffff7f89c24 <+4>:	sub    rsp,0x120
   0x00007ffff7f89c2b <+11>:	mov    eax,ecx
   0x00007ffff7f89c2d <+13>:	mov    QWORD PTR [rbp-0x88],rdx
   0x00007ffff7f89c34 <+20>:	mov    rcx,rsi
   0x00007ffff7f89c37 <+23>:	mov    rsi,QWORD PTR [rbp-0x88]
   0x00007ffff7f89c3e <+30>:	mov    QWORD PTR [rbp-0x80],rdi
   0x00007ffff7f89c42 <+34>:	mov    BYTE PTR [rbp-0x71],al
   0x00007ffff7f89c45 <+37>:	mov    QWORD PTR [rbp-0x68],rcx
   0x00007ffff7f89c49 <+41>:	mov    QWORD PTR [rbp-0x60],rsi
   0x00007ffff7f89c4d <+45>:	mov    cl,al
   0x00007ffff7f89c4f <+47>:	and    cl,0x3f
   0x00007ffff7f89c52 <+50>:	mov    BYTE PTR [rbp-0x51],cl
   0x00007ffff7f89c55 <+53>:	mov    QWORD PTR [rbp-0x50],r8
   0x00007ffff7f89c59 <+57>:	movzx  edx,al
   0x00007ffff7f89c5c <+60>:	call   0x7ffff7f8a140 <heap.SmpAllocator.sizeClassIndex>
   0x00007ffff7f89c61 <+65>:	mov    QWORD PTR [rbp-0x70],rax
   0x00007ffff7f89c65 <+69>:	mov    QWORD PTR [rbp-0x48],rax
   0x00007ffff7f89c69 <+73>:	cmp    rax,0xd
   0x00007ffff7f89c6d <+77>:	jae    0x7ffff7f89c91 <heap.SmpAllocator.alloc+113>
   0x00007ffff7f89c6f <+79>:	jmp    0x7ffff7f89cb0 <heap.SmpAllocator.alloc+144>
   0x00007ffff7f89c71 <+81>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89c75 <+85>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89c79 <+89>:	call   0x7ffff7f8a200 <heap.SmpAllocator.slotSize>
   0x00007ffff7f89c7e <+94>:	mov    QWORD PTR [rbp-0x90],rax
   0x00007ffff7f89c85 <+101>:	mov    QWORD PTR [rbp-0x40],rax
   0x00007ffff7f89c89 <+105>:	cmp    rax,0x0
   0x00007ffff7f89c8d <+109>:	jne    0x7ffff7f89ce9 <heap.SmpAllocator.alloc+201>
   0x00007ffff7f89c8f <+111>:	jmp    0x7ffff7f89ceb <heap.SmpAllocator.alloc+203>
   0x00007ffff7f89c91 <+113>:	mov    rsi,QWORD PTR [rbp-0x88]
   0x00007ffff7f89c98 <+120>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89c9c <+124>:	mov    al,BYTE PTR [rbp-0x71]
   0x00007ffff7f89c9f <+127>:	movzx  edx,al
   0x00007ffff7f89ca2 <+130>:	call   0x7ffff7f889a0 <heap.PageAllocator.map>
   0x00007ffff7f89ca7 <+135>:	add    rsp,0x120
   0x00007ffff7f89cae <+142>:	pop    rbp
   0x00007ffff7f89caf <+143>:	ret
   0x00007ffff7f89cb0 <+144>:	jmp    0x7ffff7f89c71 <heap.SmpAllocator.alloc+81>
   0x00007ffff7f89cb2 <+146>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cb6 <+150>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89cbd <+157>:	mov    eax,0x10000
   0x00007ffff7f89cc2 <+162>:	xor    edx,edx
   0x00007ffff7f89cc4 <+164>:	div    rcx
   0x00007ffff7f89cc7 <+167>:	cmp    rdx,0x0
   0x00007ffff7f89ccb <+171>:	sete   al
   0x00007ffff7f89cce <+174>:	movzx  esi,al
   0x00007ffff7f89cd1 <+177>:	call   0x7ffff7ef2790 <debug.assert>
   0x00007ffff7f89cd6 <+182>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cda <+186>:	mov    BYTE PTR [rbp-0x31],0x0
   0x00007ffff7f89cde <+190>:	call   0x7ffff7f8a260 <heap.SmpAllocator.Thread.lock>
   0x00007ffff7f89ce3 <+195>:	mov    QWORD PTR [rbp-0x30],rax
   0x00007ffff7f89ce7 <+199>:	jmp    0x7ffff7f89cf4 <heap.SmpAllocator.alloc+212>
   0x00007ffff7f89ce9 <+201>:	jmp    0x7ffff7f89cb2 <heap.SmpAllocator.alloc+146>
   0x00007ffff7f89ceb <+203>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cef <+207>:	call   0x7ffff7f10e70 <debug.FullPanic((function 'defaultPanic')).divideByZero>
   0x00007ffff7f89cf4 <+212>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89cf8 <+216>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89cfc <+220>:	add    rcx,0x68
   0x00007ffff7f89d00 <+224>:	mov    QWORD PTR [rbp-0x98],rcx
   0x00007ffff7f89d07 <+231>:	cmp    rax,0xd
   0x00007ffff7f89d0b <+235>:	jb     0x7ffff7f89d33 <heap.SmpAllocator.alloc+275>
   0x00007ffff7f89d0d <+237>:	jmp    0x7ffff7f89d35 <heap.SmpAllocator.alloc+277>
   0x00007ffff7f89d0f <+239>:	jmp    0x7ffff7f89cf4 <heap.SmpAllocator.alloc+212>
   0x00007ffff7f89d11 <+241>:	mov    rax,QWORD PTR [rbp-0x98]
   0x00007ffff7f89d18 <+248>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d1c <+252>:	mov    rax,QWORD PTR [rax+rcx*8]
   0x00007ffff7f89d20 <+256>:	mov    QWORD PTR [rbp-0xa0],rax
   0x00007ffff7f89d27 <+263>:	mov    QWORD PTR [rbp-0x28],rax
   0x00007ffff7f89d2b <+267>:	cmp    rax,0x0
   0x00007ffff7f89d2f <+271>:	jne    0x7ffff7f89d65 <heap.SmpAllocator.alloc+325>
   0x00007ffff7f89d31 <+273>:	jmp    0x7ffff7f89d74 <heap.SmpAllocator.alloc+340>
   0x00007ffff7f89d33 <+275>:	jmp    0x7ffff7f89d11 <heap.SmpAllocator.alloc+241>
   0x00007ffff7f89d35 <+277>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d39 <+281>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89d3d <+285>:	mov    edx,0xd
   0x00007ffff7f89d42 <+290>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89d47 <+295>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d4b <+299>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89d4f <+303>:	mov    QWORD PTR [rbp-0xa8],rcx
   0x00007ffff7f89d56 <+310>:	cmp    rax,0xd
   0x00007ffff7f89d5a <+314>:	jb     0x7ffff7f89e37 <heap.SmpAllocator.alloc+535>
   0x00007ffff7f89d60 <+320>:	jmp    0x7ffff7f89e39 <heap.SmpAllocator.alloc+537>
   0x00007ffff7f89d65 <+325>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d6c <+332>:	cmp    rax,0x0
   0x00007ffff7f89d70 <+336>:	jne    0x7ffff7f89d89 <heap.SmpAllocator.alloc+361>
   0x00007ffff7f89d72 <+338>:	jmp    0x7ffff7f89d8b <heap.SmpAllocator.alloc+363>
   0x00007ffff7f89d74 <+340>:	jmp    0x7ffff7f89d47 <heap.SmpAllocator.alloc+295>
   0x00007ffff7f89d76 <+342>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d7d <+349>:	and    rax,0x7
   0x00007ffff7f89d81 <+353>:	cmp    rax,0x0
   0x00007ffff7f89d85 <+357>:	je     0x7ffff7f89dba <heap.SmpAllocator.alloc+410>
   0x00007ffff7f89d87 <+359>:	jmp    0x7ffff7f89dbc <heap.SmpAllocator.alloc+412>
   0x00007ffff7f89d89 <+361>:	jmp    0x7ffff7f89d76 <heap.SmpAllocator.alloc+342>
   0x00007ffff7f89d8b <+363>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89d8f <+367>:	call   0x7ffff7efa8d0 <debug.FullPanic((function 'defaultPanic')).castToNull>
   0x00007ffff7f89d94 <+372>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d98 <+376>:	mov    rcx,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d9f <+383>:	mov    QWORD PTR [rbp-0x20],rcx
   0x00007ffff7f89da3 <+387>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89da7 <+391>:	add    rcx,0x68
   0x00007ffff7f89dab <+395>:	mov    QWORD PTR [rbp-0xb0],rcx
   0x00007ffff7f89db2 <+402>:	cmp    rax,0xd
   0x00007ffff7f89db6 <+406>:	jb     0x7ffff7f89dfb <heap.SmpAllocator.alloc+475>
   0x00007ffff7f89db8 <+408>:	jmp    0x7ffff7f89dfd <heap.SmpAllocator.alloc+477>
   0x00007ffff7f89dba <+410>:	jmp    0x7ffff7f89d94 <heap.SmpAllocator.alloc+372>
   0x00007ffff7f89dbc <+412>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89dc0 <+416>:	call   0x7ffff7ef5d30 <debug.FullPanic((function 'defaultPanic')).incorrectAlignment>
   0x00007ffff7f89dc5 <+421>:	mov    rdx,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89dcc <+428>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89dd0 <+432>:	mov    rax,QWORD PTR [rbp-0xb0]
   0x00007ffff7f89dd7 <+439>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89ddb <+443>:	mov    rdx,QWORD PTR [rdx]
   0x00007ffff7f89dde <+446>:	mov    QWORD PTR [rax+rcx*8],rdx
   0x00007ffff7f89de2 <+450>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89de6 <+454>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89deb <+459>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89df2 <+466>:	add    rsp,0x120
   0x00007ffff7f89df9 <+473>:	pop    rbp
   0x00007ffff7f89dfa <+474>:	ret
   0x00007ffff7f89dfb <+475>:	jmp    0x7ffff7f89dc5 <heap.SmpAllocator.alloc+421>
   0x00007ffff7f89dfd <+477>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e01 <+481>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89e05 <+485>:	mov    edx,0xd
   0x00007ffff7f89e0a <+490>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89e0f <+495>:	mov    rax,QWORD PTR [rbp-0xa8]
   0x00007ffff7f89e16 <+502>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e1a <+506>:	mov    rax,QWORD PTR [rax+rcx*8]
   0x00007ffff7f89e1e <+510>:	mov    QWORD PTR [rbp-0xb8],rax
   0x00007ffff7f89e25 <+517>:	mov    QWORD PTR [rbp-0x18],rax
   0x00007ffff7f89e29 <+521>:	and    rax,0xffff
   0x00007ffff7f89e2f <+527>:	cmp    rax,0x0
   0x00007ffff7f89e33 <+531>:	jne    0x7ffff7f89e5a <heap.SmpAllocator.alloc+570>
   0x00007ffff7f89e35 <+533>:	jmp    0x7ffff7f89e71 <heap.SmpAllocator.alloc+593>
   0x00007ffff7f89e37 <+535>:	jmp    0x7ffff7f89e0f <heap.SmpAllocator.alloc+495>
   0x00007ffff7f89e39 <+537>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e3d <+541>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89e41 <+545>:	mov    edx,0xd
   0x00007ffff7f89e46 <+550>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89e4b <+555>:	cmp    BYTE PTR [rbp-0x31],0x1
   0x00007ffff7f89e4f <+559>:	jae    0x7ffff7f89f42 <heap.SmpAllocator.alloc+802>
   0x00007ffff7f89e55 <+565>:	jmp    0x7ffff7f89f70 <heap.SmpAllocator.alloc+848>
   0x00007ffff7f89e5a <+570>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e5e <+574>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89e62 <+578>:	mov    QWORD PTR [rbp-0xc0],rcx
   0x00007ffff7f89e69 <+585>:	cmp    rax,0xd
   0x00007ffff7f89e6d <+589>:	jb     0x7ffff7f89eab <heap.SmpAllocator.alloc+651>
   0x00007ffff7f89e6f <+591>:	jmp    0x7ffff7f89ead <heap.SmpAllocator.alloc+653>
   0x00007ffff7f89e71 <+593>:	jmp    0x7ffff7f89e4b <heap.SmpAllocator.alloc+555>
   0x00007ffff7f89e73 <+595>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89e7a <+602>:	mov    rax,QWORD PTR [rbp-0xb8]
   0x00007ffff7f89e81 <+609>:	mov    rdx,QWORD PTR [rbp-0xc0]
   0x00007ffff7f89e88 <+616>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e8c <+620>:	shl    rsi,0x3
   0x00007ffff7f89e90 <+624>:	add    rdx,rsi
   0x00007ffff7f89e93 <+627>:	mov    QWORD PTR [rbp-0xd0],rdx
   0x00007ffff7f89e9a <+634>:	add    rax,rcx
   0x00007ffff7f89e9d <+637>:	mov    QWORD PTR [rbp-0xc8],rax
   0x00007ffff7f89ea4 <+644>:	setb   al
   0x00007ffff7f89ea7 <+647>:	jb     0x7ffff7f89ebf <heap.SmpAllocator.alloc+671>
   0x00007ffff7f89ea9 <+649>:	jmp    0x7ffff7f89ec8 <heap.SmpAllocator.alloc+680>
   0x00007ffff7f89eab <+651>:	jmp    0x7ffff7f89e73 <heap.SmpAllocator.alloc+595>
   0x00007ffff7f89ead <+653>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89eb1 <+657>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89eb5 <+661>:	mov    edx,0xd
   0x00007ffff7f89eba <+666>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89ebf <+671>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89ec3 <+675>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f89ec8 <+680>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89ecc <+684>:	mov    rax,QWORD PTR [rbp-0xd0]
   0x00007ffff7f89ed3 <+691>:	mov    rcx,QWORD PTR [rbp-0xc8]
   0x00007ffff7f89eda <+698>:	mov    QWORD PTR [rax],rcx
   0x00007ffff7f89edd <+701>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89ee1 <+705>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89ee6 <+710>:	mov    rax,QWORD PTR [rbp-0xb8]
   0x00007ffff7f89eed <+717>:	add    rsp,0x120
   0x00007ffff7f89ef4 <+724>:	pop    rbp
   0x00007ffff7f89ef5 <+725>:	ret
   0x00007ffff7f89ef6 <+726>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89efa <+730>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89efe <+734>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89f03 <+739>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f07 <+743>:	call   0x7ffff7f8a410 <heap.SmpAllocator.getCpuCount>
   0x00007ffff7f89f0c <+748>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f10 <+752>:	mov    ecx,eax
   0x00007ffff7f89f12 <+754>:	mov    DWORD PTR [rbp-0xd4],ecx
   0x00007ffff7f89f18 <+760>:	mov    DWORD PTR [rbp-0x8],eax
   0x00007ffff7f89f1b <+763>:	test   eax,eax
   0x00007ffff7f89f1d <+765>:	setne  al
   0x00007ffff7f89f20 <+768>:	movzx  esi,al
   0x00007ffff7f89f23 <+771>:	call   0x7ffff7ef2790 <debug.assert>
   0x00007ffff7f89f28 <+776>:	lea    rdi,[rip+0x27bf1]        # 0x7ffff7fb1b20
   0x00007ffff7f89f2f <+783>:	call   0x7ffff7fae630 <__tls_get_addr@plt>
   0x00007ffff7f89f34 <+788>:	mov    eax,DWORD PTR [rax+0x10]
   0x00007ffff7f89f3a <+794>:	mov    DWORD PTR [rbp-0x4],eax
   0x00007ffff7f89f3d <+797>:	jmp    0x7ffff7f8a046 <heap.SmpAllocator.alloc+1062>
   0x00007ffff7f89f42 <+802>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f46 <+806>:	mov    esi,0x10000
   0x00007ffff7f89f4b <+811>:	call   0x7ffff7f18cd0 <mem.Alignment.fromByteUnits>
   0x00007ffff7f89f50 <+816>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f54 <+820>:	movzx  edx,al
   0x00007ffff7f89f57 <+823>:	mov    esi,0x10000
   0x00007ffff7f89f5c <+828>:	call   0x7ffff7f889a0 <heap.PageAllocator.map>
   0x00007ffff7f89f61 <+833>:	mov    QWORD PTR [rbp-0xe0],rax
   0x00007ffff7f89f68 <+840>:	cmp    rax,0x0
   0x00007ffff7f89f6c <+844>:	jne    0x7ffff7f89f9b <heap.SmpAllocator.alloc+891>
   0x00007ffff7f89f6e <+846>:	jmp    0x7ffff7f89fab <heap.SmpAllocator.alloc+907>
   0x00007ffff7f89f70 <+848>:	jmp    0x7ffff7f89ef6 <heap.SmpAllocator.alloc+726>
   0x00007ffff7f89f72 <+850>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89f76 <+854>:	mov    rcx,QWORD PTR [rbp-0xf8]
   0x00007ffff7f89f7d <+861>:	mov    QWORD PTR [rbp-0xf0],rcx
   0x00007ffff7f89f84 <+868>:	mov    QWORD PTR [rbp-0x10],rcx
   0x00007ffff7f89f88 <+872>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89f8c <+876>:	mov    QWORD PTR [rbp-0xe8],rcx
   0x00007ffff7f89f93 <+883>:	cmp    rax,0xd
   0x00007ffff7f89f97 <+887>:	jb     0x7ffff7f89ffb <heap.SmpAllocator.alloc+987>
   0x00007ffff7f89f99 <+889>:	jmp    0x7ffff7f89ffd <heap.SmpAllocator.alloc+989>
   0x00007ffff7f89f9b <+891>:	mov    rax,QWORD PTR [rbp-0xe0]
   0x00007ffff7f89fa2 <+898>:	mov    QWORD PTR [rbp-0xf8],rax
   0x00007ffff7f89fa9 <+905>:	jmp    0x7ffff7f89f72 <heap.SmpAllocator.alloc+850>
   0x00007ffff7f89fab <+907>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89faf <+911>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89fb3 <+915>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89fb8 <+920>:	xor    eax,eax
   0x00007ffff7f89fba <+922>:	add    rsp,0x120
   0x00007ffff7f89fc1 <+929>:	pop    rbp
   0x00007ffff7f89fc2 <+930>:	ret
   0x00007ffff7f89fc3 <+931>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89fca <+938>:	mov    rax,QWORD PTR [rbp-0xf0]
   0x00007ffff7f89fd1 <+945>:	mov    rdx,QWORD PTR [rbp-0xe8]
   0x00007ffff7f89fd8 <+952>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89fdc <+956>:	shl    rsi,0x3
   0x00007ffff7f89fe0 <+960>:	add    rdx,rsi
   0x00007ffff7f89fe3 <+963>:	mov    QWORD PTR [rbp-0x108],rdx
   0x00007ffff7f89fea <+970>:	add    rax,rcx
   0x00007ffff7f89fed <+973>:	mov    QWORD PTR [rbp-0x100],rax
   0x00007ffff7f89ff4 <+980>:	setb   al
   0x00007ffff7f89ff7 <+983>:	jb     0x7ffff7f8a00f <heap.SmpAllocator.alloc+1007>
   0x00007ffff7f89ff9 <+985>:	jmp    0x7ffff7f8a018 <heap.SmpAllocator.alloc+1016>
   0x00007ffff7f89ffb <+987>:	jmp    0x7ffff7f89fc3 <heap.SmpAllocator.alloc+931>
   0x00007ffff7f89ffd <+989>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f8a001 <+993>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a005 <+997>:	mov    edx,0xd
   0x00007ffff7f8a00a <+1002>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f8a00f <+1007>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a013 <+1011>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a018 <+1016>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a01c <+1020>:	mov    rax,QWORD PTR [rbp-0x108]
   0x00007ffff7f8a023 <+1027>:	mov    rcx,QWORD PTR [rbp-0x100]
   0x00007ffff7f8a02a <+1034>:	mov    QWORD PTR [rax],rcx
   0x00007ffff7f8a02d <+1037>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f8a031 <+1041>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f8a036 <+1046>:	mov    rax,QWORD PTR [rbp-0xf0]
   0x00007ffff7f8a03d <+1053>:	add    rsp,0x120
   0x00007ffff7f8a044 <+1060>:	pop    rbp
   0x00007ffff7f8a045 <+1061>:	ret
   0x00007ffff7f8a046 <+1062>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a049 <+1065>:	add    eax,0x1
   0x00007ffff7f8a04c <+1068>:	mov    DWORD PTR [rbp-0x10c],eax
   0x00007ffff7f8a052 <+1074>:	setb   al
   0x00007ffff7f8a055 <+1077>:	jb     0x7ffff7f8a059 <heap.SmpAllocator.alloc+1081>
   0x00007ffff7f8a057 <+1079>:	jmp    0x7ffff7f8a062 <heap.SmpAllocator.alloc+1090>
   0x00007ffff7f8a059 <+1081>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a05d <+1085>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a062 <+1090>:	mov    eax,DWORD PTR [rbp-0xd4]
   0x00007ffff7f8a068 <+1096>:	cmp    eax,0x0
   0x00007ffff7f8a06b <+1099>:	jne    0x7ffff7f8a096 <heap.SmpAllocator.alloc+1142>
   0x00007ffff7f8a06d <+1101>:	jmp    0x7ffff7f8a098 <heap.SmpAllocator.alloc+1144>
   0x00007ffff7f8a06f <+1103>:	mov    ecx,DWORD PTR [rbp-0xd4]
   0x00007ffff7f8a075 <+1109>:	mov    eax,DWORD PTR [rbp-0x10c]
   0x00007ffff7f8a07b <+1115>:	xor    edx,edx
   0x00007ffff7f8a07d <+1117>:	div    ecx
   0x00007ffff7f8a07f <+1119>:	mov    DWORD PTR [rbp-0x4],edx
   0x00007ffff7f8a082 <+1122>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a085 <+1125>:	mov    QWORD PTR [rbp-0x118],rax
   0x00007ffff7f8a08c <+1132>:	cmp    rax,0x80
   0x00007ffff7f8a092 <+1138>:	jb     0x7ffff7f8a0d4 <heap.SmpAllocator.alloc+1204>
   0x00007ffff7f8a094 <+1140>:	jmp    0x7ffff7f8a0d6 <heap.SmpAllocator.alloc+1206>
   0x00007ffff7f8a096 <+1142>:	jmp    0x7ffff7f8a06f <heap.SmpAllocator.alloc+1103>
   0x00007ffff7f8a098 <+1144>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a09c <+1148>:	call   0x7ffff7f10e70 <debug.FullPanic((function 'defaultPanic')).divideByZero>
   0x00007ffff7f8a0a1 <+1153>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a0a5 <+1157>:	mov    rcx,QWORD PTR [rbp-0x118]
   0x00007ffff7f8a0ac <+1164>:	lea    rax,[rip+0x29fcd]        # 0x7ffff7fb4080 <heap.SmpAllocator.global>
   0x00007ffff7f8a0b3 <+1171>:	shl    rcx,0x8
   0x00007ffff7f8a0b7 <+1175>:	add    rax,rcx
   0x00007ffff7f8a0ba <+1178>:	mov    QWORD PTR [rbp-0x30],rax
   0x00007ffff7f8a0be <+1182>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f8a0c2 <+1186>:	add    rsi,0xd0
   0x00007ffff7f8a0c9 <+1193>:	call   0x7ffff7f8a4e0 <Thread.Mutex.tryLock>
   0x00007ffff7f8a0ce <+1198>:	test   al,0x1
   0x00007ffff7f8a0d0 <+1200>:	jne    0x7ffff7f8a0f0 <heap.SmpAllocator.alloc+1232>
   0x00007ffff7f8a0d2 <+1202>:	jmp    0x7ffff7f8a125 <heap.SmpAllocator.alloc+1285>
   0x00007ffff7f8a0d4 <+1204>:	jmp    0x7ffff7f8a0a1 <heap.SmpAllocator.alloc+1153>
   0x00007ffff7f8a0d6 <+1206>:	mov    rsi,QWORD PTR [rbp-0x118]
   0x00007ffff7f8a0dd <+1213>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a0e1 <+1217>:	mov    edx,0x80
   0x00007ffff7f8a0e6 <+1222>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f8a0eb <+1227>:	jmp    0x7ffff7f8a046 <heap.SmpAllocator.alloc+1062>
   0x00007ffff7f8a0f0 <+1232>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a0f3 <+1235>:	mov    DWORD PTR [rbp-0x120],eax
   0x00007ffff7f8a0f9 <+1241>:	lea    rdi,[rip+0x27a20]        # 0x7ffff7fb1b20
   0x00007ffff7f8a100 <+1248>:	call   0x7ffff7fae630 <__tls_get_addr@plt>
   0x00007ffff7f8a105 <+1253>:	mov    ecx,DWORD PTR [rbp-0x120]
   0x00007ffff7f8a10b <+1259>:	mov    DWORD PTR [rax+0x10],ecx
=> 0x00007ffff7f8a111 <+1265>:	mov    al,BYTE PTR [rbp-0x31]
   0x00007ffff7f8a114 <+1268>:	add    al,0x1
   0x00007ffff7f8a116 <+1270>:	mov    BYTE PTR [rbp-0x119],al
   0x00007ffff7f8a11c <+1276>:	setb   al
   0x00007ffff7f8a11f <+1279>:	test   al,0x1
   0x00007ffff7f8a121 <+1281>:	jne    0x7ffff7f8a127 <heap.SmpAllocator.alloc+1287>
   0x00007ffff7f8a123 <+1283>:	jmp    0x7ffff7f8a130 <heap.SmpAllocator.alloc+1296>
   0x00007ffff7f8a125 <+1285>:	jmp    0x7ffff7f8a0eb <heap.SmpAllocator.alloc+1227>
   0x00007ffff7f8a127 <+1287>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a12b <+1291>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a130 <+1296>:	mov    al,BYTE PTR [rbp-0x119]
   0x00007ffff7f8a136 <+1302>:	mov    BYTE PTR [rbp-0x31],al
   0x00007ffff7f8a139 <+1305>:	jmp    0x7ffff7f89d0f <heap.SmpAllocator.alloc+239>
End of assembler dump.
$1 = 140737346533032
Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 1
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 1
0x00007ffff7f89f3a in heap.SmpAllocator.alloc (context=0x0, len=107, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:163
163	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=107, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Old value = 1
New value = 2
heap.SmpAllocator.alloc (context=0x0, len=107, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:169
169	                search_count += 1;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 2
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 2
0x00007ffff7f89f3a in heap.SmpAllocator.alloc (context=0x0, len=14, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:163
163	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=14, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Old value = 2
New value = 3
heap.SmpAllocator.alloc (context=0x0, len=14, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:169
169	                search_count += 1;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 3
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 3
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 3
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 3
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 3
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 3
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 3
0x00007ffff7f89f3a in heap.SmpAllocator.alloc (context=0x0, len=37, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:163
163	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=37, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Old value = 3
New value = 4
heap.SmpAllocator.alloc (context=0x0, len=37, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:169
169	                search_count += 1;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 4
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 4
0x00007ffff7f89f3a in heap.SmpAllocator.alloc (context=0x0, len=14, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:163
163	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=14, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Old value = 4
New value = 5
heap.SmpAllocator.alloc (context=0x0, len=14, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:169
169	                search_count += 1;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 5
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 5
0x00007ffff7f89f3a in heap.SmpAllocator.alloc (context=0x0, len=20, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:163
163	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=20, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Old value = 5
New value = 6
heap.SmpAllocator.alloc (context=0x0, len=20, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:169
169	                search_count += 1;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 6
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 6
0x00007ffff7f89f3a in heap.SmpAllocator.alloc (context=0x0, len=16, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:163
163	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=16, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Old value = 6
New value = 7
heap.SmpAllocator.alloc (context=0x0, len=16, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:169
169	                search_count += 1;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 7
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 7
0x00007ffff7f89f3a in heap.SmpAllocator.alloc (context=0x0, len=23, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:163
163	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=23, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Old value = 7
New value = 8
heap.SmpAllocator.alloc (context=0x0, len=23, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:169
169	                search_count += 1;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 8
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 8
0x00007ffff7f89f3a in heap.SmpAllocator.alloc (context=0x0, len=15, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:163
163	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=15, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Old value = 8
New value = 9
heap.SmpAllocator.alloc (context=0x0, len=15, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:169
169	                search_count += 1;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 9
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 9
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 9
0x00007ffff7f89f3a in heap.SmpAllocator.alloc (context=0x0, len=96, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:163
163	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=96, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Old value = 9
New value = 10
heap.SmpAllocator.alloc (context=0x0, len=96, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:169
169	                search_count += 1;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 10
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 10
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 10
0x00007ffff7f89f3a in heap.SmpAllocator.alloc (context=0x0, len=15, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:163
163	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=15, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Old value = 10
New value = 11
heap.SmpAllocator.alloc (context=0x0, len=15, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:169
169	                search_count += 1;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 11
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 11
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 11
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 11
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 11
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 11
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 11
0x00007ffff7f89f3a in heap.SmpAllocator.alloc (context=0x0, len=199, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:163
163	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=199, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Old value = 11
New value = 0
heap.SmpAllocator.alloc (context=0x0, len=199, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:169
169	                search_count += 1;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 0
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 0
0x00007ffff7f89f3a in heap.SmpAllocator.alloc (context=0x0, len=15, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:163
163	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=15, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Old value = 0
New value = 1
heap.SmpAllocator.alloc (context=0x0, len=15, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:169
169	                search_count += 1;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 1
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 1
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 1
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 1
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 1
0x00007ffff7f89f3a in heap.SmpAllocator.alloc (context=0x0, len=55, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:163
163	        var index = thread_index;
Continuing.

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=55, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Old value = 1
New value = 2
heap.SmpAllocator.alloc (context=0x0, len=55, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:169
169	                search_count += 1;
Continuing.

Thread 2 "a.out" hit Hardware access (read/write) watchpoint 3: (unsigned long long)*0x7ffff78bf6b8

Value = 2
0x00007ffff7f8a27e in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Continuing.
[Thread 0x7ffff78bf6c0 (LWP 4699) exited]

Program terminated with signal SIGSEGV, Segmentation fault.
The program no longer exists.
No frame selected.
warning: Currently logging to gdb.c.  Turn the logging off and on to make the new setting effective.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[New Thread 0x7ffff78bf6c0 (LWP 4832)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff78bf6c0 (LWP 4832)]
0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Breakpoint 1 at 0x7ffff7f8a3ae: file /usr/lib/zig/std/heap/SmpAllocator.zig, line 89.
Breakpoint 2 at 0x7ffff7f8a0f0: file /usr/lib/zig/std/heap/SmpAllocator.zig, line 168.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".

Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=1032, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Continuing.

Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=32, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Continuing.
[New Thread 0x7ffff78bf6c0 (LWP 4834)]
[Switching to Thread 0x7ffff78bf6c0 (LWP 4834)]

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=21, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Continuing.

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=107, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Continuing.

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=14, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Continuing.

Thread 2 "a.out" hit Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=37, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Dump of assembler code for function heap.SmpAllocator.alloc:
   0x00007ffff7f89c20 <+0>:	push   rbp
   0x00007ffff7f89c21 <+1>:	mov    rbp,rsp
   0x00007ffff7f89c24 <+4>:	sub    rsp,0x120
   0x00007ffff7f89c2b <+11>:	mov    eax,ecx
   0x00007ffff7f89c2d <+13>:	mov    QWORD PTR [rbp-0x88],rdx
   0x00007ffff7f89c34 <+20>:	mov    rcx,rsi
   0x00007ffff7f89c37 <+23>:	mov    rsi,QWORD PTR [rbp-0x88]
   0x00007ffff7f89c3e <+30>:	mov    QWORD PTR [rbp-0x80],rdi
   0x00007ffff7f89c42 <+34>:	mov    BYTE PTR [rbp-0x71],al
   0x00007ffff7f89c45 <+37>:	mov    QWORD PTR [rbp-0x68],rcx
   0x00007ffff7f89c49 <+41>:	mov    QWORD PTR [rbp-0x60],rsi
   0x00007ffff7f89c4d <+45>:	mov    cl,al
   0x00007ffff7f89c4f <+47>:	and    cl,0x3f
   0x00007ffff7f89c52 <+50>:	mov    BYTE PTR [rbp-0x51],cl
   0x00007ffff7f89c55 <+53>:	mov    QWORD PTR [rbp-0x50],r8
   0x00007ffff7f89c59 <+57>:	movzx  edx,al
   0x00007ffff7f89c5c <+60>:	call   0x7ffff7f8a140 <heap.SmpAllocator.sizeClassIndex>
   0x00007ffff7f89c61 <+65>:	mov    QWORD PTR [rbp-0x70],rax
   0x00007ffff7f89c65 <+69>:	mov    QWORD PTR [rbp-0x48],rax
   0x00007ffff7f89c69 <+73>:	cmp    rax,0xd
   0x00007ffff7f89c6d <+77>:	jae    0x7ffff7f89c91 <heap.SmpAllocator.alloc+113>
   0x00007ffff7f89c6f <+79>:	jmp    0x7ffff7f89cb0 <heap.SmpAllocator.alloc+144>
   0x00007ffff7f89c71 <+81>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89c75 <+85>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89c79 <+89>:	call   0x7ffff7f8a200 <heap.SmpAllocator.slotSize>
   0x00007ffff7f89c7e <+94>:	mov    QWORD PTR [rbp-0x90],rax
   0x00007ffff7f89c85 <+101>:	mov    QWORD PTR [rbp-0x40],rax
   0x00007ffff7f89c89 <+105>:	cmp    rax,0x0
   0x00007ffff7f89c8d <+109>:	jne    0x7ffff7f89ce9 <heap.SmpAllocator.alloc+201>
   0x00007ffff7f89c8f <+111>:	jmp    0x7ffff7f89ceb <heap.SmpAllocator.alloc+203>
   0x00007ffff7f89c91 <+113>:	mov    rsi,QWORD PTR [rbp-0x88]
   0x00007ffff7f89c98 <+120>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89c9c <+124>:	mov    al,BYTE PTR [rbp-0x71]
   0x00007ffff7f89c9f <+127>:	movzx  edx,al
   0x00007ffff7f89ca2 <+130>:	call   0x7ffff7f889a0 <heap.PageAllocator.map>
   0x00007ffff7f89ca7 <+135>:	add    rsp,0x120
   0x00007ffff7f89cae <+142>:	pop    rbp
   0x00007ffff7f89caf <+143>:	ret
   0x00007ffff7f89cb0 <+144>:	jmp    0x7ffff7f89c71 <heap.SmpAllocator.alloc+81>
   0x00007ffff7f89cb2 <+146>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cb6 <+150>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89cbd <+157>:	mov    eax,0x10000
   0x00007ffff7f89cc2 <+162>:	xor    edx,edx
   0x00007ffff7f89cc4 <+164>:	div    rcx
   0x00007ffff7f89cc7 <+167>:	cmp    rdx,0x0
   0x00007ffff7f89ccb <+171>:	sete   al
   0x00007ffff7f89cce <+174>:	movzx  esi,al
   0x00007ffff7f89cd1 <+177>:	call   0x7ffff7ef2790 <debug.assert>
   0x00007ffff7f89cd6 <+182>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cda <+186>:	mov    BYTE PTR [rbp-0x31],0x0
   0x00007ffff7f89cde <+190>:	call   0x7ffff7f8a260 <heap.SmpAllocator.Thread.lock>
   0x00007ffff7f89ce3 <+195>:	mov    QWORD PTR [rbp-0x30],rax
   0x00007ffff7f89ce7 <+199>:	jmp    0x7ffff7f89cf4 <heap.SmpAllocator.alloc+212>
   0x00007ffff7f89ce9 <+201>:	jmp    0x7ffff7f89cb2 <heap.SmpAllocator.alloc+146>
   0x00007ffff7f89ceb <+203>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89cef <+207>:	call   0x7ffff7f10e70 <debug.FullPanic((function 'defaultPanic')).divideByZero>
   0x00007ffff7f89cf4 <+212>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89cf8 <+216>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89cfc <+220>:	add    rcx,0x68
   0x00007ffff7f89d00 <+224>:	mov    QWORD PTR [rbp-0x98],rcx
   0x00007ffff7f89d07 <+231>:	cmp    rax,0xd
   0x00007ffff7f89d0b <+235>:	jb     0x7ffff7f89d33 <heap.SmpAllocator.alloc+275>
   0x00007ffff7f89d0d <+237>:	jmp    0x7ffff7f89d35 <heap.SmpAllocator.alloc+277>
   0x00007ffff7f89d0f <+239>:	jmp    0x7ffff7f89cf4 <heap.SmpAllocator.alloc+212>
   0x00007ffff7f89d11 <+241>:	mov    rax,QWORD PTR [rbp-0x98]
   0x00007ffff7f89d18 <+248>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d1c <+252>:	mov    rax,QWORD PTR [rax+rcx*8]
   0x00007ffff7f89d20 <+256>:	mov    QWORD PTR [rbp-0xa0],rax
   0x00007ffff7f89d27 <+263>:	mov    QWORD PTR [rbp-0x28],rax
   0x00007ffff7f89d2b <+267>:	cmp    rax,0x0
   0x00007ffff7f89d2f <+271>:	jne    0x7ffff7f89d65 <heap.SmpAllocator.alloc+325>
   0x00007ffff7f89d31 <+273>:	jmp    0x7ffff7f89d74 <heap.SmpAllocator.alloc+340>
   0x00007ffff7f89d33 <+275>:	jmp    0x7ffff7f89d11 <heap.SmpAllocator.alloc+241>
   0x00007ffff7f89d35 <+277>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d39 <+281>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89d3d <+285>:	mov    edx,0xd
   0x00007ffff7f89d42 <+290>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89d47 <+295>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d4b <+299>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89d4f <+303>:	mov    QWORD PTR [rbp-0xa8],rcx
   0x00007ffff7f89d56 <+310>:	cmp    rax,0xd
   0x00007ffff7f89d5a <+314>:	jb     0x7ffff7f89e37 <heap.SmpAllocator.alloc+535>
   0x00007ffff7f89d60 <+320>:	jmp    0x7ffff7f89e39 <heap.SmpAllocator.alloc+537>
   0x00007ffff7f89d65 <+325>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d6c <+332>:	cmp    rax,0x0
   0x00007ffff7f89d70 <+336>:	jne    0x7ffff7f89d89 <heap.SmpAllocator.alloc+361>
   0x00007ffff7f89d72 <+338>:	jmp    0x7ffff7f89d8b <heap.SmpAllocator.alloc+363>
   0x00007ffff7f89d74 <+340>:	jmp    0x7ffff7f89d47 <heap.SmpAllocator.alloc+295>
   0x00007ffff7f89d76 <+342>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d7d <+349>:	and    rax,0x7
   0x00007ffff7f89d81 <+353>:	cmp    rax,0x0
   0x00007ffff7f89d85 <+357>:	je     0x7ffff7f89dba <heap.SmpAllocator.alloc+410>
   0x00007ffff7f89d87 <+359>:	jmp    0x7ffff7f89dbc <heap.SmpAllocator.alloc+412>
   0x00007ffff7f89d89 <+361>:	jmp    0x7ffff7f89d76 <heap.SmpAllocator.alloc+342>
   0x00007ffff7f89d8b <+363>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89d8f <+367>:	call   0x7ffff7efa8d0 <debug.FullPanic((function 'defaultPanic')).castToNull>
   0x00007ffff7f89d94 <+372>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89d98 <+376>:	mov    rcx,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89d9f <+383>:	mov    QWORD PTR [rbp-0x20],rcx
   0x00007ffff7f89da3 <+387>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89da7 <+391>:	add    rcx,0x68
   0x00007ffff7f89dab <+395>:	mov    QWORD PTR [rbp-0xb0],rcx
   0x00007ffff7f89db2 <+402>:	cmp    rax,0xd
   0x00007ffff7f89db6 <+406>:	jb     0x7ffff7f89dfb <heap.SmpAllocator.alloc+475>
   0x00007ffff7f89db8 <+408>:	jmp    0x7ffff7f89dfd <heap.SmpAllocator.alloc+477>
   0x00007ffff7f89dba <+410>:	jmp    0x7ffff7f89d94 <heap.SmpAllocator.alloc+372>
   0x00007ffff7f89dbc <+412>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89dc0 <+416>:	call   0x7ffff7ef5d30 <debug.FullPanic((function 'defaultPanic')).incorrectAlignment>
   0x00007ffff7f89dc5 <+421>:	mov    rdx,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89dcc <+428>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89dd0 <+432>:	mov    rax,QWORD PTR [rbp-0xb0]
   0x00007ffff7f89dd7 <+439>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89ddb <+443>:	mov    rdx,QWORD PTR [rdx]
   0x00007ffff7f89dde <+446>:	mov    QWORD PTR [rax+rcx*8],rdx
   0x00007ffff7f89de2 <+450>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89de6 <+454>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89deb <+459>:	mov    rax,QWORD PTR [rbp-0xa0]
   0x00007ffff7f89df2 <+466>:	add    rsp,0x120
   0x00007ffff7f89df9 <+473>:	pop    rbp
   0x00007ffff7f89dfa <+474>:	ret
   0x00007ffff7f89dfb <+475>:	jmp    0x7ffff7f89dc5 <heap.SmpAllocator.alloc+421>
   0x00007ffff7f89dfd <+477>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e01 <+481>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89e05 <+485>:	mov    edx,0xd
   0x00007ffff7f89e0a <+490>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89e0f <+495>:	mov    rax,QWORD PTR [rbp-0xa8]
   0x00007ffff7f89e16 <+502>:	mov    rcx,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e1a <+506>:	mov    rax,QWORD PTR [rax+rcx*8]
   0x00007ffff7f89e1e <+510>:	mov    QWORD PTR [rbp-0xb8],rax
   0x00007ffff7f89e25 <+517>:	mov    QWORD PTR [rbp-0x18],rax
   0x00007ffff7f89e29 <+521>:	and    rax,0xffff
   0x00007ffff7f89e2f <+527>:	cmp    rax,0x0
   0x00007ffff7f89e33 <+531>:	jne    0x7ffff7f89e5a <heap.SmpAllocator.alloc+570>
   0x00007ffff7f89e35 <+533>:	jmp    0x7ffff7f89e71 <heap.SmpAllocator.alloc+593>
   0x00007ffff7f89e37 <+535>:	jmp    0x7ffff7f89e0f <heap.SmpAllocator.alloc+495>
   0x00007ffff7f89e39 <+537>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e3d <+541>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89e41 <+545>:	mov    edx,0xd
   0x00007ffff7f89e46 <+550>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89e4b <+555>:	cmp    BYTE PTR [rbp-0x31],0x1
   0x00007ffff7f89e4f <+559>:	jae    0x7ffff7f89f42 <heap.SmpAllocator.alloc+802>
   0x00007ffff7f89e55 <+565>:	jmp    0x7ffff7f89f70 <heap.SmpAllocator.alloc+848>
   0x00007ffff7f89e5a <+570>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e5e <+574>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89e62 <+578>:	mov    QWORD PTR [rbp-0xc0],rcx
   0x00007ffff7f89e69 <+585>:	cmp    rax,0xd
   0x00007ffff7f89e6d <+589>:	jb     0x7ffff7f89eab <heap.SmpAllocator.alloc+651>
   0x00007ffff7f89e6f <+591>:	jmp    0x7ffff7f89ead <heap.SmpAllocator.alloc+653>
   0x00007ffff7f89e71 <+593>:	jmp    0x7ffff7f89e4b <heap.SmpAllocator.alloc+555>
   0x00007ffff7f89e73 <+595>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89e7a <+602>:	mov    rax,QWORD PTR [rbp-0xb8]
   0x00007ffff7f89e81 <+609>:	mov    rdx,QWORD PTR [rbp-0xc0]
   0x00007ffff7f89e88 <+616>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89e8c <+620>:	shl    rsi,0x3
   0x00007ffff7f89e90 <+624>:	add    rdx,rsi
   0x00007ffff7f89e93 <+627>:	mov    QWORD PTR [rbp-0xd0],rdx
   0x00007ffff7f89e9a <+634>:	add    rax,rcx
   0x00007ffff7f89e9d <+637>:	mov    QWORD PTR [rbp-0xc8],rax
   0x00007ffff7f89ea4 <+644>:	setb   al
   0x00007ffff7f89ea7 <+647>:	jb     0x7ffff7f89ebf <heap.SmpAllocator.alloc+671>
   0x00007ffff7f89ea9 <+649>:	jmp    0x7ffff7f89ec8 <heap.SmpAllocator.alloc+680>
   0x00007ffff7f89eab <+651>:	jmp    0x7ffff7f89e73 <heap.SmpAllocator.alloc+595>
   0x00007ffff7f89ead <+653>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89eb1 <+657>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89eb5 <+661>:	mov    edx,0xd
   0x00007ffff7f89eba <+666>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f89ebf <+671>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89ec3 <+675>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f89ec8 <+680>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89ecc <+684>:	mov    rax,QWORD PTR [rbp-0xd0]
   0x00007ffff7f89ed3 <+691>:	mov    rcx,QWORD PTR [rbp-0xc8]
   0x00007ffff7f89eda <+698>:	mov    QWORD PTR [rax],rcx
   0x00007ffff7f89edd <+701>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89ee1 <+705>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89ee6 <+710>:	mov    rax,QWORD PTR [rbp-0xb8]
   0x00007ffff7f89eed <+717>:	add    rsp,0x120
   0x00007ffff7f89ef4 <+724>:	pop    rbp
   0x00007ffff7f89ef5 <+725>:	ret
   0x00007ffff7f89ef6 <+726>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89efa <+730>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89efe <+734>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89f03 <+739>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f07 <+743>:	call   0x7ffff7f8a410 <heap.SmpAllocator.getCpuCount>
   0x00007ffff7f89f0c <+748>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f10 <+752>:	mov    ecx,eax
   0x00007ffff7f89f12 <+754>:	mov    DWORD PTR [rbp-0xd4],ecx
   0x00007ffff7f89f18 <+760>:	mov    DWORD PTR [rbp-0x8],eax
   0x00007ffff7f89f1b <+763>:	test   eax,eax
   0x00007ffff7f89f1d <+765>:	setne  al
   0x00007ffff7f89f20 <+768>:	movzx  esi,al
   0x00007ffff7f89f23 <+771>:	call   0x7ffff7ef2790 <debug.assert>
   0x00007ffff7f89f28 <+776>:	lea    rdi,[rip+0x27bf1]        # 0x7ffff7fb1b20
   0x00007ffff7f89f2f <+783>:	call   0x7ffff7fae630 <__tls_get_addr@plt>
   0x00007ffff7f89f34 <+788>:	mov    eax,DWORD PTR [rax+0x10]
   0x00007ffff7f89f3a <+794>:	mov    DWORD PTR [rbp-0x4],eax
   0x00007ffff7f89f3d <+797>:	jmp    0x7ffff7f8a046 <heap.SmpAllocator.alloc+1062>
   0x00007ffff7f89f42 <+802>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f46 <+806>:	mov    esi,0x10000
   0x00007ffff7f89f4b <+811>:	call   0x7ffff7f18cd0 <mem.Alignment.fromByteUnits>
   0x00007ffff7f89f50 <+816>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89f54 <+820>:	movzx  edx,al
   0x00007ffff7f89f57 <+823>:	mov    esi,0x10000
   0x00007ffff7f89f5c <+828>:	call   0x7ffff7f889a0 <heap.PageAllocator.map>
   0x00007ffff7f89f61 <+833>:	mov    QWORD PTR [rbp-0xe0],rax
   0x00007ffff7f89f68 <+840>:	cmp    rax,0x0
   0x00007ffff7f89f6c <+844>:	jne    0x7ffff7f89f9b <heap.SmpAllocator.alloc+891>
   0x00007ffff7f89f6e <+846>:	jmp    0x7ffff7f89fab <heap.SmpAllocator.alloc+907>
   0x00007ffff7f89f70 <+848>:	jmp    0x7ffff7f89ef6 <heap.SmpAllocator.alloc+726>
   0x00007ffff7f89f72 <+850>:	mov    rax,QWORD PTR [rbp-0x70]
   0x00007ffff7f89f76 <+854>:	mov    rcx,QWORD PTR [rbp-0xf8]
   0x00007ffff7f89f7d <+861>:	mov    QWORD PTR [rbp-0xf0],rcx
   0x00007ffff7f89f84 <+868>:	mov    QWORD PTR [rbp-0x10],rcx
   0x00007ffff7f89f88 <+872>:	mov    rcx,QWORD PTR [rbp-0x30]
   0x00007ffff7f89f8c <+876>:	mov    QWORD PTR [rbp-0xe8],rcx
   0x00007ffff7f89f93 <+883>:	cmp    rax,0xd
   0x00007ffff7f89f97 <+887>:	jb     0x7ffff7f89ffb <heap.SmpAllocator.alloc+987>
   0x00007ffff7f89f99 <+889>:	jmp    0x7ffff7f89ffd <heap.SmpAllocator.alloc+989>
   0x00007ffff7f89f9b <+891>:	mov    rax,QWORD PTR [rbp-0xe0]
   0x00007ffff7f89fa2 <+898>:	mov    QWORD PTR [rbp-0xf8],rax
   0x00007ffff7f89fa9 <+905>:	jmp    0x7ffff7f89f72 <heap.SmpAllocator.alloc+850>
   0x00007ffff7f89fab <+907>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f89faf <+911>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f89fb3 <+915>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f89fb8 <+920>:	xor    eax,eax
   0x00007ffff7f89fba <+922>:	add    rsp,0x120
   0x00007ffff7f89fc1 <+929>:	pop    rbp
   0x00007ffff7f89fc2 <+930>:	ret
   0x00007ffff7f89fc3 <+931>:	mov    rcx,QWORD PTR [rbp-0x90]
   0x00007ffff7f89fca <+938>:	mov    rax,QWORD PTR [rbp-0xf0]
   0x00007ffff7f89fd1 <+945>:	mov    rdx,QWORD PTR [rbp-0xe8]
   0x00007ffff7f89fd8 <+952>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f89fdc <+956>:	shl    rsi,0x3
   0x00007ffff7f89fe0 <+960>:	add    rdx,rsi
   0x00007ffff7f89fe3 <+963>:	mov    QWORD PTR [rbp-0x108],rdx
   0x00007ffff7f89fea <+970>:	add    rax,rcx
   0x00007ffff7f89fed <+973>:	mov    QWORD PTR [rbp-0x100],rax
   0x00007ffff7f89ff4 <+980>:	setb   al
   0x00007ffff7f89ff7 <+983>:	jb     0x7ffff7f8a00f <heap.SmpAllocator.alloc+1007>
   0x00007ffff7f89ff9 <+985>:	jmp    0x7ffff7f8a018 <heap.SmpAllocator.alloc+1016>
   0x00007ffff7f89ffb <+987>:	jmp    0x7ffff7f89fc3 <heap.SmpAllocator.alloc+931>
   0x00007ffff7f89ffd <+989>:	mov    rsi,QWORD PTR [rbp-0x70]
   0x00007ffff7f8a001 <+993>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a005 <+997>:	mov    edx,0xd
   0x00007ffff7f8a00a <+1002>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f8a00f <+1007>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a013 <+1011>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a018 <+1016>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a01c <+1020>:	mov    rax,QWORD PTR [rbp-0x108]
   0x00007ffff7f8a023 <+1027>:	mov    rcx,QWORD PTR [rbp-0x100]
   0x00007ffff7f8a02a <+1034>:	mov    QWORD PTR [rax],rcx
   0x00007ffff7f8a02d <+1037>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f8a031 <+1041>:	call   0x7ffff7f8a3e0 <heap.SmpAllocator.Thread.unlock>
   0x00007ffff7f8a036 <+1046>:	mov    rax,QWORD PTR [rbp-0xf0]
   0x00007ffff7f8a03d <+1053>:	add    rsp,0x120
   0x00007ffff7f8a044 <+1060>:	pop    rbp
   0x00007ffff7f8a045 <+1061>:	ret
   0x00007ffff7f8a046 <+1062>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a049 <+1065>:	add    eax,0x1
   0x00007ffff7f8a04c <+1068>:	mov    DWORD PTR [rbp-0x10c],eax
   0x00007ffff7f8a052 <+1074>:	setb   al
   0x00007ffff7f8a055 <+1077>:	jb     0x7ffff7f8a059 <heap.SmpAllocator.alloc+1081>
   0x00007ffff7f8a057 <+1079>:	jmp    0x7ffff7f8a062 <heap.SmpAllocator.alloc+1090>
   0x00007ffff7f8a059 <+1081>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a05d <+1085>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a062 <+1090>:	mov    eax,DWORD PTR [rbp-0xd4]
   0x00007ffff7f8a068 <+1096>:	cmp    eax,0x0
   0x00007ffff7f8a06b <+1099>:	jne    0x7ffff7f8a096 <heap.SmpAllocator.alloc+1142>
   0x00007ffff7f8a06d <+1101>:	jmp    0x7ffff7f8a098 <heap.SmpAllocator.alloc+1144>
   0x00007ffff7f8a06f <+1103>:	mov    ecx,DWORD PTR [rbp-0xd4]
   0x00007ffff7f8a075 <+1109>:	mov    eax,DWORD PTR [rbp-0x10c]
   0x00007ffff7f8a07b <+1115>:	xor    edx,edx
   0x00007ffff7f8a07d <+1117>:	div    ecx
   0x00007ffff7f8a07f <+1119>:	mov    DWORD PTR [rbp-0x4],edx
   0x00007ffff7f8a082 <+1122>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a085 <+1125>:	mov    QWORD PTR [rbp-0x118],rax
   0x00007ffff7f8a08c <+1132>:	cmp    rax,0x80
   0x00007ffff7f8a092 <+1138>:	jb     0x7ffff7f8a0d4 <heap.SmpAllocator.alloc+1204>
   0x00007ffff7f8a094 <+1140>:	jmp    0x7ffff7f8a0d6 <heap.SmpAllocator.alloc+1206>
   0x00007ffff7f8a096 <+1142>:	jmp    0x7ffff7f8a06f <heap.SmpAllocator.alloc+1103>
   0x00007ffff7f8a098 <+1144>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a09c <+1148>:	call   0x7ffff7f10e70 <debug.FullPanic((function 'defaultPanic')).divideByZero>
   0x00007ffff7f8a0a1 <+1153>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a0a5 <+1157>:	mov    rcx,QWORD PTR [rbp-0x118]
   0x00007ffff7f8a0ac <+1164>:	lea    rax,[rip+0x29fcd]        # 0x7ffff7fb4080 <heap.SmpAllocator.global>
   0x00007ffff7f8a0b3 <+1171>:	shl    rcx,0x8
   0x00007ffff7f8a0b7 <+1175>:	add    rax,rcx
   0x00007ffff7f8a0ba <+1178>:	mov    QWORD PTR [rbp-0x30],rax
   0x00007ffff7f8a0be <+1182>:	mov    rsi,QWORD PTR [rbp-0x30]
   0x00007ffff7f8a0c2 <+1186>:	add    rsi,0xd0
   0x00007ffff7f8a0c9 <+1193>:	call   0x7ffff7f8a4e0 <Thread.Mutex.tryLock>
   0x00007ffff7f8a0ce <+1198>:	test   al,0x1
   0x00007ffff7f8a0d0 <+1200>:	jne    0x7ffff7f8a0f0 <heap.SmpAllocator.alloc+1232>
   0x00007ffff7f8a0d2 <+1202>:	jmp    0x7ffff7f8a125 <heap.SmpAllocator.alloc+1285>
   0x00007ffff7f8a0d4 <+1204>:	jmp    0x7ffff7f8a0a1 <heap.SmpAllocator.alloc+1153>
   0x00007ffff7f8a0d6 <+1206>:	mov    rsi,QWORD PTR [rbp-0x118]
   0x00007ffff7f8a0dd <+1213>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a0e1 <+1217>:	mov    edx,0x80
   0x00007ffff7f8a0e6 <+1222>:	call   0x7ffff7eefe90 <debug.FullPanic((function 'defaultPanic')).outOfBounds>
   0x00007ffff7f8a0eb <+1227>:	jmp    0x7ffff7f8a046 <heap.SmpAllocator.alloc+1062>
=> 0x00007ffff7f8a0f0 <+1232>:	mov    eax,DWORD PTR [rbp-0x4]
   0x00007ffff7f8a0f3 <+1235>:	mov    DWORD PTR [rbp-0x120],eax
   0x00007ffff7f8a0f9 <+1241>:	lea    rdi,[rip+0x27a20]        # 0x7ffff7fb1b20
   0x00007ffff7f8a100 <+1248>:	call   0x7ffff7fae630 <__tls_get_addr@plt>
   0x00007ffff7f8a105 <+1253>:	mov    ecx,DWORD PTR [rbp-0x120]
   0x00007ffff7f8a10b <+1259>:	mov    DWORD PTR [rax+0x10],ecx
   0x00007ffff7f8a111 <+1265>:	mov    al,BYTE PTR [rbp-0x31]
   0x00007ffff7f8a114 <+1268>:	add    al,0x1
   0x00007ffff7f8a116 <+1270>:	mov    BYTE PTR [rbp-0x119],al
   0x00007ffff7f8a11c <+1276>:	setb   al
   0x00007ffff7f8a11f <+1279>:	test   al,0x1
   0x00007ffff7f8a121 <+1281>:	jne    0x7ffff7f8a127 <heap.SmpAllocator.alloc+1287>
   0x00007ffff7f8a123 <+1283>:	jmp    0x7ffff7f8a130 <heap.SmpAllocator.alloc+1296>
   0x00007ffff7f8a125 <+1285>:	jmp    0x7ffff7f8a0eb <heap.SmpAllocator.alloc+1227>
   0x00007ffff7f8a127 <+1287>:	mov    rdi,QWORD PTR [rbp-0x80]
   0x00007ffff7f8a12b <+1291>:	call   0x7ffff7eeaf80 <debug.FullPanic((function 'defaultPanic')).integerOverflow>
   0x00007ffff7f8a130 <+1296>:	mov    al,BYTE PTR [rbp-0x119]
   0x00007ffff7f8a136 <+1302>:	mov    BYTE PTR [rbp-0x31],al
   0x00007ffff7f8a139 <+1305>:	jmp    0x7ffff7f89d0f <heap.SmpAllocator.alloc+239>
End of assembler dump.
Dump of assembler code for function __tls_get_addr@plt:
   0x00007ffff7fae630 <+0>:	jmp    QWORD PTR [rip+0x35a2]        # 0x7ffff7fb1bd8 <__tls_get_addr@got.plt>
   0x00007ffff7fae636 <+6>:	push   0x12
   0x00007ffff7fae63b <+11>:	jmp    0x7ffff7fae500
End of assembler dump.
Undefined info command: "0x7ffff7fae500".  Try "help info".
Dump of assembler code for function __ubsan_handle_vla_bound_not_positive@got.plt:
   0x00007ffff7fb1bd0 <+0>:	push   rax
   0x00007ffff7fb1bd1 <+1>:	imul   dh
   0x00007ffff7fb1bd3 <+3>:	idiv   edi
   0x00007ffff7fb1bd5 <+5>:	jg     0x7ffff7fb1bd7 <__ubsan_handle_vla_bound_not_positive@got.plt+7>
   0x00007ffff7fb1bd7 <+7>:	add    BYTE PTR [rax],al
End of assembler dump.
No function contains specified address.
   0x7ffff7fae500:	push   QWORD PTR [rip+0x3632]        # 0x7ffff7fb1b38
   0x7ffff7fae506:	jmp    QWORD PTR [rip+0x3634]        # 0x7ffff7fb1b40
   0x7ffff7fae50c:	nop    DWORD PTR [rax+0x0]
   0x7ffff7fae510 <__ubsan_handle_add_overflow@plt>:	jmp    QWORD PTR [rip+0x3632]        # 0x7ffff7fb1b48 <__ubsan_handle_add_overflow@got.plt>
   0x7ffff7fae516 <__ubsan_handle_add_overflow@plt+6>:	push   0x0
   0x7ffff7fae51b <__ubsan_handle_add_overflow@plt+11>:	jmp    0x7ffff7fae500
   0x7ffff7fae520 <__zig_probe_stack@plt>:	jmp    QWORD PTR [rip+0x362a]        # 0x7ffff7fb1b50 <__zig_probe_stack@got.plt>
   0x7ffff7fae526 <__zig_probe_stack@plt+6>:	push   0x1
   0x7ffff7fae52b <__zig_probe_stack@plt+11>:	jmp    0x7ffff7fae500
   0x7ffff7fae530 <memset@plt>:	jmp    QWORD PTR [rip+0x3622]        # 0x7ffff7fb1b58 <memset@got.plt>
Breakpoint 3 at 0x7ffff7fb1bd2
Quit
Starting program: /home/feniljain/Projects/zig-projects/smp-alloc/mimalloc-bench/bench/alloc-test/a.out 1
Warning:
Cannot insert breakpoint 3.
Cannot access memory at address 0x7ffff7fb1bd2

Command aborted.
Starting program: /home/feniljain/Projects/zig-projects/smp-alloc/mimalloc-bench/bench/alloc-test/a.out 1
Warning:
Cannot insert breakpoint 3.
Cannot access memory at address 0x7ffff7fb1bd2

Command aborted.
Starting program: /home/feniljain/Projects/zig-projects/smp-alloc/mimalloc-bench/bench/alloc-test/a.out 1
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[New Thread 0x7ffff78bf6c0 (LWP 5326)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff78bf6c0 (LWP 5326)]
0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Breakpoint 4 at 0x7ffff7fb1bd2
Starting program: /home/feniljain/Projects/zig-projects/smp-alloc/mimalloc-bench/bench/alloc-test/a.out 1
Warning:
Cannot insert breakpoint 4.
Cannot access memory at address 0x7ffff7fb1bd2

Command aborted.
Quit
warning: Currently logging to gdb.c.  Turn the logging off and on to make the new setting effective.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[New Thread 0x7ffff78bf6c0 (LWP 5382)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff78bf6c0 (LWP 5382)]
0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Breakpoint 1 at 0x7ffff7f8a3ae: file /usr/lib/zig/std/heap/SmpAllocator.zig, line 89.
Breakpoint 2 at 0x7ffff7f8a0f0: file /usr/lib/zig/std/heap/SmpAllocator.zig, line 168.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".

Breakpoint 2, heap.SmpAllocator.alloc (context=0x0, len=1032, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
warning: Currently logging to gdb.c.  Turn the logging off and on to make the new setting effective.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[New Thread 0x7ffff78bf6c0 (LWP 5426)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff78bf6c0 (LWP 5426)]
0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Breakpoint 1 at 0x7ffff7f8a3ae: file /usr/lib/zig/std/heap/SmpAllocator.zig, line 89.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[New Thread 0x7ffff78bf6c0 (LWP 5428)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff78bf6c0 (LWP 5428)]
0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
warning: Currently logging to gdb.c.  Turn the logging off and on to make the new setting effective.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".
[New Thread 0x7ffff78bf6c0 (LWP 5477)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff78bf6c0 (LWP 5477)]
0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
Breakpoint 1 at 0x7ffff7f8a0f0: file /usr/lib/zig/std/heap/SmpAllocator.zig, line 168.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/usr/lib/libthread_db.so.1".

Breakpoint 1, heap.SmpAllocator.alloc (context=0x0, len=1032, alignment=1, ra=140737353643937) at /usr/lib/zig/std/heap/SmpAllocator.zig:168
168	                thread_index = index;
Breakpoint 2 at 0x7ffff7fb1bd2
[New Thread 0x7ffff78bf6c0 (LWP 5479)]

Thread 2 "a.out" received signal SIGSEGV, Segmentation fault.
[Switching to Thread 0x7ffff78bf6c0 (LWP 5479)]
0x00007ffff7f8a278 in heap.SmpAllocator.Thread.lock () at /usr/lib/zig/std/heap/SmpAllocator.zig:75
75	        var index = thread_index;
