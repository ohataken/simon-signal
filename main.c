#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

void sigwinch_hander(int signo) {
    struct winsize w;
    ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
    printf("sigwinch_handler has been called (h: %d, w: %d)\n", w.ws_row, w.ws_col);
}

int main(void) {
    if (signal(SIGWINCH, sigwinch_hander) == SIG_ERR) {
        printf("handler binding failed.\n");
        exit(EXIT_FAILURE);
    }

    while (1)
        pause();

    return 0;
}
