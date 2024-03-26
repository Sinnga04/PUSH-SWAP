/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:22:25 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/26 14:55:08 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			newnode = ft_lstnew(ft_atoi(num[j]));
			ft_lstadd_back(stack, newnode);
			j++;
		}
		ft_free_all(num);
		i++;
	}
}

void	free_list(t_list *head)
{
	t_list	*tmp;

	if (head == NULL)
		return ;
	if (head->next == NULL)
	{
		free(head);
		return ;
	}
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int	ft_isdigits(int c)
{
	return ((c >= '0' && c <= '9') || c == '-');
}

int	ft_isdigits_str(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL || *str == '\0')
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	if (!ft_isdigits(str[i]))
		return (1);
	while (str[i])
	{
		if (!ft_isdigits(str[i]) && str[i] != ' ' && str[i] != '\t'
			&& str[i] == '\0')
			return (1);
		else if (ft_isalpha(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	sort(t_list **stacka, t_list **stackb)
{
	int	stack_len;

	stack_len = count(*stacka);
	while (stack_len-- > 3)
		pb(stacka, stackb);
	sorthree(stacka);
	while (*stackb != NULL)
	{
		init_stack(stacka, stackb);
		move_nodes(stacka, stackb);
	}
	indexing(stacka);
	easy_move_a(stacka, smallestnumber(*stacka));
}

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*stackb;
	int		stack_len;

	(void)argc;
	stacka = NULL;
	stackb = NULL;
	stack_init(&stacka, argv);
	if (ft_check_error1(argv) || ft_check_error2(argv)
		|| ft_isduplicate(stacka))
		return (ft_error(), 1);
	stack_len = count(stacka);
	if (stack_len == 1)
		return (free_list(stacka), 0);
	else if (stack_len == 2)
		sortwo(&stacka);
	else if (stack_len == 3)
		sorthree(&stacka);
	else if (stack_len > 3)
		sort(&stacka, &stackb);
	free_list(stacka);
	free_list(stackb);
	return (0);
}
