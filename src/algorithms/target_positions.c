/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_positions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:10:39 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/02 19:18:29 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_target_node(t_node *a, int b_nbr)
{
	t_node	*target;
	long	closest_bigger;

	target = NULL;
	closest_bigger = LONG_MAX;
	while (a)
	{
		if (a->nbr > b_nbr && a->nbr < closest_bigger)
		{
			closest_bigger = a->nbr;
			target = a;
		}
		a = a->next;
	}
	return (target);
}

void	set_target_positions(t_ps *ps)
{
	t_node	*b;
	t_node	*target;

	b = ps->b;
	while (b)
	{
		target = find_target_node(ps->a, b->nbr);
		if (!target)
			target = find_smallest(ps->a);
		b->target_node = target;
		b->target_pos = target->pos;
		b = b->next;
	}
}
