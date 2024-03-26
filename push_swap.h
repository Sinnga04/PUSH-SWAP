/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:46:54 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/26 13:59:23 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "LIBFT/libft.h"
#include <ctype.h>
typedef struct s_list
{
	int				content;
	int				index;
	int				cost;
	struct s_list	*target;
	int				cheapest;
	int				above_median;
	struct s_list	*next;
	int				counter;
}			t_list;

typedef struct s_Stack
{
	int		cheapest;
	t_list	*stacka;
	t_list	*stackb;
}		t_Stack;

t_list	*smallestnumber(t_list *stackA);
t_list	*biggestnumber(t_list *stackA);
void	target_check(t_list **stackA, t_list **stackB);
int		count(t_list *stack);
int		easiest_move(t_list **stackB);
t_list	*pop(t_list **stack);
void	sa(t_list **stackA);
void	indexing(t_list **stack);
void	median(t_list **stack);
int		count(t_list *stack);
void	cost(t_list **stack);
// void	cost(t_list *stacka, t_list *stackb);
void	init_stack(t_list **stacka, t_list **stackb);
void	sb(t_list **stackb);
void	ra(t_list **stacka);
void	get_all_targets(t_list **stacka, t_list **stackb);
void	rb(t_list **stackb);
void	rr(t_list **stacka, t_list **stackb);
void	rra(t_list **stacka);
void	rrb(t_list **stackb);
void	rrr(t_list	**stacka, t_list **stackb);
void	rrb(t_list **stackb);
void	pa(t_list **stacka, t_list **stackb);
void	pb(t_list **stacka, t_list **stackb);
int		stacksorted(t_list **stacka);
t_list	*ft_lstnew(int content);
int		ft_isduplicate(t_list *stack);
int		ft_check_error1(char **s);
void	ft_print_stack(t_list *stack);
void	stack_init(t_list **stack, char **argv);
void	ft_free_all(char **s);
void	ft_lstadd_back(t_list **stack, t_list *newnode);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
t_list	*createnode(int content);
void	displaystack(t_list *stack);
void	push(t_list **stack, int value);
int		empty(t_list *stack);
int		count(t_list *stacka);
int		above_median(t_list *stack);
void	move_nodes(t_list **stacka, t_list **stackb);
void	sorthree(t_list **stacka);
void	small_to_top(t_list **stacka);
void	median(t_list **stack);
void	cheapest(t_list **stacka, t_list **stackb);
void	indexing(t_list **stack);
t_list	*most_cheapest(t_list *stacka, t_list *stackb);
void	ra_p(t_list **stacka);
void	rb_p(t_list **stackb);
void	rra_p(t_list **stacka);
void	rrb_p(t_list **stackb);
t_list	*stackissorted(t_list **stack);
void	check_all(t_list **stacka, t_list **stackb);
void	easy_move_a(t_list **stacka, t_list *node);
void	easy_move_b(t_list **stackb, t_list *small);
int		ft_isdigits_str(const char *str);
int		ft_check_error2(char **s);
int		ft_check_error1(char **s);
void	free_list(t_list *head);
long	ft_atol(const char *str);
void	sort(t_list **stacka, t_list **stackb);
int		ft_error(void);
void	sortwo(t_list **stacka);