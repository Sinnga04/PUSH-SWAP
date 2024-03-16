/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:09:12 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/15 10:15:55 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	ft_isduplicate(int num, t_list *stack)
// {
// 	t_list	*current;

// 	current = stack;
// 	while (current != NULL)
// 	{
// 		if (current->content == num)
// 			return (1);
// 		current = current->next;
// 	}
// 	return (0);
// }

int	ft_atoi(const char *str)
{
	int	i;
	int	z;
	int	neg_counter;

	i = 0;
	z = 0;
	neg_counter = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' )
			neg_counter++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		z = z * 10 + (str[i] - '0');
		i++;
	}
	if (neg_counter == 1)
	{
		z *= -1;
	}
	return (z);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int		count(t_list *stacka);

int	above_median(t_list *stack)
{
	int	i;

	i = count(stack) / 2;
	// printf("%d\n", i);
	return (i);
}

// int main(void)
// {
// 	t_list *stacka = NULL;
// 		t_list *stackb = NULL;
// 	push(&stacka, 1);
// 	push(&stacka, 132);
// 	push(&stacka, 11);
// 	push(&stacka, 123);
// 	push(&stacka, 42341);
// 	push(&stacka, 1325);
// 	above_median(stackb);
// }
