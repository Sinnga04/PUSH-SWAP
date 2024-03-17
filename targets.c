/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:00:14 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/17 14:19:21 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*smallestnumber(t_list *stacka)
{
	t_list	*current;
	t_list	*smallest;

	current = stacka;
	smallest = stacka;
	while (current != NULL)
	{
		if (current->content < smallest->content)
		{
			smallest = current;
		}
		current = current->next;
	}
	return (smallest);
}

t_list	*biggestnumber(t_list *stacka)
{
	t_list	*current;
	t_list	*biggest;

	current = stacka;
	biggest = stacka;
	while (current != NULL)
	{
		if (current->content > biggest->content)
		{
			biggest = current;
		}
		current = current->next;
	}
	return (biggest);
}

void	target_check(t_list **stacka, t_list **stackb)
{
	t_list	*current_b;
	t_list	*big;
	t_list	*current_a;
	int		delta;

	current_b = *stackb;
	big = biggestnumber(*stacka);
	while (current_b)
	{
		current_a = *stacka;
		delta = current_a->content - current_b->content;
		current_b->target = current_a;
		while (current_a)
		{
			if ((current_b)->content > big->content)
			{
				current_b->target = smallestnumber(*stacka);
			}
			else if (current_a->content > current_b->content)
			{
				if (delta >= (current_a->content - current_b->content))
				{
					delta = current_a->content - current_b->content;
					current_b->target = current_a;
				}
			}
			current_a = current_a->next;
		}
		current_b = current_b->next;
	}
}


//  void	target_check(t_list **stacka, t_list **stackb)
//  {
// 	t_list	*current_b;
// 	long 	best_match_index;
// 	t_list	*current_a;
// 	int		delta;

// 	current_b = *stackb;
// 	best_match_index = biggestnumber(*stacka)->content;
// 	current_a = *stacka;
// 	while (current_a)
// 	{
// 			if(current_a->content > current_b->content && current_a->content < best_match_index)
// 				{
// 					best_match_index = current_a->content;
// 					current_b->target = current_a;
// 				}
// 			current_a = current_a->next;
// 	}
// 	if (best_match_index == biggestnumber(*stacka)->content)
// 		current_b->target = smallestnumber(*stacka);
// 	// else 
// 	// 	current_b->target = current_b->target;
// 	current_b = current_b->next;
//  }


 
int		count(t_list *stack);

void	cheapest(t_list **stackb)
{
	t_list	*current_b;

	current_b = *stackb;
	while (current_b != NULL)
	{
		current_b->cheapest = current_b->target->cost + current_b->cost;
		printf("%d and his cost %d\n", current_b->content, current_b->cheapest);
		current_b = current_b->next;
	}
}

t_list	*most_cheapest(t_list *stackb)
{
	t_list	*cheapest;
	int		sum;

	sum = stackb->cheapest;
	cheapest = stackb;
	while (stackb)
	{
		if (stackb->cheapest < sum)
		{
			cheapest = stackb;
			sum = cheapest->cheapest;
		}
		stackb = stackb->next;
	}
	return (cheapest);
}

int	pop(t_list **stack)
{
	int		value;
	t_list	*temp;

	if (*stack == NULL)
		printf("error\n");
	value = (*stack)->content;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
	return (value);
}

void	sb(t_list **stackb)
{
	t_list	*top;
	int		temp;

	top = *stackb;
	if (top == NULL || top->next == NULL)
		return ;
	temp = top->content;
	top->content = top->next->content;
	top->next->content = temp;
	printf("sb\n");
	indexing(stackb);
}
void	sa(t_list **stacka)
{
	t_list	*current;
	int		temp;

	current = *stacka;
	if (current == NULL || current->next == NULL)
		return ;
	temp = current->content;
	current->content = current->next->content;
	current->next->content = temp;
	printf("sa\n");
	indexing(stacka);
}

void	ra(t_list **stacka)
{
	t_list	*last;

	if (*stacka == NULL || (*stacka)->next == NULL)
	{
		return ;
	}
	last = *stacka;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = *stacka;
	*stacka = (*stacka)->next;
	last->next->next = NULL;
	indexing(stacka);
}

void	rb(t_list **stackb)
{
	t_list	*current;
	t_list	*last;

	current = *stackb;
	last = NULL;
	while (current->next != NULL)
	{
		last = current;
		current = current->next;
	}
	last->next = NULL;
	current->next = *stackb;
	*stackb = current;
	indexing(stackb);
}

void	rrb(t_list **stackb)
{
	t_list	*current;
	t_list	*last;

	current = *stackb;
	last = NULL;
	if (*stackb == NULL || (*stackb)->next == NULL)
		return ;
	while (current->next != NULL)
	{
		last = current;
		current = current->next;
	}
	last->next = NULL;
	current->next = *stackb;
	*stackb = current;
	indexing(stackb);
}

void	rra(t_list **stacka)
{
	t_list	*current;
	t_list	*last;

	current = *stacka;
	last = NULL;
	if (*stacka == NULL || (*stacka)->next == NULL)
		return ;
	while (current->next != NULL)
	{
		last = current;
		current = current->next;
	}
	last->next = NULL;
	current->next = *stacka;
	*stacka = current;
	// printf("rrb\n");
	// indexing(stacka);
}
void	pa(t_list **stacka, t_list **stackb)
{
	int	first;

	first = pop(stackb);
	push(stacka, first);
	printf("pa\n");
	indexing(stacka);
}

void	pb(t_list **stacka, t_list **stackb)
{
	int	first;

	first = pop(stacka);
	push(stackb, first);
	printf("pb\n");
	indexing(stackb);
}

void	displaystack(t_list *stack)
{
	while (stack)
	{
		printf("%d his target \n", stack->content);
		stack = stack->next;
	}
}

void	displaytarget(t_list *stack)
{
	while (stack)
	{
		printf("%d his target is %d\n", stack->content, stack->target->content);
		stack = stack->next;
	}
}

void	move_nodes(t_list **stacka, t_list **stackb);
void	easy_move_a(t_list *stacka);
int	main(void)
{
	t_list	*stacka;
	t_list	*stackb;

	stacka = NULL;
	stackb = NULL;
	push(&stacka, 32);
	push(&stacka, 5);
	push(&stacka, 7);
	// push(&stacka, 19);
	
	// push(&stackb, 17);
	push(&stackb, 2);
	push(&stackb, 18);

	while (stackb)
	{
		init_stack(&stacka, &stackb);
		printf("%d and his target %d\n", stackb->content,
			stackb->target->content);
		stackb = stackb->next;
	}
	// easy_move_a(stacka);
	// displaystack(stacka);
	return (0);
}
