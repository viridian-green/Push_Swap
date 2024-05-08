/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:51:37 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/08 13:12:23 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_s **s_a, t_s **s_b, t_s *cheapest_node)
{
	while (*s_a != cheapest_node && *s_b != cheapest_node->target)
		rr(s_a, s_b);
	set_index(*s_a);
	set_index(*s_b);
}

void	reverse_rotate_both(t_s **a, t_s **b, t_s *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target)
		rrr(a, b);
	set_index(*a);
	set_index(*b);
}

void	min_on_top(t_s **a)
{
	while ((*a)->value != find_min_value(*a)->value)
	{
		if (find_min_value(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	move_on_top(t_s **stack, t_s *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

int	stack_sorted(t_s **stack)
{
	t_s	*curr;

	curr = *stack;
	while (curr->next)
	{
		if (curr->value < curr->next->value)
			curr = curr->next;
		else
			return (0);
	}
	return (1);
}
