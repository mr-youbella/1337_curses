/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:21:45 by youbella          #+#    #+#             */
/*   Updated: 2025/02/27 15:44:17 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

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
	bit = 0;
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
		return (write(2, "Usage: ./client <PID> <message>\n", 32), 1);
	if (kill(pid, 0) == -1 || pid <= 0)
		return (write(2, "Invalid PID.\n", 13), 1);
	while (argv[2][i])
	{
		get_bit(pid, argv[2][i]);
		i++;
	}
	get_bit(pid, '\n');
	return (0);
}
