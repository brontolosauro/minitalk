/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfani <rfani@student.42firenze.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:29:24 by rfani             #+#    #+#             */
/*   Updated: 2025/07/11 18:55:31 by rfani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

volatile sig_atomic_t	g_ack_received = 0;
void	ack_handler(int sig);
void	send_message(int pid, char *message);
void	send_char(int pid, char c);

int	main(int argc, char **argv)
{
	int					pid;
	char				*message;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Usage: %s <PID> <message>\n", argv[0]);
		return (1);
	}
	sa.sa_handler = &ack_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	pid = ft_atoi(argv[1]);
	message = argv[2];
	send_message(pid, message);
	return (0);
}

void	ack_handler(int sig)
{
	if (sig == SIGUSR1)
		g_ack_received = 1;
}

void	send_message(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		send_char(pid, message[i]);
		i++;
	}
	send_char(pid, '\0');
}

void	send_char(int pid, char c)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if ((c >> (7 - j)) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_ack_received)
			pause();
		g_ack_received = 0;
		j++;
	}
}
