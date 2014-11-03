#include <stdio.h>
#include <stdlib.h>
#include "terminal.h"

int main()
{
    printf("Hello world!\n");
    return 0;
}

int kbhit(void)
{
    struct timeval tv = { 0, 0 };
    fd_set readfds;

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    return select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv) == 1;
}
