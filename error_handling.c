/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:17:37 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/07 16:56:41 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(s_stack *s_a, int n)
{
	s_stack	*temp;

	temp = s_a;
	if (!s_a)
		return (0);
	while (temp)
	{
		if (temp->value == n)
		{
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

int	error_syntax(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		if (av[i][j] != '+' && av[i][j] != '-'
			&& !(av[i][j] >= '0' && av[i][j] <= '9'))
			return (1);
		if ((av[i][j] == '+' || av[i][j] == '-') &&
			!(av[i][j + 1] >= '0' && av[i][j + 1] <= '9'))
			return (1);
		while (av[i][++j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (1);
		}
		i++;
	}
	return (0);
}
