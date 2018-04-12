/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:56:09 by ireva             #+#    #+#             */
/*   Updated: 2016/12/05 19:41:26 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		f;
	int		c;
	char	*arr;

	i = 0;
	f = 0;
	if (!s)
		return (NULL);
	c = ft_strlen(s) - 1;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
		i++;
	if (i - 1 == c)
	{
		arr = ft_strnew(0);
		return (arr);
	}
	while (s[c] == '\n' || s[c] == '\t' || s[c] == ' ')
		c--;
	f = c - i + 1;
	arr = ft_strnew(f);
	if (arr == NULL)
		return (NULL);
	arr = (char *)ft_strncpy(arr, &s[i], f);
	return (arr);
}
