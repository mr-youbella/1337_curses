/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_op_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:52:49 by youbella          #+#    #+#             */
/*   Updated: 2025/04/16 16:23:51 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	use_op(char *all_op, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(all_op, "rra", 3))
		rra(stack_a);
	else if (!ft_strncmp(all_op, "rrb", 3))
		rrb(stack_b);
	else if (!ft_strncmp(all_op, "rrr", 3))
		r(stack_a, stack_b, 3);
	else if (!ft_strncmp(all_op, "sa", 2))
		sa(stack_a);
	else if (!ft_strncmp(all_op, "sb", 2))
		sb(stack_b);
	else if (!ft_strncmp(all_op, "ss", 3))
		ss(stack_a, stack_b);
	else if (!ft_strncmp(all_op, "pa", 2))
		pa(stack_a, stack_b);
	else if (!ft_strncmp(all_op, "pb", 2))
		pb(stack_a, stack_b);
	else if (!ft_strncmp(all_op, "ra", 2))
		ra(stack_a);
	else if (!ft_strncmp(all_op, "rb", 2))
		rb(stack_b);
	else if (!ft_strncmp(all_op, "rr", 2))
		r(stack_a, stack_b, 2);
}

int	check_op(char *op)
{
	if (ft_strncmp(op, "sa\n", 3) && ft_strncmp(op, "sb\n", 3) \
		&& ft_strncmp(op, "ss\n", 3) && ft_strncmp(op, "pa\n", 3) \
		&& ft_strncmp(op, "pb\n", 3) && ft_strncmp(op, "ra\n", 3) \
		&& ft_strncmp(op, "rb\n", 3) && ft_strncmp(op, "rr\n", 3) \
		&& ft_strncmp(op, "rra\n", 4) && ft_strncmp(op, "rrb\n", 4) \
		&& ft_strncmp(op, "rrr\n", 4))
		return (0);
	return (1);
}

void	is_ok(t_stack **stack_a, t_stack **stack_b)
{
	if (!is_sorted(*stack_a) && !*stack_b)
		ft_putstr_fd("OK\n", 1, NULL, NULL);
	else
		ft_putstr_fd("KO\n", 1, NULL, NULL);
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
}
