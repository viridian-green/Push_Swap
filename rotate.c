/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:19:07 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/08 13:19:43 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_s **stack)
{
	t_s		*to_rotate;
	t_s		*last_node;
	int		len;

	len = stack_len(*stack);
	if (NULL == stack || NULL == *stack || 1 == len)
		return ;
	last_node = traverse_stack(*stack);
	to_rotate = *stack;
	last_node->next = to_rotate;
	*stack = (*stack)->next;
	last_node->next->next = NULL;
}

void	rb(t_s **s_b)
{
	rotate(s_b);
	ft_putstr_fd("rb\n", 1);
}

void	ra(t_s **s_a)
{
	rotate(s_a);
	ft_putstr_fd("ra\n", 1);
}

void	rr(t_s **s_a, t_s **s_b)
{
	rotate(s_a);
	rotate(s_b);
	ft_putstr_fd("rr\n", 1);
}
