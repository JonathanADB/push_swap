/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:59:16 by jonadomi          #+#    #+#             */
/*   Updated: 2026/01/30 23:00:53 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_ps *ps)
{
	if (ps->a)
		free_stack(&ps->a);
	if (ps->b)
		free_stack(&ps->b);
	if (ps->args)
		free_split(ps->args);
}
