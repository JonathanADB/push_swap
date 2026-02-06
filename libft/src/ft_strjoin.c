/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:26:01 by jonadomi          #+#    #+#             */
/*   Updated: 2025/10/21 16:26:04 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined_str = (char *)malloc(len1 + len2 + 1);
	if (!joined_str)
		return (NULL);
	ft_strlcpy(joined_str, s1, len1 + 1);
	ft_strlcpy(joined_str + len1, s2, len2 + 1);
	return (joined_str);
}

/* int main(void)
{
    const char *frase1 = "Hola ";
    const char *frase2 = "Mundo!";
    char *resultado = ft_strjoin(frase1, frase2);

    if (resultado)
    {
        printf("Resultado: %s\n", resultado);
        free(resultado);
    }
    else
    {
        printf("Error al unir las cadenas.\n");
    }
    return 0;
} */