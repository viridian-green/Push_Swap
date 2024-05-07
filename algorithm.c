/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:26:22 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/07 11:25:47 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int tiny_sort(s_stack **s_a)
{
	if (stack_len(*s_a) == 2)
		sa(s_a);
	else if (stack_len(*s_a) == 3)
	{
		sort_three(s_a);
		return 0;
	}
	return 1;
}

void sort_three(s_stack **s_a)
{
	s_stack *biggest_node;

	biggest_node = find_max_value(*s_a);
	if (*s_a == biggest_node)
		ra(s_a);
	else if ((*s_a)->next == biggest_node)
		rra(s_a);
	if ((*s_a)->value > (*s_a)->next->value)
		sa(s_a);
}

void	sorting_stacks(s_stack **a, s_stack **b)
{
	if (stack_len(*a) > 3 && !stack_sorted(a))
		pb(a, b);
	if (stack_len(*a) > 3  && !stack_sorted(a))
	{
		pb(a, b);
	}
	while (stack_len(*a) > 3  && !stack_sorted(a))
	{
		prep_nodes_a(a, b);
		move_a_to_b(a, b);
	}
	// At this point, the nodes are sorted in stack B in descending order.
	tiny_sort(a);
	while (*b)
	{
		prep_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_index(*a);
	min_on_top(a);
}

void set_index(s_stack *stack)
{
	s_stack *s_stack;
	s_stack = stack;
	int median = stack_len(s_stack) / 2;
	int i = 0;

	while (s_stack)
	{
		s_stack->index = i;
		if (i <= median)
			s_stack->above_median = true;
		else
			s_stack->above_median = false;
		s_stack = s_stack->next;
		i++;
	}
}

void find_cheapest(s_stack *stack)
{
	int cheapest_value;
	s_stack *cheapest_node;
	s_stack *ptr;

	ptr = stack;
	if (!stack)
		return ;
	cheapest_value = INT_MAX;
	while (ptr)
	{
		if (ptr->cost < cheapest_value)
		{
			cheapest_value = ptr->cost;
			cheapest_node = ptr;
		}
		ptr = ptr->next;
	}
	cheapest_node->cheapest = true;
}

s_stack	*get_cheapest(s_stack *stack)
{
	s_stack	*temp;

	temp = stack;
	if (!stack)
		return (NULL);
	while (temp)
	{
		if (temp->cheapest == true)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

void	move_on_top(s_stack **stack, s_stack *top_node, char stack_name)
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