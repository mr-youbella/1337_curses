/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:28:20 by youbella          #+#    #+#             */
/*   Updated: 2025/04/13 03:20:30 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

char	**ft_split(char const *s, char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd, char **numbers, t_stack **stack_a);
ssize_t	ft_atoi(const char *str);
void	sa(t_stack **a);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	ft_lstclear(t_stack **lst);
t_stack	*ft_lstnew(int value);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	sort_two(t_stack **stack_a);
void	sort_three(t_stack **stack_a);
void	sort_five(t_stack **a, t_stack **b);
void	big_sort(t_stack **a, t_stack **b, int size);
void	free_split(char **numbers);
void	full_stack_a(t_stack **stack_a, int argc, char **argv);

#endif