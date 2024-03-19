/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:09:05 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/19 10:52:21 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_list	*smallestnumber(t_list *stacka);
t_list	*most_cheapest(t_list *stackb);

void	easy_move_b(t_list **stackb)
{
	t_list	*small;

	small = most_cheapest(*stackb);
	if (small->above_median)
		while (*stackb != small)
			rb_p(stackb);
	else
		while (*stackb != small)
			rrb_p(stackb);
}

void	easy_move_a(t_list **stacka, t_list *node)
{
	if (node->above_median)
		while (*stacka != node)
			ra_p(stacka);
	else
		while (*stacka != node)
			rra_p(stacka);
}

void	rr(t_list **stacka, t_list **stackb)
{
	ra(stacka);
	rb(stackb);
	indexing(stacka);
	indexing(stackb);
	printf("rr\n");
}

void	rrr(t_list **stacka, t_list **stackb)
{
	rra(stacka);
	rrb(stackb);
	indexing(stacka);
	indexing(stackb);
	printf("rrr\n");
}
// int	ft_lstsize(t_list *lst)
// {
// 	int	size;

// 	size = 0;
// 	while (lst)
// 	{
// 		size++;
// 		lst = lst->next;
// 	}
// 	return (size);
// }
// void	rotate_to(t_list **stack, t_list *target, char s)
// {
// 	int	len;

// 	len = ft_lstsize(*stack);
// 	while (s == 'a' && *stack != target)
// 	{
// 		if (target->index <= len / 2)
// 			ra(stack);
// 		else
// 			rra(stack);
// 	}
// 	while (s == 'b' && *stack != target)
// 	{
// 		if (target->index <= len / 2)
// 			rb(stack);
// 		else
// 			rrb(stack);
// 	}
// }

// t_list	*next_to_move(t_list *b)
// {
// 	t_list	*node;

// 	node = b;
// 	while (b)
// 	{
// 		if (b->index + b->target->index < node->index + node->target->index)
// 			node = b;
// 		b = b->next;
// 	}
// 	return (node);
// }

// void	move_nodes(t_list **stacka, t_list **stackb)
// {
// 	t_list	*to_move;
// 	int		len_a;
// 	int		len_b;

// 	to_move = next_to_move(*stackb);
// 	len_a = count(*stacka);
// 	len_b = count(*stackb);
// 	while (*stackb != to_move && *stacka != to_move->target)
// 	{
// 		if (to_move->index > len_b / 2 && to_move->target->index > len_a)
// 			rrr(stacka, stackb);
// 		else if (to_move->index <= len_b / 2 && to_move->target->index <= len_a)
// 			rr(stacka, stackb);
// 		else
// 			break ;
// 	}
// 	rotate_to(stacka, to_move->target, 'a');
// 	rotate_to(stackb, to_move, 'b');
// 	pa(stacka, stackb);
// }

void	move_nodes(t_list **stacka, t_list **stackb)
{
	t_list	*cheap;
	cheap = most_cheapest(*stackb);
	
	if (cheap->above_median && cheap->target->above_median)
	{
		while (cheap != *stackb && cheap->target != *stacka)
			rr(stacka, stackb);
	}
	else if (!(cheap->above_median) && !(cheap->target->above_median))
	{
		while (cheap != *stackb && cheap->target != *stacka)
			rrr(stacka, stackb);
	}
	easy_move_a(stacka, cheap->target);
	easy_move_b(stackb);
	indexing(stacka);
	indexing(stackb);
	pa(stacka, stackb);
}