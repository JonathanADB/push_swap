/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:03:38 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/02 20:58:15 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ps *ps)
{
	t_node	*node;

	if (!ps || ps->size_b == 0)
		return ;
	node = pop_top(&ps->b);
	push_top(&ps->a, node);
	ps->size_b--;
	ps->size_a++;
	ft_printf("pa\n");
}
