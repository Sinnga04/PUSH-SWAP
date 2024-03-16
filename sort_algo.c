/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:34:25 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/16 17:32:51 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void    sortAndCheckConditions(t_list *stackA)
// {
//     int first;
//     int second;
//     int third;

//     if (stackA != NULL && stackA->next != NULL) 
//     {
//         // first = stackA->top->data;
//         // second = stackA->top->next->data;
//         // third = stackA->top->next->next->data;

//     if (stackA->next->content > stackA->next->next->content 
//			&& stackA->next->next->content < stackA->next->next->next->content
//     && stackA->next->next->next->content > stackA->next->content)
//         rra(stackA);
//     else if (stackA->next->content > stackA->next->next->content &&
		//stackA->next->content > stackA->next->next->next->content
//     && stackA->next->next->content < stackA->next->next->next->content)
//     {
//         rra(stackA);
//         sa(stackA); 
//     }
//     else if(stackA->next->next->next->content > stackA->next->next->content 
	//&& stackA->next->next->next->content > stackA->next->content
//     && stackA->next->next->content > stackA->next->content)
//     {
//         sa(stackA);
//         rra(stackA);
//     }
//     else if (stackA->next->content < stackA->next->next->content
		//&& stackA->next->content < stackA->next->next->next->content 
//     && stackA->next->next->content > stackA->next->next->next->content)
//         ra(stackA);
//     else if(stackA->next->content < stackA->next->next->content
		//&& stackA->next->content > stackA->next->next->next->content
//     && stackA->next->next->content > stackA->next->next->next->content)
//         sa(stackA);
//     }
// }

// void sortfour(Stack *stackA, Stack *stackB)
// {
//     if (stackA->top != NULL && stackA->top->next != NULL
		//&& stackA->top->next->next != NULL
// 		&& stackA->top->next->next->next != NULL)
// 	{

//     int lok = findLargestNumber(stackA);
//     if (stackA->top->data == lok)
//         pb(stackA,stackB);
//     else if (stackA->top->next->data == lok)
//     {
//         sa(stackA);
//         pb(stackA,stackB);
//     }
//     else if(stackA->top->next->next->data == lok)
//     {
//         ra(stackA);
//         ra(stackA);
//         pb(stackA,stackB);
//     }
//     else if (stackA->top->next->next->next->data == lok)
//     {
//         rra(stackA);
//         pb(stackA, stackB);
//     }
//     sortAndCheckConditions(stackA);
//     pa(stackA, stackB);
//     }
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
//     print_stack(stacka);
//     printf("Initial state of stack B: ");
//     print_stack(stackb);

//     // Call the move_nodes function
//     move_nodes(&stacka, &stackb);

//     // Print final state of stacks after move_nodes function
//     printf("Final state of stack A: ");
//     print_stack(stacka);
//     printf("Final state of stack B: ");
//     print_stack(stackb);
// 	return (0);
// }