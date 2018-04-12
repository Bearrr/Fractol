/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:47:36 by ireva             #+#    #+#             */
/*   Updated: 2016/12/22 16:26:06 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = (char*)malloc(ft_strlen(s) + 1);
	if (str)
	{
		while (s[i])
		{
			str[i] = s[i];
			i++;
		}
		str[i] = s[i];
	}
	return (str);
}
