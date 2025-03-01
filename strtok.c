#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	*string;
	char	*string_copy;
	char	*dir;
	char	path[13];
	char	*command;

	command = "plus";
	string = "ABCD:EFGH:IJKL";
	string_copy = strdup(string);
	dir = strtok(string_copy, ":");
	while (dir)
	{
		puts(dir);
		snprintf(path, sizeof(path), "%s/%s", dir, command);
		puts(path);
		dir = strtok(NULL, ":");
	}
}

/*
c1r7s1% cc strtok.c
c1r7s1% ./a.out    
ABCD
ABCD/plus
EFGH
EFGH/plus
IJKL
IJKL/plus
c1r7s1%
*/
