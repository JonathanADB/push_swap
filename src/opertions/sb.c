/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:02:20 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/02 21:00:27 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_ps *ps)
{
	t_node	*first;
	t_node	*second;

	if (!ps || ps->size_b < 2)
		return ;
	first = ps->b;
	second = ps->b->next;
	first->next = second->next;
	second->next = first;
	ps->b = second;
	ft_printf("sb\n");
}
