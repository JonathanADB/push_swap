/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 00:08:58 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/02 18:13:31 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(t_ps *ps, int nbr)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		error_exit(ps);
	node->nbr = nbr;
	node->pos = -1;
	node->target_pos = -1;
	node->cost_a = 0;
	node->cost_b = 0;
	node->above_median = false;
	node->target_node = NULL;
	node->next = NULL;
	return (node);
}
