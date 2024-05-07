/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:57:55 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/07 15:45:52 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b_to_a(s_stack **a, s_stack **b)
{
	move_on_top(a, (*b)->target, 'a');
	pa(b, a);
}

void prep_nodes_b(s_stack *a, s_stack *b)
{
	set_index(a);
	set_index(b);
	find_target_b(a, b);
}


void find_target_b(s_stack *s_a, s_stack *s_b)
{
	s_stack *ptr_a;
	s_stack *ptr_b;
	s_stack *target_node;
	int closest_bigger;

	ptr_b = s_b;
	while (ptr_b)
	{
		closest_bigger = INT_MAX;
		ptr_a = s_a; //Go back to top node.
		while (ptr_a)
		{
			if (ptr_a->value > ptr_b->value
			&& ptr_a->value < closest_bigger)
			{
				closest_bigger = ptr_a->value;
				target_node = ptr_a;
			}
			ptr_a = ptr_a->next;
		}
		if (closest_bigger == INT_MAX)
			ptr_b->target = find_min_value(s_a);
		else
			ptr_b->target = target_node;
		ptr_b = ptr_b->next;
	}
}