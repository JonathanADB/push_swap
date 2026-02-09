/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:58:38 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/09 18:57:46 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_ps *ps)
{
	if (ps->a)
		free_stack(&ps->a);
	if (ps->b)
		free_stack(&ps->b);
	if (ps->args)
		free_split(ps->args);
	write(2, "Error\n", 6);
	exit(1);
}
