/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:40:18 by bde-sous          #+#    #+#             */
/*   Updated: 2023/04/22 18:23:24 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freestack(t_node *stack)
{
	t_node	*aux;

	while (stack != NULL)
	{
		aux = stack;
		stack = stack->next;
		free(aux);
	}
}

int	ft_isint(const char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (0);
	if ((str[0] == '-' || str[0] == '+') && str[1] != '\0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
	}
	if (str[i] != '\0')
		return (0);
	if (ft_atoll(str) > INT_MAX || ft_atoll(str) < INT_MIN)
		return (0);
	return (1);
}

void	ft_virtual_sort(t_node **list, int ac)
{
	t_node	*current_node;
	t_node	*first_node;
	t_node	*compare_node;
	int		i;

	first_node = *list;
	current_node = first_node;
	while (current_node)
	{
		i = 0;
		compare_node = first_node;
		while (compare_node != NULL)
		{
			if (current_node->data < compare_node->data)
				i++;
			if (compare_node->next == NULL)
				break ;
			compare_node = compare_node->next;
		}
		current_node->pos = ac - i;
		current_node = current_node->next;
	}
}

t_node	*ft_add_to_list(t_node *list, int val)
{
	t_node	*new_node;
	t_node	*current_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = val;
	new_node->next = NULL;
	if (list == NULL)
		list = new_node;
	else
	{
		current_node = list;
		while (current_node != NULL)
		{
			if (current_node->data == val)
				ft_puterr(list, new_node);
			if (current_node->next == NULL)
				break ;
			current_node = current_node->next;
		}
		current_node->next = new_node;
	}
	return (list);
}

int	main(int argc, char **argv)
{
	t_node	*list;
	t_node	*list2;

	if (argc > 1)
	{
		list = NULL;
		list2 = NULL;
		ft_init_stack(argc, argv, &list);
		ft_virtual_sort(&list, argc - 1);
		if (!ft_is_sorted(list))
		{
			if (argc - 1 < 4)
				ft_three_sort(&list);
			else if (argc - 1 < 6)
				ft_five_sort(&list, &list2);
			else
				ft_rdx_sort(&list, &list2, ft_nbrlen(ft_find_max(list), 2), 0);
		}
		freestack(list);
	}
	return (0);
}

// int ft_print_list(t_node *stack) 
// {
//     t_node *current;
//     current = stack;
//     while (current != NULL) 
//     {
//         printf("valor: %d | pos virtual: %d \n", current->data,current->pos);
//         current = current->next;
//     }
//     printf("\n");
//     return(0);
// }
