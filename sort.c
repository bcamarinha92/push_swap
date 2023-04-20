/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:47:31 by bde-sous          #+#    #+#             */
/*   Updated: 2023/04/20 20:31:07 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three_sort(t_node **stack)
{
	int	maximum;
	int	minimum;

	maximum = ft_find_max(*stack);
	minimum = ft_find_min(*stack);
	while (!ft_is_sorted(*stack))
	{
		if ((*stack)->data != minimum && (*stack)->next->data == maximum)
        {
			ft_rever_rotate(stack,"rra\n");
        }
		else if ((*stack)->data == maximum && (*stack)->next->data == minimum)
        {
			ft_rotate_node(stack,"ra\n");
        }
		else
        {
			ft_swap_node(stack,"sa\n");
        }
        
	}
}

void	ft_five_sort(t_node **stack, t_node **stack2)
{
	while (ft_stack_length(*stack) > 3)
	{
		if ((*stack)->data == ft_find_min(*stack))
        {
			ft_move_node(stack, stack2,"pb\n");
        }
		else
        {
            if ((*stack)->next->data == ft_find_min(*stack))
            {
			    ft_rotate_node(stack,"ra\n");
            }
            else
            {
                ft_rever_rotate(stack,"rra\n");
            }
        }
	}
    ft_three_sort(stack);
    while (ft_stack_length(*stack2))
    {
        ft_move_node(stack2, stack, "pa\n");
    }
}

int	ft_radix_sort(t_node **a, t_node **b, int max_len, int right_shift)
{
	int	i;
	int	len;

    i = -1;
    if (right_shift > max_len || ft_is_sorted(*a))
	{
        len = ft_stack_length(*b);
        while (++i < len)
        {
            ft_move_node(b,a,"pa\n");
        }
		return (0);
	}
	len = ft_stack_length(*a);
	while (++i < len && !ft_is_sorted(*a))
	{
		if (!((*a)->data >> right_shift & 1))
        {
			ft_move_node(a, b,"pb\n");
        }
		else
        {
			ft_rotate_node(a,"ra\n");
        }
	}
	i = -1;
	len = ft_stack_length(*b);
	while (++i < len)
    {
		ft_move_node(b,a,"pa\n");
    }
	return (ft_radix_sort(a, b, max_len, right_shift + 1));
}