/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:03:14 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/02 16:29:55 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_positions(t_node *stack)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		stack->pos = pos;
		pos++;
		stack = stack->next;
	}
}

static void	assign_above_median(t_node *stack, int size)
{
	int	median;

	median = size / 2;
	while (stack)
	{
		stack->above_median = (stack->pos <= median);
		stack = stack->next;
	}
}

void	update_positions(t_ps *ps)
{
	assign_positions(ps->a);
	assign_positions(ps->b);
	assign_above_median(ps->a, ps->size_a);
	assign_above_median(ps->b, ps->size_b);
}
