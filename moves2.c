/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:16:07 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/26 16:48:33 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stacksorted(t_list **stacka)
{
	t_list	*current;

	current = *stacka;
	while (current != NULL && current->next != NULL)
	{
		if (current->content > current->next->content)
			return (1);
		current = current->next;
	}
	return (0);
}

void	ra_p(t_list **stacka)
{
	ra(stacka);
	write(1, "ra\n", 3);
}

void	rb_p(t_list **stackb)
{
	rb(stackb);
	write(2, "rb\n", 3);
}

void	rra_p(t_list **stacka)
{
	rra(stacka);
	printf("rra\n");
}

void	rrb_p(t_list **stackb)
{
	rrb(stackb);
	printf("rrb\n");
}
