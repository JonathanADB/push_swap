/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:02:08 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/02 21:00:15 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps *ps)
{
	t_node	*first;
	t_node	*second;

	if (!ps || ps->size_a < 2)
		return ;
	first = ps->a;
	second = ps->a->next;
	first->next = second->next;
	second->next = first;
	ps->a = second;
	ft_printf("sa\n");
}
