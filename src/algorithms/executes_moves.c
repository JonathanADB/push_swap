/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executes_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:25:08 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/02 17:50:49 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both_positive(t_ps *ps, int *ca, int *cb)
{
	while (*ca > 0 && *cb > 0)
	{
		rr(ps);
		(*ca)--;
		(*cb)--;
	}
}

static void	rotate_both_negative(t_ps *ps, int *ca, int *cb)
{
	while (*ca < 0 && *cb < 0)
	{
		rrr(ps);
		(*ca)++;
		(*cb)++;
	}
}

static void	rotate_single(
	t_ps *ps,
	int *cost,
	void (*rot)(t_ps *),
	void (*rev)(t_ps *)
)
{
	while (*cost > 0)
	{
		rot(ps);
		(*cost)--;
	}
	while (*cost < 0)
	{
		rev(ps);
		(*cost)++;
	}
}

void	execute_cheapest(t_ps *ps)
{
	t_node	*cheapest;
	int		cost_a;
	int		cost_b;

	if (!ps || !ps->b)
		return ;
	cheapest = get_cheapest_node(ps);
	if (!cheapest)
		return ;
	cost_a = cheapest->cost_a;
	cost_b = cheapest->cost_b;
	rotate_both_positive(ps, &cost_a, &cost_b);
	rotate_both_negative(ps, &cost_a, &cost_b);
	rotate_single(ps, &cost_a, ra, rra);
	rotate_single(ps, &cost_b, rb, rrb);
	pa(ps);
}
