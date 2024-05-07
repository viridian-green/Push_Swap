/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:51:37 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/07 17:06:34 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_front(s_stack **stack, int n)
{
	s_stack	*new_node;
	s_stack	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(s_stack));
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

void	initialize_stack(char **av, s_stack **s_a)
{
	int		i;
	long	nbr;

	i = 0;
	while (av[i])
	{
		nbr = ft_atol(av[i]);
		if (check_duplicates(*s_a, ((int)nbr)) == 1)
			error_free(s_a, av);
		if (error_syntax(av) == 1)
			error_free(s_a, av);
		if ((nbr > INT_MAX) || (nbr < INT_MIN))
			error_free(s_a, av);
		insert_front(s_a, (int)nbr);
		i++;
	}
}

void	set_index(s_stack *stack)
{
	s_stack	*s_stack;
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
