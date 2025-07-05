/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 00:14:08 by youbella          #+#    #+#             */
/*   Updated: 2025/04/16 16:26:18 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	sort_index(t_stack *stack)
{
	t_stack	*ptr;
	t_stack	*min;
	int		index;
	int		size;

	index = 0;
	size = ft_lstsize(stack);
	while (index < size)
	{
		ptr = stack;
		min = NULL;
		while (ptr)
		{
			if (ptr->index == -1 && (!min || ptr->value < min->value))
				min = ptr;
			ptr = ptr->next;
		}
		if (min)
			min->index = index++;
	}
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

static int	is_sorted(t_stack *stack_a)
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	check_numbers(argc, argv, 1, 0);
	full_stack_a(&stack_a, argc, argv);
	if (!is_sorted(stack_a))
		return (ft_lstclear(&stack_a), 0);
	sort_index(stack_a);
	size = ft_lstsize(stack_a);
	if (size == 2)
		sort_two(&stack_a);
	else if (size == 3)
		sort_three(&stack_a);
	else if (size <= 5)
		sort_five(&stack_a, &stack_b);
	else
		big_sort(&stack_a, &stack_b, size);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
