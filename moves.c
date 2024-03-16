/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:57:29 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/16 18:50:58 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	pop(t_list **stack);
t_list	*createnode(int content);

// void	sa(t_list *stacka)
// {
// 	t_list	*current;
// 	int		temp2;
// 	int		temp1;

// 	current = stacka;
// 	if (current == NULL || current->next == NULL)
// 		return ;
// 	temp1 = pop(&stacka);
// 	temp2 = pop(&stacka);
// 	push(&stacka, temp1);
// 	push(&stacka, temp2);
// 	printf("sa\n");
// }

// void	sb(t_list *stackb)
// {
// 	t_list	*current;
// 	int		temp1;
// 	int		temp2;

// 	current = stackb;
// 	printf("ok\n");
// 	if (current == NULL || current->next == NULL)
// 		return ;
// 	temp1 = pop(&current);
// 	temp2 = pop(&current);
// 	push(&current, temp2);
// 	push(&current, temp1);
// 	indexing(&current);
// 	// median(&current);
// 	// cost(&current);
// 	printf("sb\n");
// }





// void	rr(t_list **stacka, t_list **stackb)
// {
// 	ra(stacka);
// 	rb(stackb);
// }

// void	rra(t_list *stacka)
// {
// 	t_list	*secondlast;
// 	t_list	*last;

// 	secondlast = NULL;
// 	last = stacka;
// 	if (stacka == NULL || stacka->next == NULL)
// 		return ;
// 	while (last->next != NULL)
// 	{
// 		secondlast = last;
// 		last = last->next;
// 	}
// 	if (secondlast == NULL)
// 		return ;
// 	secondlast->next = NULL;
// 	last->next = stacka;
// 	stacka = last;
// 	printf("rra\n");
// }

// void	rrr(t_list	**stacka, t_list **stackb)
// {
// 	rra(stacka);
// 	rrb(stackb);
// }
// // void	rrb(t_list *stackb)
// {
// 	t_list		*secondlast;
// 	t_list		*last;

// 	// if (stackb == NULL || stackb->next == NULL)
// 	// 	exit ;
// 	last = stackb;
// 	secondlast = NULL;
// 	while (last->next != NULL)
// 	{
// 		secondlast = last;
// 		last = last->next;
// 	}
// 	if (secondlast != NULL)
// 		secondlast->next = NULL;
// 	else
// 		stackb = NULL;
// 	push(&stackb, last->content);
// 	free(last);
// 	printf("rrb\n");
// }