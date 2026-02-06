/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonadomi <jonadomi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:22:43 by jonadomi          #+#    #+#             */
/*   Updated: 2025/10/21 16:22:46 by jonadomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
/* 
int main() {
	char letra = 'a'; 

	if (ft_isalpha(letra))
		printf("'%c' es una letra.\n", letra);
	else
		printf("'%c' NO es una letra .\n", letra);

	return 0;
}  */