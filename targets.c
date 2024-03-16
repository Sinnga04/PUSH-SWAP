/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:00:14 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/16 19:49:46 by kamsingh         ###   ########.fr       */
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
		while (current_a)
		{
			if ((current_b)->content > big->content)
				current_b->target = smallestnumber(*stacka);
			else if (current_b->content < current_a->content)
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

int		count(t_list *stack);

void	cheapest(t_list **stackb)
{
	t_list	*current_b;

	current_b = *stackb;
	while (current_b != NULL)
	{
		current_b->cheapest = current_b->target->cost + current_b->cost;
		printf("%d and his cost %d\n",current_b->content,  current_b->cheapest);
		current_b = current_b->next;
	}
}

t_list *most_cheapest(t_list *stackb)
{
	t_list *cheapest;
	int sum = stackb->cheapest;
	cheapest = stackb;
	while (stackb)
	{
		if(stackb->cheapest < sum)
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

void sb(t_list **stackb)
{
    t_list *top = *stackb;
    if (top == NULL || top->next == NULL)
        return;

    int temp = top->content;
    top->content = top->next->content;
    top->next->content = temp;
    printf("sb\n");
	indexing(stackb);
}
void sa(t_list **stacka)
{
    t_list *current = *stacka;

    if (current == NULL || current->next == NULL)
        return;
    int temp = current->content;
    current->content = current->next->content;
    current->next->content = temp;
    printf("sa\n");
	indexing(stacka);
}

void	ra(t_list **stacka)
{

    t_list *current = *stacka;
	t_list *last = NULL;
	while (current->next != NULL)
	{
		last = current;
		current = current->next; 
	}
	last->next = NULL;
    current->next = *stacka;
    *stacka = current;

	printf("rrb\n");
	indexing(stacka);
}

void	rb(t_list **stackb)
{

    t_list *current = *stackb;
	t_list *last = NULL;
	while (current->next != NULL)
	{
		last = current;
		current = current->next; 
	}
	last->next = NULL;
    current->next = *stackb;
    *stackb = current;
	printf("rrb\n");
	indexing(stackb);
}

void	rrb(t_list **stackb)
{
    t_list *current = *stackb;
	t_list *last = NULL;
	
 	while (current->next != NULL) 
 	{
    last = current;
    current = current->next;
 	}

	last->next = NULL;
    current->next = *stackb;
	*stackb = current; 
	printf("rrb\n");
	indexing(stackb);
}

void	rra(t_list **stacka)
{
    t_list *current = *stacka;
	t_list *last = NULL;
	
 	while (current->next != NULL) 
 	{
    last = current;
    current = current->next;
 	}

	last->next = NULL;
    current->next = *stacka;
	*stacka = current; 
	printf("rrb\n");
	indexing(stacka);
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

void displaytarget(t_list *stack)
{
	while (stack)
	{
		printf("%d his target is %d\n",stack->content,  stack->target->content);
		stack = stack->next;
	}
}

void	move_nodes(t_list **stacka, t_list **stackb);
 void	easy_move_a(t_list *stacka);
// int main() {
//     t_list *stacka = NULL;
// 	t_list *stackb = NULL;
	
// 	push(&stackb, 3);
// 	push(&stackb, 41);
// 	push(&stackb, 15);

// 	push(&stacka, 4);
// 	push(&stacka, 19);
// 	indexing(&stackb);
// 	median(&stackb);
// 	cost(&stackb);
// 	target_check(&stacka, &stackb);
// 	move_nodes(&stacka, &stackb);
// 	move_nodes(&stacka, &stackb);
// 	move_nodes(&stacka, &stackb);
//  	displaystack(stackb);
// 	displaystack(stacka);
// 	easy_move_a(stacka);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// // // Function to initialize the stacks with test data
// void initialize_stacks(t_list **stacka, t_list **stackb)
// {
//     // Add some test data to stacka and stackb
//     push(stacka, 10);
//     push(stacka, 20);
//     push(stacka, 30);

//     push(stackb, 5);
//     push(stackb, 15);
//     push(stackb, 25);
// }

// // Function to test the move_nodes function
// void test_move_nodes()
// {
//     // Initialize stacks
//     t_list *stacka = NULL;
//     t_list *stackb = NULL;
//     initialize_stacks(&stacka, &stackb);

//     // Print initial state of stacks
//     printf("Initial state of stack A: ");
//     displaystack(stacka);
//     printf("Initial state of stack B: ");
//     displaystack(stackb);
// 	init_stack(&stacka, &stackb);
// 	displaytarget(stackb);
//     // Call the function to be tested
//     move_nodes(&stacka, &stackb);
//     move_nodes(&stacka, &stackb);

//     // Print final state of stacks
//     printf("Final state of stack A: ");
//     displaystack(stacka);
//     printf("Final state of stack B: ");
//     displaystack(stackb);
// }

// int main()
// {
//     // Test the move_nodes function
//     test_move_nodes();

//     return 0;
// }

// int main(void) {
//     // Initialize sample stacka and stackb
//     t_list *stacka = NULL;
//     t_list *stackb = NULL;

//     // Add some elements to stacka and stackb
//     // Example: Push 1, 2, 3 to stacka; Push 4, 5, 6 to stackb
//     push(&stacka, 1);
//     push(&stacka, 2);
//     push(&stacka, 3);
//     push(&stackb, 4);
//     push(&stackb, 5);
//     push(&stackb, 6);

//     // Print initial state of stacks
//     printf("Initial state of stack A: ");
//     displaystack(stacka);
//     printf("Initial state of stack B: ");
//     displaystack(stackb);

//     // Perform the rr operation
//     rr(&stacka, &stackb);

//     // Print final state of stacks after rr operation
//     printf("Final state of stack A after rr operation: ");
//     displaystack(stacka);
//     printf("Final state of stack B after rr operation: ");
//     displaystack(stackb);
// 	return (0);
// }



int main(void) 
{

    t_list *stacka = NULL;
    t_list *stackb = NULL;


    push(&stacka, 23);
	push(&stacka, 11);
	push(&stacka, 53);
	
    push(&stackb, 3);
    push(&stackb, 13);

	init_stack(&stacka, &stackb);

    displaystack(stacka);
	printf("ok\n");
	move_nodes(&stacka, &stackb);
    displaystack(stacka);
	return (0);
}

// smallest above median check karna hai !!!