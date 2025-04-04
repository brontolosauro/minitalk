/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfani <rfani@student.42firenze.it>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:42:24 by rfani             #+#    #+#             */
/*   Updated: 2025/04/02 13:50:24 by rfani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"

int	main(void)
{
	int		pid;
	char	*pid_str;

	pid = getpid();
	pid_str = ft_itoa(pid);
	if (pid_str == NULL)
	{
		ft_putstr_fd("Error: Failed to convert PID to string\n", 2);
		return (1);
	}
	ft_putstr_fd("Server PID: ", 1);
	ft_putstr_fd(pid_str, 1);
	ft_putstr_fd("\n", 1);
	free(pid_str);
	while (1)
	{
		pause();
	}
	return (0);
}
