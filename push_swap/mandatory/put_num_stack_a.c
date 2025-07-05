/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_num_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:20:51 by youbella          #+#    #+#             */
/*   Updated: 2025/04/14 19:52:51 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_duplicate(ssize_t num, t_stack *stack_a)
{
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	while (stack_a)
	{
		if (stack_a->value == num)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	full_stack_a(t_stack **stack_a, int argc, char **argv)
{
	int		i;
	int		j;
	char	**numbers;
	t_stack	*temp;

	i = 1;
	while (i < argc)
	{
		j = 0;
		numbers = ft_split(argv[i], ' ');
		while (numbers[j])
		{
			if (!is_duplicate(ft_atoi(numbers[j]), *stack_a))
				ft_putstr_fd("Error\n", 2, numbers, stack_a);
			temp = ft_lstnew(ft_atoi(numbers[j]));
			if (!temp)
				ft_putstr_fd("Error\n", 2, numbers, stack_a);
			ft_lstadd_back(stack_a, temp);
			j++;
		}
		free_split(numbers);
		i++;
	}
}
