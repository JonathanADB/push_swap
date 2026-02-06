/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:26:37 by jonadomi          #+#    #+#             */
/*   Updated: 2025/10/21 16:26:40 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;
	size_t			len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/* 

char toupper_adapter(unsigned int i, char c)
{
    (void)i;
    return (char)ft_toupper((int)c); // o funcion x
}

int main(void)
{
    const char *original = "hola mundo";
    char *transformada = ft_strmapi(original, toupper_adapter);

    if (transformada)
    {
        printf("Original    : %s\n", original);
        printf("Transformada: %s\n", transformada);
        free(transformada);
    }
    else
    {
        printf("Error: malloc falló\n");
    }

    return 0;
} */