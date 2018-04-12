/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:46:38 by ireva             #+#    #+#             */
/*   Updated: 2016/12/22 16:23:11 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned const char	*a;

	a = arr;
	while (n > 0)
	{
		if (a[0] == (unsigned char)c)
			return ((char*)a);
		a++;
		n--;
	}
	return (NULL);
}
