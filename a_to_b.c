/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:12:21 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/08 13:18:51 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_nodes_a(t_s **s_a, t_s **s_b)
{
	set_index(*s_a);
	set_index(*s_b);
	find_target_a(*s_a, *s_b);
	find_cost_a(*s_a, *s_b);
	find_cheapest(*s_a);
}

void	find_target_a(t_s *s_a, t_s *s_b)
{
	t_s		*target_node;
	t_s		*p_a;
	t_s		*p_b;
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

void	find_cost_a(t_s *s_a, t_s *s_b)
{
	int		len_sa;
	int		len_sb;
	t_s		*ptr_a;

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

void	move_a_to_b(t_s **a, t_s **b)
{
	t_s	*cheapest_node;

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
