/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:23:44 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/17 11:36:13 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void largestmove(Stack *stackA, Stack *stackB)
// {
//    int largest = findLargestNumber(stackA);
//         if (stackA->top->data == largest )
//             pb(stackA, stackB);
//         else if (stackA->top->next->data == largest )
//         {
//             sa(stackA);
//             pb(stackA, stackB);
//         }
//         else if (largest == stackA->top->next->next->data )
//         {
//             ra(stackA);
//             ra(stackA);
//             pb(stackA, stackB);
//         }
//         else if (largest == stackA->top->next->next->next->data)
//         {
//             ra(stackA);
//             ra(stackA);
//             ra(stackA);
//             pb(stackA, stackB);
//         }
//         else if (largest == stackA->top->next->next->next->next
//         ->data)
//         {
//             rra(stackA);
//             pb(stackA, stackB);
//         }
// }

// void secondlargestmove(Stack *stackA, Stack *stackB)
// {
//      int secondLargest = findLargestNumber(*stackA);
//         if (stackA->top->data == secondLargest )
//         {
//             pb(stackA, stackB);
//         }
//         else if (stackA->top->next->data == secondLargest )
//         {
//             sa(stackA);
//             pb(stackA, stackB);
//         }
//         else if (secondLargest == stackA->top->next->next->data )
//         {
//             ra(stackA);
//             ra(stackA);
//             pb(stackA, stackB);
//         }
//         else if (secondLargest == stackA->top->next->next->next->data)
//         {
//             ra(stackA);
//             ra(stackA);
//             ra(stackA);
//             pb(stackA, stackB);
//         }
//         else if (secondLargest == stackA->top->next->next->next->next
//         ->data)
//         {
//             rra(stackA);
//             pb(stackA, stackB);
//         }
// }

// void sortfivenumbers(Stack *stackA, Stack *stackB)
// {

//         largestmove(stackA, stackB);
//         secondlargestmove(stackA, stackB);
//         sortAndCheckConditions(stackA);
//         pa(stackA, stackB);
//         pa(stackA, stackB);
// }


t_list	*ft_lstnew(int content)
{
	t_list	*newnode;

	newnode = malloc (sizeof(t_list));
	if (!newnode)
		return (NULL);
	if (!content)
	{
		newnode->content = 0;
		newnode->next = NULL;
		return (newnode);
	}
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
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
	{
		last = last->next;
	}
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

void	stack_init(t_list **stack, char **argv)
{
	t_list	*newnode;
	char	**num;
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		num = ft_split(argv[i], ' ');
		j = 0;
		while (num[j])
		{
			newnode = ft_lstnew(ft_atoi(argv[j]));
			ft_lstadd_back(stack, newnode);
			j++;
		}
		ft_free_all(num);
		i++;
	}
}

void	ft_print_stack(t_list *stack)
{
	while (stack)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
}

int	ft_check_error1(char **s)
{
	int	i;
	int	j;

	i = 1;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (ft_isdigit(s[i][j]))
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int ft_isduplicate(t_list *stack)
{
	int		i;
	t_list	*tmp;
	t_list	*new;
	int		num;

	i = 0;
	new = stack;
	while (new)
	{
		tmp = new;
		num = new->content;
		i = 0;
		while (tmp)
		{
			if (tmp->content == num)
				i++;
			if (i > 1)
			{
				return (1);
			}
			tmp = tmp->next;
		}
		new = new->next;
	}
	return (0);
}
