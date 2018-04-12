/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:20:40 by ireva             #+#    #+#             */
/*   Updated: 2016/12/06 11:57:27 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*arr;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	j = ft_strlen(s1);
	arr = (char *)malloc(sizeof(char) * (j + ft_strlen(s2) + 1));
	if (arr == NULL)
		return (NULL);
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		arr[j] = s2[i];
		i++;
		j++;
	}
	arr[j] = '\0';
	return (arr);
}
