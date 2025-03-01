#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void change_directory(char *path) {
    if (path == NULL) {
        path = getenv("HOME"); // Default to HOME if no argument
    }

    if (chdir(path) != 0) {
        perror("cd"); // Print error if chdir fails
    }
}

int main() {
    char input[BUFFER_SIZE];

    while (1) {
        printf("minishell> ");  
        if (!fgets(input, BUFFER_SIZE, stdin)) {
            printf("\n");
            break;  // Exit on Ctrl+D
        }

        input[strcspn(input, "\n")] = 0; // Remove newline character

        // Tokenize input
        char *command = strtok(input, " ");
        char *arg = strtok(NULL, " "); // Get the next token (directory)

        if (command == NULL) continue; // Skip empty input

        if (strcmp(command, "cd") == 0) {
            change_directory(arg);
        } else {
            printf("Command not recognized: %s\n", command);
        }
    }

    return 0;
}

