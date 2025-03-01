#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	g_stop;

void	block_signal(int signal)
{
	sigset_t	set;

	sigemptyset(&set);
	sigaddset(&set, signal);
	sigprocmask(SIG_BLOCK, &set, NULL);
       	if (signal == SIGQUIT)
		printf("SIGQUIT blocked.\n");	
}

void    unblock_signal(int signal)
{
        sigset_t        set;

        sigemptyset(&set);
        sigaddset(&set, signal);
        sigprocmask(SIG_UNBLOCK, &set, NULL);
        if (signal == SIGQUIT)
                printf("SIGQUIT unblocked.\n");   
}

void	signal_handler(int signal)
{
	if (signal != SIGINT)
		return ;
	block_signal(SIGINT);
	g_stop = 1;
	unblock_signal(SIGINT);
}

void	signal_action(void)
{
	struct sigaction	act;

	memset(&act, 0, sizeof(act));
	act.sa_handler = &signal_handler;
	sigaction(SIGINT, &act, NULL);
}

int	main(void)
{
	g_stop = 0;
	signal_action();
	block_signal(SIGQUIT);
	while (1)
	{
		block_signal(SIGINT);
		if (g_stop == 1)
		{
			printf("Action succesfull\n");
			unblock_signal(SIGINT);
			unblock_signal(SIGQUIT);
		}
		else
			unblock_signal(SIGINT);
		sleep(1);
	}
	return (0);
}
