/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opers.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:32:15 by bde-sous          #+#    #+#             */
/*   Updated: 2023/04/22 18:23:51 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_node(t_node **stack, char *move)
{
	t_node	*tmp;
	t_node	*first;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	first = *stack;
	while (tmp->next)
		tmp = tmp->next;
	*stack = (*stack)->next;
	first->next = NULL;
	tmp->next = first;
	ft_putstr_fd(move, 1);
}

void	ft_rever_rotate(t_node **list, char *move)
{
	t_node	*current_node;
	t_node	*previous_node;

	current_node = *list;
	previous_node = NULL;
	if (*list == NULL || (*list)->next == NULL)
		return ;
	current_node = *list;
	previous_node = NULL;
	while (current_node->next != NULL)
	{
		previous_node = current_node;
		current_node = current_node->next;
	}
	current_node->next = *list;
	*list = current_node;
	previous_node->next = NULL;
	ft_putstr_fd(move, 1);
}

void	ft_move_node(t_node **stack_src, t_node **stack_dst, char *move)
{
	t_node	*element;

	if (*stack_src == NULL)
		return ;
	element = *stack_src;
	*stack_src = (*stack_src)->next;
	element->next = *stack_dst;
	*stack_dst = element;
	ft_putstr_fd(move, 1);
}

t_node	*ft_swap_node(t_node **list, char *move)
{
	int	temp;
	int	pos;

	if ((*list) == NULL || (*list)->next == NULL)
		return (*list);
	temp = (*list)->data;
	pos = (*list)->pos;
	(*list)->data = (*list)->next->data;
	(*list)->pos = (*list)->next->pos;
	(*list)->next->data = temp;
	(*list)->next->pos = pos;
	ft_putstr_fd(move, 1);
	return (*list);
}

void	ft_puterr(t_node *stack, t_node *node)
{
	if (stack != NULL)
		freestack(stack);
	if (node != NULL)
		free(node);
	ft_putstr_fd("Error\n", 1);
	exit(1);
}
