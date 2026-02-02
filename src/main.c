/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:04:17 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/02 21:48:16 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;
	char	**args;

	if (argc < 2)
		return (0);
	ft_memset(&ps, 0, sizeof(t_ps));
	args = parse_args(&ps, argc, argv);
	if (!args)
		return (0);
	init_stack_a(&ps, args);
	sort_if_needed(&ps);
	free_all(&ps);
	return (0);
}
