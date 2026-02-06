/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:22:51 by jonadomi          #+#    #+#             */
/*   Updated: 2025/10/21 16:22:55 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/* 
int main(void)
{
    char ch1 = 'A';
    char ch2 = 200;

    if (ft_isascii(ch1))
        printf("'%c' es ASCII\n", ch1);
    else
        printf("'%c' NO es ASCII\n", ch1);

    if (ft_isascii(ch2))
        printf("'%c' es ASCII\n", ch2);
    else
        printf("'%c' NO es ASCII\n", ch2);

    return 0;
} */