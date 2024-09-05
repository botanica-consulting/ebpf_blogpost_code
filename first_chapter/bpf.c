#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

char LICENSE[] SEC("license") = "GPL";

struct sys_enter_execve {
    __u64 unused;
    __u32 nr;
    __u32 pad;
    const char *filename;
    const char *const *argv;
    const char *const *envp;
};

SEC("tracepoint/syscalls/sys_enter_execve")
int hello_world(struct sys_enter_execve *ctx) {
    __u32 pid = (__u32)(bpf_get_current_pid_tgid() >> 32);
    char comm[128];

    if (0 == bpf_get_current_comm(comm, sizeof(comm))) {
	    /* We are reading the execed parameter from user space */
	    char execed[128];
	    if (0 < bpf_probe_read_user_str(execed, sizeof(execed), ctx->filename)) {
	    	bpf_printk("%s just execed, with pid %d the program %s\n", comm, pid, execed);
	    }
    }

    return 0;
}


