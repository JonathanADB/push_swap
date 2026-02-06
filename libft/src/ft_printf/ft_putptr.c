/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:20:46 by jonadomi          #+#    #+#             */
/*   Updated: 2025/12/02 16:24:16 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	addr;
	int				count;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	count = 0;
	addr = (unsigned long)ptr;
	count += ft_putstrt("0x");
	count += ft_puthex_ulong(addr, 0);
	return (count);
}
