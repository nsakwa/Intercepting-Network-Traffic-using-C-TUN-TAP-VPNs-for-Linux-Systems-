#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/if_tun.h>
#include <errno.h>

#define CLEAR(s) memset((s), 0, sizeof(s))

void print_error(const char *msg, ...) {
    va_list args;
    va_start(args, msg);
    vfprintf(stderr, msg, args);
    va_end(args);
    fprintf(stderr, "\n");
}

int tun_alloc(char *dev) {
    // ... (your provided code) ...
}

int main(int argc, char *argv[]) {
    char tun_name[IFNAMSIZ];
    strcpy(tun_name, "tun%d"); //you can change the name.
    int tun_fd = tun_alloc(tun_name);
    if (tun_fd < 0) {
        return 1;
    }
    printf("TUN/TAP device %s opened.\n", tun_name);
    // Add code to read/write from tun_fd here
    close(tun_fd);
    return 0;
}