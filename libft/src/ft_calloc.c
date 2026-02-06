/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:22:20 by jonadomi          #+#    #+#             */
/*   Updated: 2025/10/21 16:22:23 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		return (malloc(1));
	}
	total_size = nmemb * size;
	if (size != 0 && total_size / size != nmemb)
	{
		return (NULL);
	}
	ptr = malloc(total_size);
	if (!ptr)
	{
		return (NULL);
	}
	ft_memset(ptr, 0, total_size);
	return (ptr);
}

/* int main(void)
{
	int *arr;
	size_t n = 5;

	arr = (int *)ft_calloc(n, sizeof(int));
	if (!arr)
	{
		printf("Error reservando memoria\n");
		return 1;
	}
	for (size_t i = 0; i < n; i++)
	{
		printf("arr[%zu] = %d\n", i, arr[i]);
	}
	free(arr);
	return 0;
} */
