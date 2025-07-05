/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:28:06 by youbella          #+#    #+#             */
/*   Updated: 2025/04/12 02:32:30 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	int	tmp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = tmp;
	ft_putstr_fd("sa\n", 1, NULL, NULL);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	ft_putstr_fd("pa\n", 1, NULL, NULL);
}

void	ra(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	last = ft_lstlast(*stack_a);
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	last->next = tmp;
	tmp->next = NULL;
	ft_putstr_fd("ra\n", 1, NULL, NULL);
}

void	rra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	ft_putstr_fd("rra\n", 1, NULL, NULL);
}
