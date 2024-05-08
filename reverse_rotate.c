/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:21:33 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/08 13:19:34 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_s **stack)
{
	int		len;
	t_s		*prev;
	t_s		*current;

	len = stack_len(*stack);
	if (NULL == stack || NULL == *stack || 1 == len)
		return ;
	prev = NULL;
	current = *stack;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *stack;
	*stack = current;
}

void	rra(t_s **s_a)
{
	reverse_rotate(s_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_s **s_b)
{
	reverse_rotate(s_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_s **s_a, t_s **s_b)
{
	reverse_rotate(s_a);
	reverse_rotate(s_b);
	ft_putstr_fd("rrr\n", 1);
}
