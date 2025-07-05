/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 02:30:03 by youbella          #+#    #+#             */
/*   Updated: 2025/04/13 03:09:47 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_index(t_stack *stack_b)
{
	int		max_index;
	t_stack	*tmp;

	if (!stack_b)
		return (-1);
	max_index = stack_b->index;
	tmp = stack_b->next;
	while (tmp)
	{
		if (tmp->index > max_index)
			max_index = tmp->index;
		tmp = tmp->next;
	}
	return (max_index);
}

static int	find_position(t_stack *stack_b, int max_index)
{
	int		pos;
	t_stack	*tmp;

	pos = 0;
	tmp = stack_b;
	while (tmp && tmp->index != max_index)
	{
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}

static void	push_b(t_stack **stack_a, t_stack **stack_b, int chunk_size)
{
	int	i;

	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + chunk_size)
		{
			pb(stack_a, stack_b);
			if (ft_lstsize(*stack_b) > 1)
				rb(stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

void	big_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	chunk_size;
	int	pos;
	int	half;

	if (size <= 100)
		chunk_size = 20;
	else
		chunk_size = 35;
	push_b(stack_a, stack_b, chunk_size);
	while (*stack_b)
	{
		pos = find_position(*stack_b, find_max_index(*stack_b));
		half = ft_lstsize(*stack_b) / 2;
		if (pos <= half)
			while ((*stack_b)->index != find_max_index(*stack_b))
				rb(stack_b);
		else
			while ((*stack_b)->index != find_max_index(*stack_b))
				rrb(stack_b);
		pa(stack_a, stack_b);
	}
}
