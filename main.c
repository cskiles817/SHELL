#include <stdio.h> // IO & fprintf & stderr
#include <stdlib.h> // exit
#include "shell.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        interactiveMode();
    } else if (argc == 2) {
        batchMode(argv[1]);
    } else {
        fprintf(stderr, "Uses: %s [filename]\n", argv[0]);
        exit(1);
    }
    return 0;
}

