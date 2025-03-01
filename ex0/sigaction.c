#include <signal.h>
#include <stdio.h>
#include <string.h>

void	sigint_handler(int signal)
{
	if (signal == SIGINT)
		printf("\nIntercepted SIGINT!\n");
}

void	set_signal_action(void)
{
	struct sigaction	act;

	memset(&act, 0, sizeof(act));
	act.sa_handler = &sigint_handler;
	sigaction(SIGINT, &act, NULL);
}

int	main(void)
{
	set_signal_action();
	while (1)
		continue ;
	return (0);
}
