/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:03:28 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/08 13:15:45 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_s *stack)
{
	int		counter;
	t_s		*temp;

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

t_s	*find_max_value(t_s *s_a)
{
	t_s		*max_value;
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

t_s	*find_min_value(t_s *s_a)
{
	long	min;
	t_s		*min_value;

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

t_s	*get_cheapest(t_s *stack)
{
	t_s	*temp;

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
