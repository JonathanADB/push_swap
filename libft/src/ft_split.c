/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:25:16 by jonadomi          #+#    #+#             */
/*   Updated: 2026/01/30 20:40:45 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**count_and_alloc(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (ft_calloc(count + 1, sizeof(char *)));
}

static int	fill_split(char const *s, char c, char **result)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		if (len > 0)
		{
			result[i] = ft_substr(s, 0, len);
			if (!result[i])
				return (-1);
			s += len;
			i++;
		}
	}
	return (0);
}

void	free_split(char **result)
{
	size_t	i;

	i = 0;
	if (!result)
		return ;
	while (result[i])
		free(result[i++]);
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = count_and_alloc(s, c);
	if (!result)
		return (NULL);
	if (fill_split(s, c, result) == -1)
	{
		free_split(result);
		return (NULL);
	}
	return (result);
}

/* int main(void)
{
    char **result;
    size_t i;

    // Ejemplo de cadena y delimitador
    const char *str = "  Hola,,mundo,esto,es,una,prueba  ";
    char delimiter = ',';

    result = ft_split(str, delimiter);
    if (!result)
    {
        printf("Error: ft_split devolvió NULL\n");
        return 1;
    }

    printf("Resultado de split:\n");
    for (i = 0; result[i] != NULL; i++)
    {
        printf("Palabra %zu: '%s'\n", i, result[i]);
        free(result[i]);  // Liberamos cada palabra
    }
    free(result);  // Liberamos el array de punteros

    return 0;
} */