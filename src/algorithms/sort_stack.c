/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:54:41 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/09 19:00:58 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_all_but_three(t_ps *ps)
{
	int	median;
	int	size;
	int	pushed;

	size = ps->size_a;
	median = get_median(ps->a, size);
	pushed = 0;
	while (ps->size_a > 3 && pushed < size / 2)
	{
		if (ps->a->nbr < median)
		{
			pb(ps);
			pushed++;
		}
		else
			ra(ps);
	}
	while (ps->size_a > 3)
	{
		if (ps->a->nbr >= median && ps->a->next && ps->a->next->nbr < median)
			rra(ps);
		else
			pb(ps);
	}
}

static void	rotate_until_sorted(t_ps *ps)
{
	t_node	*smallest;

	update_positions(ps);
	smallest = find_smallest(ps->a);
	if (smallest->pos <= ps->size_a / 2)
		while (ps->a != smallest)
			ra(ps);
	else
		while (ps->a != smallest)
			rra(ps);
}

void	sort_stacks(t_ps *ps)
{
	push_all_but_three(ps);
	sort_three(ps);
	while (ps->b)
	{
		update_positions(ps);
		set_target_positions(ps);
		calculate_costs(ps);
		execute_cheapest(ps);
	}
	update_positions(ps);
	rotate_until_sorted(ps);
}
