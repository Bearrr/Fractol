/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:30:35 by ireva             #+#    #+#             */
/*   Updated: 2016/12/08 15:33:10 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*arr;

	i = 0;
	if (s)
	{
		arr = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (arr == NULL)
			return (NULL);
		while (s[i])
		{
			arr[i] = f(s[i]);
			i++;
		}
		arr[i] = '\0';
		return (arr);
	}
	return (0);
}
