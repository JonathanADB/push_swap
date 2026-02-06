/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:25:51 by jonadomi          #+#    #+#             */
/*   Updated: 2025/10/21 16:25:54 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (*s)
	{
		f(i, s);
		s++;
		i++;
	}
}

/* void apply_toupper(unsigned int i, char *c)
{
    (void)i;
    *c = ft_toupper(*c);
}

int main(void)
{
    char str[] = "hola mundo";

    printf("Original    : %s\n", str);
    ft_striteri(str, apply_toupper);
    printf("Transformada: %s\n", str); 

    return 0;
} */