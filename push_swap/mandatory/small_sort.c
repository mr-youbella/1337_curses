/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:31:10 by youbella          #+#    #+#             */
/*   Updated: 2025/04/10 16:30:41 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	sort_three(t_stack **stack_a)
{
	int	top;
	int	mid;
	int	bottom;

	top = (*stack_a)->value;
	mid = (*stack_a)->next->value;
	bottom = (*stack_a)->next->next->value;
	if (top > mid && mid < bottom && bottom > top)
		sa(stack_a);
	else if (top > mid && mid > bottom)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (top > mid && mid < bottom && bottom < top)
		ra(stack_a);
	else if (top < mid && mid > bottom && bottom > top)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (top < mid && mid > bottom && bottom < top)
		rra(stack_a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->index == 0 || (*a)->index == 1)
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	while (*b)
	{
		pa(a, b);
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
}
