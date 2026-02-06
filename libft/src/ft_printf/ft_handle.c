/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:13:17 by jonadomi          #+#    #+#             */
/*   Updated: 2025/12/02 16:15:42 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle(char specifier, va_list args)
{
	int	total;

	total = 0;
	if (specifier == 'c')
		total += ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		total += ft_putstrt(va_arg(args, char const *));
	else if (specifier == 'p')
		total += ft_putptr(va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		total += ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		total += ft_putunbr(va_arg(args, unsigned int));
	else if (specifier == 'x')
		total += ft_puthex_ulong((unsigned long)va_arg(args, unsigned int), 0);
	else if (specifier == 'X')
		total += ft_puthex_ulong((unsigned long)va_arg(args, unsigned int), 1);
	else if (specifier == '%')
		total += ft_putchar('%');
	else
	{
		total += ft_putchar('%');
		total += ft_putchar(specifier);
	}
	return (total);
}
