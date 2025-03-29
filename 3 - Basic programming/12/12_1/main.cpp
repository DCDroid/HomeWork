#include"manual_test.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void segfault_sigaction(int signal, siginfo_t *si, void *arg)
{
    std::cout << "Test error! We can not caught this fault" << std::endl;
    exit(0);
}

int main() 
{
    struct sigaction sa;

    memset(&sa, 0, sizeof(struct sigaction));
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = segfault_sigaction;
    sa.sa_flags   = SA_SIGINFO;

    sigaction(SIGSEGV, &sa, NULL);

    RunOneTest(test_mean, "Mean test");
    RunOneTest(test_empty_mean, "Mean test, empty array");
    RunOneTest(test_median, "Median test");
    RunOneTest(test_empty_median, "Median test, empty array");
    RunOneTest(test_mode, "Mode test");
    RunOneTest(test_empty_mode, "Mode test, empty array");
    return 0;
}

