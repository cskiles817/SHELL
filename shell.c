#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

void interactiveMode() {
    char *line = NULL;
    size_t length = 0;
    int lineNumber = 1;

    while (1) {
        printf("wish> ");
        fflush(stdout);

        ssize_t read = getline(&line, &length, stdin);
        if (read == -1) {
            break;
        }

        if (line[read - 1] == '\n') {
            line[read - 1] = '\0';
        }
        printf("line%d: %s\n", lineNumber, line);
        lineNumber++;
    }
    free(line);
}

void batchMode(char *filename) {
    FILE *file = fopen(filename, "r"); // r --> open for reading
    char *line = NULL;
    size_t length = 0;
    int lineNumber = 1;

    if (file == NULL) {
        fprintf(stderr, "Can't open %s\n", filename);
        exit(1);
    }
    while (getline(&line, &length, file) != -1) {
        size_t len = strlen(line);  //size_t <-- used for array index
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        printf("line%d: %s\n", lineNumber, line);
        lineNumber++;
    }
    free(line);
    fclose(file);
}
