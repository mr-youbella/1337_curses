/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:28:06 by youbella          #+#    #+#             */
/*   Updated: 2025/04/12 02:33:32 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	ft_putstr_fd("pb\n", 1, NULL, NULL);
}

void	rb(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	last = ft_lstlast(*stack_b);
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	last->next = tmp;
	tmp->next = NULL;
	ft_putstr_fd("rb\n", 1, NULL, NULL);
}

void	rrb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	ft_putstr_fd("rrb\n", 1, NULL, NULL);
}
