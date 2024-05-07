/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:12:21 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/07 16:43:18 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_nodes_a(s_stack **s_a, s_stack **s_b)
{
	set_index(*s_a);
	set_index(*s_b);
	find_target_a(*s_a, *s_b);
	find_cost_a(*s_a, *s_b);
	find_cheapest(*s_a);
}

void	find_target_a(s_stack *s_a, s_stack *s_b)
{
	s_stack	*target_node;
	s_stack	*p_a;
	s_stack	*p_b;
	int		closest_smaller;

	p_a = s_a;
	while (p_a)
	{
		closest_smaller = INT_MIN;
		p_b = s_b;
		while (p_b)
		{
			if (p_b->value < p_a->value && p_b->value > closest_smaller)
			{
				closest_smaller = p_b->value;
				target_node = p_b;
			}
			p_b = p_b->next;
		}
		if (closest_smaller == INT_MIN)
			p_a->target = find_max_value(s_b);
		else
			p_a->target = target_node;
		p_a = p_a->next;
	}
}

void	find_cost_a(s_stack *s_a, s_stack *s_b)
{
	int		len_sa;
	int		len_sb;
	s_stack	*ptr_a;

	ptr_a = s_a;
	len_sa = stack_len(s_a);
	len_sb = stack_len(s_b);
	while (ptr_a)
	{
		ptr_a->cost = ptr_a->index;
		if (!(ptr_a->above_median))
			ptr_a->cost = len_sa - (ptr_a->index);
		if (ptr_a->target->above_median)
			ptr_a->cost += ptr_a->target->index;
		else
			ptr_a->cost += len_sb - (ptr_a->target->index);
		ptr_a = ptr_a->next;
	}
}

void	move_a_to_b(s_stack **a, s_stack **b)
{
	s_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if ((cheapest_node->above_median) && (cheapest_node->target->above_median))
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) \
	&& !(cheapest_node->target->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	move_on_top(a, cheapest_node, 'a');
	move_on_top(b, cheapest_node->target, 'b');
	pb(a, b);
}
