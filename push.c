/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:31:03 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/07 11:30:55 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(s_stack **src, s_stack **dest)
{
	s_stack	*node_to_push;

	if (*src == NULL)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*dest == NULL)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		*dest = node_to_push;
	}
}

void	pa(s_stack **stack_b, s_stack **stack_a)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(s_stack **stack_a, s_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
