/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:26:10 by jonadomi          #+#    #+#             */
/*   Updated: 2025/10/21 16:26:13 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	while (dst_len < size && dst[dst_len] != '\0')
	{
		dst_len++;
	}
	src_len = ft_strlen(src);
	if (dst_len == size)
	{
		return (size + src_len);
	}
	i = 0;
	while ((dst_len + i + 1) < size && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len + i < size)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/* int main() {
    char buffer[10] = "Hola";
    size_t resultado = ft_strlcat(buffer, " mundo", sizeof(buffer));

    printf("Resultado: %s\n", buffer);        
    printf("Longitud teórica: %zu\n", resultado); 
    return 0;
}
  */