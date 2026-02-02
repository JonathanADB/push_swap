/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:20:51 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/02 17:35:12 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	abs_val(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	total_cost(t_node *node)
{
	int	cost_a;
	int	cost_b;

	cost_a = abs_val(node->cost_a);
	cost_b = abs_val(node->cost_b);
	return (cost_a + cost_b);
}

t_node	*get_cheapest_node(t_ps *ps)
{
	t_node	*iter;
	t_node	*cheapest;
	int		best_cost;
	int		current_cost;

	if (!ps || !ps->b)
		return (NULL);
	iter = ps->b;
	cheapest = iter;
	best_cost = total_cost(iter);
	iter = iter->next;
	while (iter)
	{
		current_cost = total_cost(iter);
		if (current_cost < best_cost)
		{
			best_cost = current_cost;
			cheapest = iter;
		}
		iter = iter->next;
	}
	return (cheapest);
}
