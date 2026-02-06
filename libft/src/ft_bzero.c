/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:22:07 by jonadomi          #+#    #+#             */
/*   Updated: 2025/10/21 16:22:10 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
	{
		*p++ = 0;
	}
}

/* int main() {
    char buffer[10] = "Hola";

    bzero(buffer, sizeof(buffer));

    int i = 0;
    while (i < 10)
    {
        printf("%d ", buffer[i]);
        i++;
    }

    return 0;
} */