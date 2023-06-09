/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:47:09 by bde-sous          #+#    #+#             */
/*   Updated: 2023/04/22 18:02:29 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_max(t_node *head)
{
	int		max;
	t_node	*current;

	max = head->pos;
	current = head->next;
	while (current != NULL)
	{
		if (current->pos > max)
			max = current->pos;
		current = current->next;
	}
	return (max);
}

int	ft_find_min(t_node *head)
{
	int		min;
	t_node	*current;

	min = head->pos;
	current = head->next;
	while (current != NULL)
	{
		if (current->pos < min)
			min = current->pos;
		current = current->next;
	}
	return (min);
}

int	ft_is_sorted(t_node *head)
{
	t_node	*current;

	current = head;
	while (current != NULL && current->next != NULL)
	{
		if (current->pos > current->next->pos)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_stack_length(t_node *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	ft_nbrlen(long n, int base)
{
	int	len;

	len = 0;
	if (!base)
		base = 10;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= base;
	}
	return (len);
}
