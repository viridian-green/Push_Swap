/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:03:28 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/07 17:08:21 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

int	stack_len(s_stack *stack)
{
	int		counter;
	s_stack	*temp;

	counter = 0;
	temp = stack;
	if (stack == NULL)
		return (0);
	while (temp)
	{
		temp = temp->next;
		counter++;
	}
	return (counter);
}

s_stack	*traverse_stack(s_stack *head)
{
	s_stack	*temp;

	temp = head;
	if (!head)
		return (NULL);
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}

int	stack_sorted(s_stack **stack)
{
	s_stack	*curr;

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

s_stack	*find_max_value(s_stack *s_a)
{
	s_stack	*max_value;
	long	max;

	max = LONG_MIN;
	if (!s_a)
		return (NULL);
	while (s_a)
	{
	if (s_a->value > max)
	{
		max = s_a->value;
		max_value = s_a;
	}
	s_a = (s_a)->next;
	}
	return (max_value);
}

s_stack	*find_min_value(s_stack *s_a)
{
	long	min;
	s_stack	*min_value;

	min = LONG_MAX;
	if (!s_a)
		return (NULL);
	while (s_a)
	{
	if (s_a->value < min)
	{
		min = s_a->value;
		min_value = s_a;
	}
	s_a = s_a->next;
	}
	return (min_value);
}

void	min_on_top(s_stack **a)
{
	while((*a)->value != find_min_value(*a)->value)
	{
		if (find_min_value(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
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
