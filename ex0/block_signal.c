#include <signal.h>
#include <strings.h>
#include <unistd.h>
#include <stdio.h>

volatile int	g_unblock_sigquit = 0;

void	block_signal(int signal)
{
	sigset_t	sigset;

	sigemptyset(&sigset);
	sigaddset(&sigset, signal);
	sigprocmask(SIG_BLOCK, &sigset, NULL);
	if (signal == SIGQUIT)
		printf("SIGQUIT (ctrl-\\) blocked.\n");
}

void	unblock_signal(int signal)
{
	sigset_t	sigset;

	sigemptyset(&sigset);
	sigaddset(&sigset, signal);
	sigprocmask(SIG_UNBLOCK, &sigset, NULL);
	if (signal == SIGQUIT)
		printf("SIGQUIT (ctrl-\\) unblocked.\n");
}

void	sigint_handler(int signal)
{
	if (signal != SIGINT)
		return ;
	block_signal(SIGINT);
	g_unblock_sigquit = 1;
	unblock_signal(SIGINT);
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
	block_signal(SIGQUIT);
	while (1)
	{
		block_signal(SIGINT);
		if (g_unblock_sigquit == 1)
		{
			printf("SIGINT detected. Unblocking SIGQUIT.\n");
			unblock_signal(SIGINT);
			unblock_signal(SIGQUIT);
		}
		else
			unblock_signal(SIGINT);
		sleep(1);
	}
	return (0);
}
