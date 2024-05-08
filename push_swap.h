/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:31:16 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/08 13:23:15 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"
# include <limits.h>
// # include <stdio.h>

typedef struct t_stack
{
	int					value;
	int					index;
	int					cost;
	bool				above_median;
	bool				cheapest;
	struct t_stack		*target;
	struct t_stack		*next;
}	t_s;

//Error handling
int					check_duplicates(t_s *s_a, int n);
int					error_syntax(char **av);
void				free_args_error(char **args);

//Memory
void				free_stack(t_s **stack);
void				error_free(t_s **s_a, char **av);
void				ft_free_args(char **args);

//Split arguments
char				**ft_split(char const *s, char c);

//Operations
void				push(t_s **src, t_s **dest);
void				pa(t_s **stack_a, t_s **stack_b);
void				pb(t_s **stack_a, t_s **stack_b);
void				swap(t_s **stack);
void				sa(t_s **s_a);
void				sb(t_s **s_b);
void				rotate(t_s **stack);
void				ra(t_s **s_a);
void				rb(t_s **s_b);
void				rr(t_s **s_a, t_s **s_b);
void				reverse_rotate(t_s **stack);
void				rra(t_s **s_a);
void				rrb(t_s **s_b);
void				rrr(t_s **s_a, t_s **s_b);

//Utils
int					stack_len(t_s *stack);
t_s					*traverse_stack(t_s *head);
t_s					*find_max_value(t_s *s_a);
t_s					*find_min_value(t_s *s_a);
void				sorting_stacks(t_s **s_a, t_s **s_b);
void				set_index(t_s *stack);
void				find_cheapest(t_s *stack);
t_s					*get_cheapest(t_s *stack);
long				ft_atol(const char *str);
void				initialize_stack(char **av, t_s **s_a);

//Algorithm
int					stack_sorted(t_s **stack);
int					tiny_sort(t_s **a);
void				sort_three(t_s **s_a);
int					check_sort_a(t_s **stack);
void				min_on_top(t_s **a);
void				move_a_to_b(t_s **a, t_s **b);
void				move_on_top(t_s **stack, t_s *top_node, char stack_name);
void				reverse_rotate_both(t_s **a, t_s **b, t_s *cheapest_node);
void				rotate_both(t_s **s_a, t_s **s_b, t_s *cheapest_node);

//From stack a to stack b
void				prep_nodes_a(t_s **s_a, t_s **s_b);
void				find_target_a(t_s *s_a, t_s *s_b);
void				find_cost_a(t_s *s_a, t_s *s_b);

//From stack b to stack a
void				prep_nodes_b(t_s *a, t_s *b);
void				find_target_b(t_s *s_a, t_s *s_b);
void				move_b_to_a(t_s **a, t_s **b);
#endif
