/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:14:08 by youbella          #+#    #+#             */
/*   Updated: 2025/04/16 16:25:59 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_split(char **numbers)
{
	int	i;

	if (!numbers)
		return ;
	i = 0;
	while (numbers[i])
		free(numbers[i++]);
	free(numbers);
}

static void	check_numbers(int argc, char **argv, int i, int j)
{
	int		k;
	char	**numbers;

	while (i < argc)
	{
		j = 0;
		numbers = ft_split(argv[i], ' ');
		while (numbers[j])
		{
			k = 0;
			if (numbers[j][k] == '-' || numbers[j][k] == '+')
				k++;
			if (!numbers[j][k])
				ft_putstr_fd("Error\n", 2, numbers, NULL);
			while (numbers[j][k])
			{
				if (!(numbers[j][k] >= '0' && numbers[j][k] <= '9'))
					ft_putstr_fd("Error\n", 2, numbers, NULL);
				k++;
			}
			j++;
		}
		free_split(numbers);
		i++;
	}
}

int	is_sorted(t_stack *stack_a)
{
	if (!stack_a)
		return (0);
	while (stack_a && stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

static char	**ft_scanf(t_stack **stack_a, char *join_op, char **all_op)
{
	char	*op;

	while (1)
	{
		op = get_next_line(0);
		if (!op)
			break ;
		if (!check_op(op))
		{
			free(op);
			free(all_op);
			ft_putstr_fd("Error\n", 2, NULL, stack_a);
		}
		join_op = ft_strjoin(join_op, op);
		free(op);
	}
	if (!is_sorted(*stack_a) && !join_op)
		return (ft_lstclear(stack_a), \
				ft_putstr_fd("OK\n", 1, NULL, NULL), NULL);
	else if (is_sorted(*stack_a) && !join_op)
		return (ft_lstclear(stack_a), \
				ft_putstr_fd("KO\n", 1, NULL, NULL), NULL);
	all_op = ft_split(join_op, '\n');
	free(join_op);
	return (all_op);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**all_op;

	if (argc < 2)
		return (0);
	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	check_numbers(argc, argv, 1, 0);
	full_stack_a(&stack_a, argc, argv);
	all_op = ft_scanf(&stack_a, NULL, NULL);
	if (!all_op)
		return (0);
	while (all_op[i])
	{
		use_op(all_op[i], &stack_a, &stack_b);
		i++;
	}
	free_split(all_op);
	is_ok(&stack_a, &stack_b);
	return (0);
}
