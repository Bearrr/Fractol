/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:48:43 by ireva             #+#    #+#             */
/*   Updated: 2016/12/22 16:24:38 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int max;

	i = 0;
	max = -1;
	if ((char)c == '\0')
		return ((char*)(s + ft_strlen(s)));
	while (s[i])
	{
		if (s[i] == (char)c)
			max = i;
		i++;
	}
	if (max >= 0)
		return ((char*)(&s[max]));
	return (NULL);
}
