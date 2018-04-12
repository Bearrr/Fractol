/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordslen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:11:45 by ireva             #+#    #+#             */
/*   Updated: 2016/12/08 14:20:41 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_wordslen(const char *s, char c)
{
	char		*arr;
	int			i2;
	int			i;

	i = 0;
	i2 = 0;
	if (!s && !c)
		return (NULL);
	while (s[i2] != c && s[i2])
		i2++;
	arr = (char *)malloc(sizeof(char) * (i2 + 1));
	return (arr);
}
