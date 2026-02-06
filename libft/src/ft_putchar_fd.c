/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:24:33 by jonadomi          #+#    #+#             */
/*   Updated: 2025/10/21 16:24:35 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* int main(void)
{
    ft_putchar_fd('H', 1);
    ft_putchar_fd('o', 1);
    ft_putchar_fd('l', 1);
    ft_putchar_fd('a', 1);
    ft_putchar_fd('\n', 1);
    return 0;
} */
