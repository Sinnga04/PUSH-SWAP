/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:16:07 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/17 11:35:28 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
