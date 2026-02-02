/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:05:02 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/02 20:59:45 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_ps *ps)
{
	t_node	*prev;
	t_node	*last;

	if (!ps || ps->size_a < 2)
		return ;
	prev = NULL;
	last = ps->a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = ps->a;
	ps->a = last;
	ft_printf("rra\n");
}
