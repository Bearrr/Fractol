/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:42:52 by ireva             #+#    #+#             */
/*   Updated: 2016/12/09 14:42:54 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memalloc(size_t size)
{
	int				i;
	void			*str;
	unsigned char	*s;

	i = 0;
	str = malloc(size);
	if (str == NULL)
		return (NULL);
	s = (unsigned char *)str;
	while (size != 0)
	{
		s[i] = 0;
		i++;
		size--;
	}
	return (void *)(s);
}
