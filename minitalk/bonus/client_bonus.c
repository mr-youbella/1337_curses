/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:47:05 by youbella          #+#    #+#             */
/*   Updated: 2025/02/27 09:52:41 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

static void	confirm_msg(int signal)
{
	if (signal == SIGUSR2)
		write(1, "Message received.\n", 18);
}

static void	send_bit_to_server(int pid, int bit)
{
	if (bit)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(100);
}

static void	get_bit(int pid, char ch)
{
	int	i;
	int	bit;

	i = 0;
	while (i < 8)
	{
		bit = (ch >> (7 - i)) & 1;
		send_bit_to_server(pid, bit);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	pid = ft_atoi(argv[1]);
	if (argc != 3)
		return (write(2, "Usage: ./client <PID> <message>\n", 31), 1);
	if (kill(pid, 0) == -1 || pid == 0)
		return (write(2, "Invalid PID.\n", 13), 1);
	signal(SIGUSR2, confirm_msg);
	while (argv[2][i])
	{
		get_bit(pid, argv[2][i]);
		i++;
	}
	get_bit(pid, '\n');
	get_bit(pid, '\0');
	return (0);
}
