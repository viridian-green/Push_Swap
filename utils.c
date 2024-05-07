/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:03:28 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/03 12:43:30 by ademarti         ###   ########.fr       */
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
	int	counter;
	counter = 0;

	s_stack *temp;
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
	s_stack *temp;

	temp = head;
	if (!head)
		return (NULL);
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}

int stack_sorted(s_stack **stack)
{
	s_stack *curr;

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

s_stack *find_max_value(s_stack *s_a)
{
	long	max;
	s_stack *max_value;

	max = LONG_MIN;
	if (!s_a)
		return NULL;
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

s_stack *find_min_value(s_stack *s_a)
{
	long min;
	s_stack *min_value;

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

void min_on_top(s_stack **a)
{
	while((*a)->value != find_min_value(*a)->value)
	{
		if (find_min_value(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}
