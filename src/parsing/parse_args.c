/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 23:09:00 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/02 21:46:44 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parse_args(t_ps *ps, int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (NULL);
	if (argc == 2)
	{
		ps->args = ft_split(argv[1], ' ');
		if (!ps->args || !ps->args[0])
			error_exit(ps);
		return (ps->args);
	}
	ps->args = NULL;
	return (argv + 1);
}
