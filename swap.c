/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:36:55 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/08 13:15:06 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_s **stack)
{
	int		len;
	t_s		*node_one;
	t_s		*node_two;

	len = stack_len(*stack);
	if (stack == NULL || *stack == NULL || 1 == len)
		return ;
	node_one = (*stack)->next;
	node_two = *stack;
	node_two->next = node_one->next;
	node_one->next = node_two;
	*stack = node_one;
}

void	sa(t_s **s_a)
{
	swap(s_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_s **s_b)
{
	swap(s_b);
	ft_putstr_fd("sb\n", 1);
}
