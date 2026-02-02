/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 23:09:00 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/02 21:30:56 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parse_args(t_ps *ps, int argc, char **argv)
{
	char	**args;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (NULL);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || !args[0])
			error_exit(ps);
		return (ps->args);
	}
	ps->args = NULL;
	return (argv + 1);
}
