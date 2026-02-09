/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:04:32 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/09 16:14:59 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_ps *ps)
{
	t_node	*first;
	t_node	*last;

	if (!ps || ps->size_b < 2)
		return ;
	first = ps->b;
	ps->b = ps->b->next;
	first->next = NULL;
	last = ps->b;
	while (last->next)
		last = last->next;
	last->next = first;
	ft_printf("rb\n");
}
