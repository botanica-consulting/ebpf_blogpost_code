#! /bin/bash

sudo bpftool prog load bpf.o /sys/fs/bpf/execve_trace autoattach

