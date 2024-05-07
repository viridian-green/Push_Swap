// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/02/27 14:27:54 by ademarti          #+#    #+#             */
// /*   Updated: 2024/03/11 13:54:41 by ademarti         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	s_stack	*a;
	s_stack	*b;
	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
	}
	initialize_stack(av + 1, &a);
	if (stack_sorted(&a))
		return (0);
	sorting_stacks(&a, &b);
	free_stack(&a);
	return (0);
}
