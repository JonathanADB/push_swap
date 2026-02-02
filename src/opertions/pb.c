/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:03:55 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/02 20:58:33 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_ps *ps)
{
	t_node	*node;

	if (!ps || ps->size_a == 0)
		return ;
	node = pop_top(&ps->a);
	push_top(&ps->b, node);
	ps->size_a--;
	ps->size_b++;
	ft_printf("pb\n");
}
