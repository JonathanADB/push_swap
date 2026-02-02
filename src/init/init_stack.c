/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:16:49 by jonadomi          #+#    #+#             */
/*   Updated: 2026/01/30 23:56:15 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_ps *ps, char **args)
{
	int		i;
	long	nbr;
	t_node	*node;

	i = 0;
	while (args[i])
	{
		if (error_syntax(args[i]))
			error_exit(ps);
		nbr = ft_atol(ps, args[i]);
		if (error_duplicate(ps->a, (int)nbr))
			error_exit(ps);
		node = new_node(ps, (int)nbr);
		stack_add_back(&ps->a, node);
		ps->size_a++;
		i++;
	}
}
