#include "minishell.h"

int	ft_heredoc_detection(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if ((ft_strncmp(args[i], "<<", 2) == 0) || (ft_strcmp(args[i], "<<") == 0))
			return (i);
		i++;
	}
	return (-1);
}

char	*get_delimiter(char **args, int i)
{
	if (ft_strcmp(args[i], "<<") == 0)
	{
		if (!args[i + 1])
		{
			perror("syntax error near unexpected token `newline'");
			return (NULL);
		}
		else
			return (args[i + 1]);
	}
	else
		return(ft_substr(args[i], 2, ft_strlen(args[i]) - 2));
}

void	handle_heredoc(char *delimiter)
{
	int	fd;
	//char	*line;
	//int	len;
	//int	status;
	char	buffer[BUFFER_SIZE];
	int	read_byte;

	//puts("hh");
	if (delimiter == NULL)
		return ;
	fd = open(HEREDOC_NAME, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open");
		return ;
	}
	//status = 1;
	while (1)
	{
		write(1, "heredoc> ", 9);
		read_byte = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);
		if (read_byte <= 0)
			break ;
		buffer[read_byte] = '\0';
		if (buffer[read_byte - 1] == '\n')
			buffer[read_byte - 1] = '\0';
		if (strcmp(buffer, delimiter) == 0)
			break ;
		write(fd, buffer, ft_strlen(buffer));
	}
	/*
	while (status)
	{
		line = readline("heredoc>");
		if (!line)
			break ;
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		free(line);
	}
	*/
	close(fd);
}

void	execute_command_in_heredoc(char **args)
{
	int	fd;

	(void)args;
	fd = open(HEREDOC_NAME, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return ;
	}
	//dup2(fd, STDIN_FILENO);
	close(fd);
}
