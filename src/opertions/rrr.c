/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:05:24 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/09 16:08:40 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_one(t_node **stack, int size)
{
	t_node	*prev;
	t_node	*last;

	if (size < 2)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rrr(t_ps *ps)
{
	reverse_rotate_one(&ps->a, ps->size_a);
	reverse_rotate_one(&ps->b, ps->size_b);
	ft_printf("rrr\n");
}
