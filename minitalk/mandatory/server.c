/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:21:56 by youbella          #+#    #+#             */
/*   Updated: 2025/02/27 08:38:49 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	g_pid_client;

static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char	received_char;
	static int	bit_count;

	(void)context;
	if (info->si_pid != g_pid_client)
	{
		g_pid_client = info->si_pid;
		received_char = 0;
		bit_count = 0;
	}
	if (sig == SIGUSR1)
		received_char |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &received_char, 1);
		received_char = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	signal;

	pid = getpid();
	write(1, "PID = ", 6);
	ft_putnbr(pid);
	write(1, "\n", 1);
	g_pid_client = -1;
	signal.sa_sigaction = handle_signal;
	signal.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &signal, NULL) == -1
		|| sigaction(SIGUSR2, &signal, NULL) == -1)
		return (1);
	while (1)
		pause();
	return (0);
}
