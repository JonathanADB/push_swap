/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:18:00 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/02 16:32:26 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

void	calculate_costs(t_ps *ps)
{
	t_node	*b;

	if (!ps || !ps->b)
		return ;
	b = ps->b;
	while (b)
	{
		b->cost_b = calc_cost(b->pos, ps->size_b);
		b->cost_a = calc_cost(b->target_pos, ps->size_a);
		b = b->next;
	}
}
