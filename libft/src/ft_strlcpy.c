/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:26:20 by jonadomi          #+#    #+#             */
/*   Updated: 2025/10/21 16:26:22 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

/* 
int main() {
    char destino[5];
    const char *fuente = "Hola mundo";

    size_t len = ft_strlcpy(destino, fuente, sizeof(destino));

    printf("Destino: %s\n", destino);       // Imprime: Hola
    printf("Longitud fuente: %zu\n", len);  // Imprime: 10

    return 0;
}
 */
