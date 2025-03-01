#include "minishell.h"

char	*find_executable(char *command)
{
	char	*path;
/*	char	*path_copy;
	char	*dir;
	char	full_path[BUFFER_SIZE];
*/	
	(void)command;
	path = getenv("PATH");
	puts(path);
	return (path);
/*	path_copy = ft_strdup(path);
	dir = ft_split(path_copy, ':');
	while (dir)
	{
		if (access
	}*/
}

int	execute_command(char **args)
{
	char	*command_path;

	if (!args[0])
		return (1);
	if (ft_strchr(args[0], '/'))
	{
		execve(args[0], args, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	command_path = find_executable(args[0]);
	return (0);
}

int	slash_looking(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == '/')
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}
