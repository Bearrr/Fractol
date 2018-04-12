/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:46:20 by ireva             #+#    #+#             */
/*   Updated: 2016/12/22 16:22:48 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*a;
	unsigned const char	*b;
	int					i;

	a = dest;
	b = src;
	if (a < b)
		i = 1;
	else
	{
		i = -1;
		a = a + n - 1;
		b = b + n - 1;
	}
	while (n > 0)
	{
		*a = *b;
		a = a + i;
		b = b + i;
		n--;
	}
	return (dest);
}
