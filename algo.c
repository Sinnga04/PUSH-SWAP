/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:38:15 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/16 17:10:46 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count(t_list *stacka);

void	indexing(t_list **stack)
{
	int		i;
	t_list	*current;

	i = 0;
	current = *stack;
	while (current)
	{
		current->index = i++;
		current = current->next;
	}
}

void	median(t_list **stack)
{
	t_list	*current;
	int		size;

	size = count(*stack);
	current = *stack;
	while (current)
	{
		current->above_median = (current->index <= size / 2);
		current = current->next;
	}
}

int	count(t_list *stack)
{
	int		i;
	t_list	*current;

	i = 0;
	current = stack;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}

void	cost(t_list **stack)
{
	int		size;
	t_list	*current;

	size = count(*stack);
	current = *stack;
	while (current)
	{
		if (current->above_median)
		{
			current->cost = current->index;
			printf("%d the current cost is %d\n",current->content, current->cost);
		}
		else
			current->cost = size - current->index;
		current = current->next;
	}
}

void	init_stack(t_list **stacka, t_list **stackb)
{
	indexing(stacka);
	indexing(stackb);
	median(stacka);
	median(stackb);
	cost(stacka);
	cost(stackb);
	target_check(stacka, stackb);
}

// int	main(void)
// {
// 	t_list	*stacka;
// 	t_list	*stackb;

// 	stacka = NULL;
// 	stackb = NULL;
// 	push(&stacka, 4);
// 	push(&stacka, 25);
// 	push(&stacka, 13);
	
// 	push(&stackb, 1);
// 	push(&stackb, 2);
// 	push(&stackb, 3);
// 	push(&stackb, 11);
// 	push(&stackb, 32);
// 	push(&stackb, 23);
// 	// int i = count(stackA);
// 	// printf("%d", i);
// 	// indexing(&stackB);
// 	//  indexing(&stackB);
// 	// median(&stackB);
// 	// init_stack(&stacka, &stackb);
	
	
// 	// check_cost_try(&stackB);
// 	printf("kamal bvas\n");
// 	displaystack(&stackb);
// 	//targets(&stackA &stackB);
// 	// int i = indexingB(stackB);
// 	// int a = count(stackA);
// 	// int j = check_cost(stackA, 4);
// 	// // printf("this is %d anf B is ..%d and oooo ii ...%d or ignvkn", k, i, a
// 	// 	/ 2);
// 	// printf("\n%d\n", j);
// 	return (0);
// }
