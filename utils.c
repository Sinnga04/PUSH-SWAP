/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:20:17 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/26 13:03:35 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *ft_lstnew(int content)
{
    t_list  *current;
    current = malloc (sizeof(t_list));
    if (!current)
        return (NULL);
    if (!content)
    {
        current->content = 0;
        current->next = NULL;
        return (current);
    }
    current->content = content;
    current->next = NULL;
    return (current);
}


void	ft_lstadd_back(t_list **stack, t_list *newnode)
{
	t_list	*last;

	if (!stack || !newnode)
		return ;
	if (!*stack)
	{
		*stack = newnode;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = newnode;
}

void	ft_free_all(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free (s);
}
void ft_free(t_list *lst) 
{
    t_list *current;

    while (lst != NULL) {
        current = lst; 
        lst = lst->next; 
        free(current); 
    }
}


