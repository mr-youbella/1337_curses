/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:28:20 by youbella          #+#    #+#             */
/*   Updated: 2025/04/11 21:56:28 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42         
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

char	**ft_split(char const *s, char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd, char **numbers, t_stack **stack_a);
ssize_t	ft_atoi(const char *str);
char	*get_next_line(int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, const char *s2);
void	sa(t_stack **a);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	sb(t_stack **b);
void	r(t_stack **a, t_stack **b, int op);
void	ft_lstclear(t_stack **lst);
t_stack	*ft_lstnew(int value);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	free_split(char **numbers);
void	full_stack_a(t_stack **stack_a, int argc, char **argv);
void	use_op(char *all_op, t_stack **stack_a, t_stack **stack_b);
int		check_op(char *op);
void	is_ok(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack *stack_a);

#endif