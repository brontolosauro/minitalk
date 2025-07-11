/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfani <rfani@student.42firenze.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:42:24 by rfani             #+#    #+#             */
/*   Updated: 2025/07/11 17:15:48 by rfani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	sig_handler(int sig, siginfo_t *info, void *context);

int	main(void)
{
	struct sigaction	sa;
	int	pid;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &sig_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server PID: %d \n", getpid());
	while (1)
		pause();
	return (0);
}

void sig_handler(int sig, siginfo_t *info, void *context)
{
	static int	bit_count = 0;
	static char	c = 0;

	(void)context;
	if (sig == SIGUSR1)
		c |= (1 << (7 - bit_count));
	else if (sig == SIGUSR2)
		c &= ~(1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		if (c == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", c);
		bit_count = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}
