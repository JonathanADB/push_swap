/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:03:15 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/09 15:57:37 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_ps *ps)
{
	t_node	*first_a;
	t_node	*second_a;
	t_node	*first_b;
	t_node	*second_b;

	if (ps->size_a > 1)
	{
		first_a = ps->a;
		second_a = ps->a->next;
		first_a->next = second_a->next;
		second_a->next = first_a;
		ps->a = second_a;
	}
	if (ps->size_b > 1)
	{
		first_b = ps->b;
		second_b = ps->b->next;
		first_b->next = second_b->next;
		second_b->next = first_b;
		ps->b = second_b;
	}
	ft_printf("ss\n");
}
