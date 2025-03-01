#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>

int main() {
    char *input;
    char	*folder;

    while (1) {
        input = readline("minishell> "); // Display prompt and get input
        if (!input) {
            printf("\n");
            break; // Exit on EOF (Ctrl+D)
        }

        if (*input) // Add input to history if not empty
            add_history(input);
	
	if (strcmp(input, "cd folder") == 0)
	{
		puts("mais oui");
		folder = "folder";
		chdir(folder);
	}
        printf("You entered: %s\n", input);
        free(input); // Free the allocated input
    }

    return 0;
}
