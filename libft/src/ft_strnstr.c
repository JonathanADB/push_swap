/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:26:55 by jonadomi          #+#    #+#             */
/*   Updated: 2025/10/21 16:26:57 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_len;
	size_t	i;

	if (!*little)
		return ((char *)big);
	l_len = ft_strlen(little);
	if (l_len > len)
		return (NULL);
	i = 0;
	while (i + l_len <= len && big[i])
	{
		if (ft_strncmp(&big[i], little, l_len) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

/* int main() {
    const char *texto = "Hola mundo cruel";
    const char *buscar = "mundo";
    char *resultado = ft_strnstr(texto, buscar, 15);

    if (resultado)
        printf("Encontrado: %s\n", resultado);
    else
        printf("No encontrado\n");

    return 0;
}
 */