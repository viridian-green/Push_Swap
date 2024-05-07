/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:51:37 by ademarti          #+#    #+#             */
/*   Updated: 2024/04/30 12:06:19 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_both(s_stack **s_a, s_stack **s_b, s_stack *cheapest_node)
{
	while (*s_a != cheapest_node && *s_b != cheapest_node->target)
		rr(s_a, s_b);
	set_index(*s_a);
	set_index(*s_b);
}

void reverse_rotate_both(s_stack **s_a, s_stack **s_b, s_stack *cheapest_node)
{
	while (*s_a != cheapest_node && *s_b != cheapest_node->target)
		rrr(s_a, s_b);
	set_index(*s_a);
	set_index(*s_b);
}