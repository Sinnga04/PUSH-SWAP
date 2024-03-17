/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:34:25 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/17 12:12:54 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// void sortAndCheckConditions(t_list *stacka)
// {
// 	int first = stacka->content;
//     int second = stacka->next->content;
//     int third = stacka->next->next->content;
// 	printf("Okiushd\n");
//     if (first > second && second < third && third > first)
//     {
//         printf("Perform rra\n");
//         sa(&stacka);
//         // rra(&stacka);
//     }
//     else if (first > second && first > third && second < third)
//     {
//         printf("Perform rra and sa\n");
//         // sa(&stacka);
//         ra(&stacka);
//     }
//     else if (third > second && third > first && second > first)
//     {
//         // printf("Perform sa and rra\n");
//         // rra(&stacka);
//         // sa(&stacka);
// 		//it is alredy sorted
// 		printf("oka\n");
//     }
//     else if (first < second && first < third && second > third)
//     {
//         printf("Perform ra\n");
// 		sa(&stacka);
//         ra(&stacka);
//     }
//     else if (first < second && first > third && second > third)
//     {
//         printf("Perform sa\n");
//         sa(&stacka);
// 		// rra(&stacka);
//     }
// }


void sortAndCheckConditions(t_list **stacka)
{
	t_list *big;
	big = biggestnumber(*stacka);
	if (*stacka == big)
		ra(stacka);
	else if ((*stacka)->next == big)
		rra(stacka);
	if ((*stacka)->content > (*stacka)->next->content)
		sa(stacka);
}