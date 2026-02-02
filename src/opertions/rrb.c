/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:05:15 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/02 20:59:55 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_ps *ps)
{
	t_node	*prev;
	t_node	*last;

	if (!ps || ps->size_b < 2)
		return ;
	prev = NULL;
	last = ps->b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = ps->b;
	ps->b = last;
	ft_printf("rrb\n");
}
