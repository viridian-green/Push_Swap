/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:51:37 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/09 17:01:03 by ademarti         ###   ########.fr       */
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

void	insert_front(t_s **stack, int n)
{
	t_s	*new_node;
	t_s	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_s));
	if (!new_node)
		return ;
	new_node->value = n;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		(*stack) = new_node;
	}
	else
	{
		last_node = traverse_stack(*stack);
		last_node->next = new_node;
	}
}

void	initialize_stack(char **av, t_s **s_a, int ac)
{
	int		i;
	long	nbr;

	i = 0;
	while (av[i])
	{
		nbr = ft_atol(av[i]);
		if (check_duplicates(*s_a, ((int)nbr)) == 1)
			error_free(s_a, av, ac);
		if (error_syntax(av) == 1)
			error_free(s_a, av, ac);
		if ((nbr > INT_MAX) || (nbr < INT_MIN))
			error_free(s_a, av, ac);
		insert_front(s_a, (int)nbr);
		i++;
	}
}

void	set_index(t_s *stack)
{
	t_s		*s_stack;
	int		median;
	int		i;

	s_stack = stack;
	median = stack_len(s_stack) / 2;
	i = 0;
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

t_s	*traverse_stack(t_s *head)
{
	t_s	*temp;

	temp = head;
	if (!head)
		return (NULL);
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}
