/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:09:12 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/26 14:06:42 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sortwo(t_list **stacka)
{
	t_list	*big;

	big = biggestnumber(*stacka);
	if (*stacka == big)
		ra_p(stacka);
}
