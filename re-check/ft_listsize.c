/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:23:01 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/10 18:40:32 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int ft_lstsize(t_list *lst)
{
	int count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

// int main(void)
// {
// 	  t_list *head = malloc(sizeof(t_list));
//     head->data = 1;
//     head->next = malloc(sizeof(t_list));
//     head->next->data = 2;
//     int size = ft_lstsize(head);
//     printf("Size of the list: %d\n", size);
//     t_list *current = head;
//     while (current != NULL) {
//         t_list *temp = current;
//         current = current->next;
//         free(temp);
//     }

//     return 0;
// }

// int	ft_isDuplicate(int num, Stack *stack)
// {
// 	Node	*current;

// 	current = stack->top;
// 	while (current != NULL)
// 	{
// 		if (current->data == num)
// 			return (1);
// 		current = current->next;
// 	}
// 	return (0);
// }

// int main(int argc, char *argv[]) {
//     // Create a stack and initialize it
//     Stack stackA;
//     stackA.top = NULL;

//     // Call check function to process command-line arguments
// 	if (ft_isDuplicate(1, &stackA) == 0)
//     	printf("ok");
// 	else
//     	printf("wrong");
		
	

//     return 0;
// }
