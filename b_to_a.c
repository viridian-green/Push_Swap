/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:57:55 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/07 16:48:27 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b_to_a(s_stack **a, s_stack **b)
{
	move_on_top(a, (*b)->target, 'a');
	pa(b, a);
}

void	prep_nodes_b(s_stack *a, s_stack *b)
{
	set_index(a);
	set_index(b);
	find_target_b(a, b);
}

void	find_target_b(s_stack *s_a, s_stack *s_b)
{
	s_stack	*p_a;
	s_stack	*p_b;
	s_stack	*target_node;
	int		closest_bigger;

	p_b = s_b;
	while (p_b)
	{
		closest_bigger = INT_MAX;
		p_a = s_a;
		while (p_a)
		{
			if (p_a->value > p_b->value && p_a->value < closest_bigger)
			{
				closest_bigger = p_a->value;
				target_node = p_a;
			}
			p_a = p_a->next;
		}
		if (closest_bigger == INT_MAX)
			p_b->target = find_min_value(s_a);
		else
			p_b->target = target_node;
		p_b = p_b->next;
	}
}
