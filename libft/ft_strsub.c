/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:32:50 by ireva             #+#    #+#             */
/*   Updated: 2016/12/08 16:07:04 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*arr;

	i = 0;
	if (s)
	{
		arr = ft_strnew(len);
		if (arr == NULL)
			return (NULL);
		while (len != 0)
		{
			arr[i] = s[start];
			start++;
			len--;
			i++;
		}
		return (arr);
	}
	return (NULL);
}
