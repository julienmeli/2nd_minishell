#define TYPE_END 0
#define TYPE_PIPE 1
#define TYPE_BREAK 2

typedef struct	s_list
{
	char	**args;
	int	length;
	int	type;
	int	pipes[2];
	struct s_list	*previous;
	struct s_list	*next;
}		t_list;

int	list_push(t_list **cmds, char *arg)
{
}

int	parse_arg(t_list **cmds, char *arg)
{
	int	is_break;

	is_break = (strcmp(arg, ";") == 0);
	if (is_break && !*cmds)
		return (EXIT_SUCCESS);
	else if (!is_break && (!*cmds || cmds->type = TYPE_END))
		list_push(cmds, arg);
	else if (strcmp(arg, "|") == 0)
		cmds->type = TYPE_PIPE;
	else if (is_break)
		cmds->type = TYPE_BREAK;
	else
		return (add_arg(cmds, arg));
	return (EXIT_SUCCESS);
}	

int	main(int argc, char **argv, char **env)
{
	t_list	*cmds;
	int	i;
	int	ret;

	i = 1;
	ret = EXIT_SUCCESS;
	cmds = NULL;
	while (i < argc)
		ret = parse_arg(&cmds, argv[i++]);
	if (*cmds)
		ret = exec_cmds(&cmds, env);
	list_clear(cmds);
	return (ret);
}
