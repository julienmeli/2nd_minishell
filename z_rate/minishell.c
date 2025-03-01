#include "minishell.h"

int	jsh_launch(char **args)
{
	pid_t	pid;
	pid_t	wpid;
	int	status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		//return (1);
	}
	else if (pid == 0)
	{
		//if (execute_command(args) == 0)
		//	exit(EXIT_SUCCESS);
		//else
		if (execvp(args[0], args) == -1)
			perror("jsh");
		exit(clean_exit(args, 1));
		//return (1);
	}
	else
	{
		wpid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}

int	jsh_execute(char **args)
{
	if (!args || args[0] == NULL)
	{
		return (clean_exit(args, 1));
	}
	if (ft_strcmp(args[0], "cd") == 0)
	{
		if (!args[1] && args[1] == NULL)
		{
			puts("Error: cd: argument missing.\n");
			return (clean_exit(args, 1));
		}
		else if (chdir(args[1]) != 0)
		{
			perror("cd");
			return (clean_exit(args, 1));
		}
		return (clean_exit(args, 0));
	}
	else if (ft_strcmp(args[0], "exit") == 0)
	{
		exit(clean_exit(args, 0));
	}
	else
		return (jsh_launch(args));
}

void	jsh_loop(void)
{
	char	*line;
	char	**args;
	int	status;
	
	status = 1;
	while (status)
	{
		line = readline("minishell>>> ");
		if (!line)
			break ;
		if (*line)
			add_history(line);
		args = ft_split2(line, " \a\b\t\n\v\f\r");
		status = jsh_execute(args);
		free(args);
		free(line);
	}
	clean_exit(args, 0);
}

int	main(void)
{
	jsh_loop();
	return (0);
}
