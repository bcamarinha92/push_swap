/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-sous <bde-sous@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:40:12 by bde-sous          #+#    #+#             */
/*   Updated: 2023/04/20 21:06:37 by bde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_node 
{
    int data;
    int pos;
    struct s_node* next;
} t_node;

void	ft_virtual_sort(t_node** list, int ac);
void	ft_three_sort(t_node **stack);
void	ft_five_sort(t_node **stack, t_node **stack2);
void	ft_rotate_node(t_node **stack, char *move);
void	ft_rever_rotate(t_node **list, char *move);
void	ft_move_node(t_node **stack_src, t_node **stack_dst, char *move);
void	freestack(t_node *stack); 
t_node*	ft_swap_node(t_node** list, char *move);
int		ft_radix_sort(t_node **a, t_node **b, int max_len, int right_shift);
int		ft_find_max(t_node* head);
int		ft_find_min(t_node* head);
int		ft_is_sorted(t_node* head);
int		ft_stack_length(t_node *stack);
int		ft_nbrlen(long n, int base);
t_node*	ft_add_to_list(t_node* list, int val);

#endif