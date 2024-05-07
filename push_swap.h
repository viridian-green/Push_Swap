/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:31:16 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/07 16:29:31 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft/libft.h"
# include <limits.h>
#include <stdio.h>

typedef struct t_stack
{
	int value;
	int index;
	int cost;
	bool above_median;
	bool cheapest;
	struct t_stack *target;
	struct t_stack *next;
} s_stack;

//Error handling
int	check_duplicates(s_stack *s_a, int n);
int error_syntax(char **av);
void ft_free_args_2(char **args);

//Memory
void free_stack(s_stack **stack);
void error_free(s_stack **s_a, char **av);
void    ft_free_args(char **args);

//Split arguments
char	**ft_split(char const *s, char c);

//Operations
void push(s_stack **src, s_stack **dest);
void	pa(s_stack **stack_a, s_stack **stack_b);
void	pb(s_stack **stack_a, s_stack **stack_b);
void swap(s_stack **stack);
void sa(s_stack **s_a);
void	sb(s_stack **s_b);
void	rotate(s_stack **stack);
void	ra(s_stack **s_a);
void	rb(s_stack **s_b);
void	rr(s_stack **s_a, s_stack **s_b);
void	reverse_rotate(s_stack **stack);
void	rra(s_stack **s_a);
void	rrb(s_stack **s_b);
void	rrr(s_stack **s_a, s_stack **s_b);

//Utils
int	stack_len(s_stack *stack);
s_stack	*traverse_stack(s_stack *head);
s_stack *find_max_value(s_stack *s_a);
s_stack *find_min_value(s_stack *s_a);
void sorting_stacks(s_stack **s_a, s_stack **s_b);
void set_index(s_stack *stack);
void find_cheapest(s_stack *stack);
s_stack *get_cheapest(s_stack *stack);
long	ft_atol(const char *str);
void	initialize_stack(char **av, s_stack **s_a);

//Algorithm
int	stack_sorted(s_stack **stack);
int tiny_sort(s_stack **a);
void sort_three(s_stack **s_a);
int	check_sort_a(s_stack **stack);
void min_on_top(s_stack **a);
void	move_a_to_b(s_stack **a, s_stack **b);
void	move_on_top(s_stack **stack, s_stack *top_node, char stack_name);
void reverse_rotate_both(s_stack **s_a, s_stack **s_b, s_stack *cheapest_node);
void rotate_both(s_stack **s_a, s_stack **s_b, s_stack *cheapest_node);

//From stack a to stack b
void prep_nodes_a(s_stack **s_a, s_stack **s_b);
void find_target_a(s_stack *s_a, s_stack *s_b);
void find_cost_a(s_stack *s_a, s_stack *s_b);

//From stack b to stack a
void prep_nodes_b(s_stack *a, s_stack *b);
void find_target_b(s_stack *s_a, s_stack *s_b);
void	move_b_to_a(s_stack **a, s_stack **b);
#endif
