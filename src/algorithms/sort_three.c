/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:41:03 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/03 21:48:34 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_ps *ps)
{
	int	a;
	int	b;
	int	c;

	a = ps->a->nbr;
	b = ps->a->next->nbr;
	c = ps->a->next->next->nbr;
	if (a > b && b < c && a < c)
		sa(ps);
	else if (a > b && b > c)
	{
		sa(ps);
		rra(ps);
	}
	else if (a > c && b < c)
		ra(ps);
	else if (a < b && a > c)
		rra(ps);
	else if (a < b && b > c && a < c)
	{
		sa(ps);
		ra(ps);
	}
}
