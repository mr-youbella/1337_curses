/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 07:56:52 by youbella          #+#    #+#             */
/*   Updated: 2025/02/27 09:53:56 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

static int	g_pid_client;

int	check_bytes(unsigned char c)
{
	if (c < 128)
		return (1);
	else if ((c & 224) == 192)
		return (2);
	else if ((c & 240) == 224)
		return (3);
	else if ((c & 248) == 240)
		return (4);
	return (0);
}

static void	reset_state(int *bit_count, int *byte_count, int *bytes_expected,
	unsigned char *received_bytes)
{
	*bit_count = 0;
	*byte_count = 0;
	*bytes_expected = 0;
	ft_bzero(received_bytes);
}

static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static unsigned char	received_bytes[4];
	static int				bit_count;
	static int				byte_count;
	static int				bytes_expected;

	(void)context;
	if (info->si_pid != g_pid_client)
		reset_state(&bit_count, &byte_count, &bytes_expected, received_bytes);
	g_pid_client = info->si_pid;
	if (sig == SIGUSR1)
		received_bytes[byte_count] |= (1 << (7 - bit_count));
	if (++bit_count == 8)
	{
		bit_count = 0;
		if (++byte_count == 1)
			bytes_expected = check_bytes(received_bytes[0]);
		if (byte_count == bytes_expected)
		{
			write(1, received_bytes, bytes_expected);
			if (received_bytes[0] == '\0')
				kill(info->si_pid, SIGUSR2);
			reset_state(&bit_count, &byte_count, \
						&bytes_expected, received_bytes);
		}
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
