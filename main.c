/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:57:32 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/08 15:20:51 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_s	*a;
	t_s	*b;
	char **av_split;

	a = NULL;
	b = NULL;
	av_split = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
	{
		av_split = ft_split(av[1], ' ');
		initialize_stack(av_split + 1, &a);
	}
	else
		initialize_stack(av + 1, &a);
	if (stack_sorted(&a))
		return (0);
	sorting_stacks(&a, &b);
	free_stack(&a);
	if (av_split != NULL)
		ft_free_args(av_split);
	return (0);
}
