/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_if_needed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:08:12 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/02 15:08:55 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_if_needed(t_ps *ps)
{
	if (stack_sorted(ps->a))
		return ;
	if (ps->size_a == 2)
		sa(ps);
	else if (ps->size_a == 3)
		sort_three(ps);
	else
		sort_stacks(ps);
}
