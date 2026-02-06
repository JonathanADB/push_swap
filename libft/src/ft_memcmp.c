/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:23:43 by jonadomi          #+#    #+#             */
/*   Updated: 2025/10/21 16:23:46 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}
/* 
int main() {
    char a[] = "Hala";
    char b[] = "Halo";

    int r = ft_memcmp(a, b, 4);

    if (r == 0)
        printf("Son iguales\n");
    else if (r < 0)
        printf("a es menor que b\n");
    else
        printf("a es mayor que b\n");

    return 0;
}
 */