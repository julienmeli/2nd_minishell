#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

void	change_directory(char *path) 
{
    if (path == NULL) 
    {
        path = getenv("HOME"); // Default to HOME if no argument
    }

    if (chdir(path) != 0) 
    {
        perror("cd"); // Print error if chdir fails
    }
}

int	main() 
{
	char	input[BUFFER_SIZE];
	ssize_t	length;
	ssize_t	i;
	char	*command;
        char	*arg;

	while (1) 
	{
        	// Print prompt
        	write(STDOUT_FILENO, "minishell> ", 11);

        	// Read input from stdin
        	length = read(STDIN_FILENO, input, BUFFER_SIZE - 1);
        	if (length <= 0) 
		{
            		write(STDOUT_FILENO, "\n", 1);
            		break; // Exit on Ctrl+D
        	}

        	// Manually remove the newline if present
        	if (input[length - 1] == '\n') 
		{
            		input[length - 1] = '\0';
        	}
		else 
		{
            		input[length] = '\0';
        	}

        // Manually extract command and argument
        command = input;
        arg = NULL;

        // Find the first space (to separate command and argument)
		i = 0;
		while (i < length)
		{
			if (input[i] == ' ')
			{
			input[i] = '\0';
			arg = &input[i + 1];
				break ;
			}
			i++;
		}
	/*
        for (int i = 0; i < length; i++) {
            if (input[i] == ' ') {
                input[i] = '\0'; // Null-terminate the command
                arg = &input[i + 1]; // The argument starts after the space
                break;
            }
        }
	*/
        // Execute the command
        	if (strcmp(command, "cd") == 0) 
		{
            	change_directory(arg);
        	}	 
		else 
		{
            	write(STDOUT_FILENO, "Command not recognized: ", 24);
            	write(STDOUT_FILENO, command, strlen(command));
            	write(STDOUT_FILENO, "\n", 1);
        	}
    }
    return 0;
}

