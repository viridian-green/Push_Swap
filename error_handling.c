/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:17:37 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/07 16:32:44 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	handle_arguments(char **av, s_stack **s_a)
// {
// 	int	i;
// 	int	nbr_args;

// 	i = 0;
// 	nbr_args = 0;
// 	while (av[i])
// 	{
// 		nbr_args++;
// 		i++;
// 	}
// 	if (av[1][0] == '\0')
// 		error_free(s_a);
// 	// if (av[1][0] == '\0')
// 	// 	error_free(s_a);
// 	if (nbr_args < 2)
// 		exit(1);
// }

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

// int	error_syntax(char **nbr)
// {
// 	int	i;

// 	i = 0;
// 	while (nbr[i])
// 	{
// 		if ((nbr[i] == '-' && nbr[i + 1] == '-') || ((nbr[i] == '-')
// 		&& !(nbr[i + 1] >= '0' && nbr[i + 1] <= '9')) ||
// 		((nbr[i] == '+') && (nbr[i + 1] == '+')) || (!(nbr[i] >= '0' && nbr[i] <= '9')
// 		 && nbr[i] != '+' && nbr[i] != '-' && nbr[i] != ' '))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

int	error_syntax(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		if (av[i][j] != '+' && av[i][j] != '-' \
			&& !(av[i][j] >= '0' && av[i][j] <= '9'))
			return (1);
		if ((av[i][j] == '+' || av[i][j] == '-') && \
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

void	ft_free_args(char **args)
{
	int	i;

	i = 0;
	if (!args || !(*args))
		return ;
	while (args[i])
	{
		free(args[i]);
		args[i] = NULL;
		i++;
	}
	free(args);
}

void	free_stack(s_stack **stack)
{
	s_stack	*temp;
	s_stack	*current;

	if (NULL == stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current ->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void free_args_error(char **args)
{
	int	i;

	i = -1;
	if (!args || !(*args))
		return ;
	while (args[i])
	{
		free(args[i]);
		args[i] = NULL;
		i++;
	}
	free(args -1);
}

void	error_free(s_stack **s_a, char **av)
{
	free_stack(s_a);
	free_args_error(av);
	write(2, "Error\n", 6);
	exit(1);
}
