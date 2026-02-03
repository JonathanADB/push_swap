/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:54:25 by jonadomi          #+#    #+#             */
/*   Updated: 2026/02/03 19:58:49 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *arr, int size)
{
	int	x;
	int	y;
	int	tmp;

	x = 0;
	while (x < size - 1)
	{
		y = 0;
		while (y < size - x - 1)
		{
			if (arr[y] > arr[y + 1])
			{
				tmp = arr[y];
				arr[y] = arr[y + 1];
				arr[y + 1] = tmp;
			}
			y++;
		}
		x++;
	}
}

int	get_median(t_node *a, int size)
{
	int		*arr;
	t_node	*tmp;
	int		i;
	int		median;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	tmp = a;
	i = 0;
	while (tmp)
	{
		arr[i] = tmp->nbr;
		tmp = tmp->next;
		i++;
	}
	bubble_sort(arr, size);
	median = arr[size / 2];
	free(arr);
	return (median);
}
