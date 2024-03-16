/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:38:25 by kamsingh          #+#    #+#             */
/*   Updated: 2024/02/01 17:48:07 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_num_digits(int n)
{
	int	numdigits;

	numdigits = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		numdigits++;
	}
	return (numdigits);
}

char	*ft_itoa(int num)
{
	long	n;
	int		sign;
	int		numdigits;
	char	*str;

	n = num;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	numdigits = get_num_digits(n) + (sign == -1);
	str = (char *)malloc((numdigits + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[numdigits] = '\0';
	while (numdigits > 0)
	{
		str[--numdigits] = '0' + (n % 10);
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
