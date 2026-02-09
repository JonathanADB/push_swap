/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:04:42 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/09 16:07:19 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_one(t_node **stack, int size)
{
	t_node	*first;
	t_node	*last;

	if (size < 2)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	rr(t_ps *ps)
{
	rotate_one(&ps->a, ps->size_a);
	rotate_one(&ps->b, ps->size_b);
	ft_printf("rr\n");
}
