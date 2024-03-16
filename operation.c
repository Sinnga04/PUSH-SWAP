/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamsingh <kamsingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:23:44 by kamsingh          #+#    #+#             */
/*   Updated: 2024/03/15 09:12:39 by kamsingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void sort2num(Stack *stackA) {
//     if (stackA->top != NULL && stackA->top->next != NULL) {
//         int first = stackA->top->data;
//         int second = stackA->top->next->data;
//         if (first < second)
//             sa(stackA);
//     }
// }

// int ft_lstsize(t_list *lst);

// void    helposition(Stack *stackA, Stack *stackB)
// {
// int largestPosition = helperfive(stackA);
// if (largestPosition == 0) {
//     pb(stackA, stackB);
// } else if (largestPosition == 1) {
//     sa(stackA);
//     pb(stackA, stackB);
// } else if (largestPosition == 2) {
//     ra(stackA);
//     ra(stackA);
//     pb(stackA, stackB);
// } else if (largestPosition == 3) {
//     ra(stackA);
//     ra(stackA);
//     ra(stackA);
//     pb(stackA, stackB);
// } else if (largestPosition == ft_lstsize((t_list *)stackA) - 1) {
//     rra(stackA);
//     pb(stackA, stackB);
// }
// }

// int    helperfive(Stack *stackA)
// {
// int largest = 0;
// Node *current = stackA->top;
// int position = 0;
// int largestPosition = 0;

// while (current != NULL) {
//     if (current->data > largest) {
//         largest = current->data;
//         largestPosition = position;
//     }
//     current = current->next;
//     position++;
//     }
//     return (position);
// }
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
// void mechturk(Stack *stackA, Stack *stackB) {
//     int max = findLargestNumber(stackA);
//     int min = findSmallestNumber(stackA);
//     printf("\nole%d\n", max);
//     printf("\nnole%d\n", min);
//     Node* current = stackA->top;
//     while (current != NULL) {
//         if (current->data < max ) {
//             // pa(stackA, stackB);
//             // printf("\nthis is %d\n", current->data);
//             pb(stackA, stackB);
//             if (isEmpty(stackA)) {
//                 break; 
//             }
//         }
//         current = current->next;
//     }
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

// int	count(t_list *stack)
// {
// 	int		i;
// 	t_list	*current;

// 	i = 0;
// 	current = stack;
// 	while (current != NULL)
// 	{
// 		i++;
// 		current = current->next;
// 	}
// 	return (i);
// }

int	main(int argc, char **argv)
{
	(void)argc;
	t_list	*stacka;
	int		i;

	stacka = NULL;
	//t_list *stackB = NULL;
	if (ft_check_error1(argv) == 1)
	{
		write (2, "Error1\n", 7);
		return (1);
	}
	stack_init(&stacka, argv);
	ft_print_stack(stacka);
	i = count(stacka);
	if (i == 2)
		printf("1");
	else
		printf("2");
}

// int main(int argc, char *argv[]) {
//     Stack stackA;
//     initializeStack(&stackA);
//     Stack stackB;
//     initializeStack(&stackB);
//     //int num = 0;
//     if (check(argc, argv, &stackA) == EXIT_FAILURE)
//         exit(EXIT_FAILURE);
//     //push(&stackA, num);
//     // printf("Initial stack contents:\n");
//     displayStack(&stackA);
//     if (argc == 3)
//         sort2num(&stackA);
//     else if (argc ==  4)
//         sortAndCheckConditions(&stackA);
//     else if (argc ==  5)
//             sortfour(&stackA, &stackB);
//         else if (argc == 6) {
//             sortfivenumbers(&stackA, &stackB);
//         }
//         else if (argc == 11)
//         {  
//             printf("ok");
//             mechturk(&stackA, &stackB);
//         }
//         //printf("\nFinal stack contents:\n");
//         displayStack(&stackA);
//         return EXIT_SUCCESS;
// }