/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:45:56 by ireva             #+#    #+#             */
/*   Updated: 2016/12/22 16:22:24 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*a;
	unsigned const char	*b;

	a = dest;
	b = src;
	while (n > 0)
	{
		*a = *b;
		if (a[0] == (unsigned char)c)
		{
			a++;
			return (a);
		}
		a++;
		b++;
		n--;
	}
	return (0);
}
