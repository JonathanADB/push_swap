/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:27:07 by jonadomi          #+#    #+#             */
/*   Updated: 2025/10/21 16:27:10 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	str = NULL;
	if (s1 != NULL && set != NULL)
	{
		start = 0;
		end = ft_strlen(s1);
		while (s1[start] && ft_strchr(set, s1[start]))
			start++;
		while (end > start && ft_strchr(set, s1[end - 1]))
			end--;
		str = (char *)malloc(end - start + 1);
		if (str)
			ft_strlcpy(str, s1 + start, end - start + 1);
		return (str);
	}
	return (NULL);
}

/* int main(void)
{
    char *s = "+++Hola Bilbao***";
    char *set = "+*";
    char *resultado = ft_strtrim(s, set);
    printf("Resultado: %s\n", resultado);
    free(resultado);
    return 0;
}
 */