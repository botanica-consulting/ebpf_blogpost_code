# Code repository for eBPF blog post series
This repo contains the code that goes alongside our eBPF blog post series

## First Chapter - Hacking eBPF & LLVM for Fun and Profit
[In this first post](https://www.botanica.software/post/hacking-ebpf-llvm-for-fun-and-profit) we describe the basic setup for adding a toy `MachineFunctionPass` to llvm.
The files included (under `first_chapter`) are:
1. `0001-Added-capability-to-print-number-of-machine-instruct.patch` - a patchfile which adds our `MachineFunctionPass`
2. `bpf.c` - a simple "Hello World" in eBPF to test our pass on
3. `compile_bpf.sh` - commandline to build `bpf.c`
4. `load_and_attach.sh` - commandline to load and attach the program
5. `detach_program.sh` - commandline to detach it
6. `print_trace.sh` - auxiliary command to print trace we issue in `bpf.c`

   
