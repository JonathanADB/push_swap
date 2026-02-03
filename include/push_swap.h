/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:50:11 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/03 19:55:12 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

/* ========================= NODE STRUCTURE ========================= */
typedef struct s_node
{
	int				nbr;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	bool			above_median;
	struct s_node	*target_node;
	struct s_node	*next;
}	t_node;
/* ========================= MASTER STRUCTURE ========================= */
typedef struct s_ps
{
	t_node	*a;
	t_node	*b;
	int		size_a;
	int		size_b;
	char	**args;
}	t_ps;
/* ========================= PARSING ========================= */
char	**parse_args(t_ps *ps, int argc, char **argv);
int		error_syntax(char *str);
int		error_duplicate(t_node *a, int nbr);
long	ft_atol(t_ps *ps, char *str);

/* ========================= INIT ========================= */
void	init_stack_a(t_ps *ps, char **args);
t_node	*new_node(t_ps *ps, int nbr);
/* ========================= ERROR HANDLING ========================= */
void	error_exit(t_ps *ps);
void	free_all(t_ps *ps);
void	free_stack(t_node **stack);
/* ========================= STACK UTILS ========================= */
void	stack_add_back(t_node **stack, t_node *new);
int		stack_sorted(t_node *stack);
/* ========================= OPERATIONS ========================= */
void	sa(t_ps *ps);
void	sb(t_ps *ps);
void	ss(t_ps *ps);
void	pa(t_ps *ps);
void	pb(t_ps *ps);
void	ra(t_ps *ps);
void	rb(t_ps *ps);
void	rr(t_ps *ps);
void	rra(t_ps *ps);
void	rrb(t_ps *ps);
void	rrr(t_ps *ps);
t_node	*pop_top(t_node **stack);
void	push_top(t_node **stack, t_node *node);
/* ========================= ALGORITHM ========================= */
void	sort_if_needed(t_ps *ps);
void	sort_three(t_ps *ps);
void	sort_stacks(t_ps *ps);
void	update_positions(t_ps *ps);
void	set_target_positions(t_ps *ps);
void	calculate_costs(t_ps *ps);
void	execute_cheapest(t_ps *ps);
t_node	*find_smallest(t_node *stack);
t_node	*get_cheapest_node(t_ps *ps);
int		get_median(t_node *a, int size);
void	bubble_sort(int *arr, int size);

#endif
