/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:16:07 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/16 15:37:52 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pop(t_list **stack);

// int	pop(t_list **stack);
// {
// 	t_list		*secondlast;
// 	t_list		*last;

// 	if (stackb == NULL || stackb->next == NULL)
// 		return ;
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

// void	pa(t_list *stacka, t_list *stackb)
// {
// 	int	first;

// 	if (empty(stackb))
// 		return ;
// 	first = pop(&stackb);
// 	push(&stacka, first);
// 	printf("pa\n");
// }

// void	pb(t_list *stacka, t_list *stackb)
// {
// 	int	first;

// 	if (empty(stacka))
// 		return ;
// 	first = pop(&stacka);
// 	push(&stackb, first);
// 	printf("pb\n");
// }

int	stacksorted(t_list *stack)
{
	t_list	*current;

	if (empty(stack) || stack->next == NULL)
		return (1);
	current = stack;
	while (current->next != NULL)
	{
		if (current->content < current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}
