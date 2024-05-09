/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:54:54 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/09 16:33:10 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_stack(t_s **stack)
{
	t_s	*temp;
	t_s	*current;

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

void	free_args_error(char **args)
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
	free(args - 1);
}

void	error_free(t_s **s_a, char **av, int ac)
{
	free_stack(s_a);
	if (ac == 2)
		free_args_error(av);
	write(2, "Error\n", 6);
	exit(1);
}
