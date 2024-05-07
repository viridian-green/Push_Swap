/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:19:07 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/07 12:09:27 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(s_stack **stack)
{
	s_stack	*to_rotate;
	s_stack	*last_node;
	int		len;

	len = stack_len(*stack);
	if (NULL == stack || NULL == *stack || 1 == len)
		return ;
	last_node = traverse_stack(*stack);
	to_rotate = *stack;
	last_node->next = to_rotate; //this makes first node to last node
	*stack = (*stack)->next; //this removes the top node from stack
	last_node->next->next = NULL; //this terminates the stack
}

void	rb(s_stack **s_b)
{
	rotate(s_b);
	ft_putstr_fd("rb\n", 1);
}

void	ra(s_stack **s_a)
{
	rotate(s_a);
	ft_putstr_fd("ra\n", 1);
}

void	rr(s_stack **s_a, s_stack **s_b)
{
	rotate(s_a);
	rotate(s_b);
	ft_putstr_fd("rr\n", 1);
}
