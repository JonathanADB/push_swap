/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:04:18 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/09 16:13:35 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps *ps)
{
	t_node	*first;
	t_node	*last;

	if (!ps || ps->size_a < 2)
		return ;
	first = pop_top(&ps->a);
	last = ps->a;
	while (last->next)
		last = last->next;
	last->next = first;
	ft_printf("ra\n");
}
