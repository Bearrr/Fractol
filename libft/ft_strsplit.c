/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:09:04 by ireva             #+#    #+#             */
/*   Updated: 2016/12/07 17:37:43 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		words(const char *s1, char c1)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (s1[i] == c1 && s1[i])
		i++;
	while (s1[i])
	{
		while (s1[i] != c1 && s1[i])
			i++;
		j++;
		while (s1[i] == c1 && s1[i])
			i++;
	}
	return (j);
}

static char		*words_len(const char *s2, char c2)
{
	char		*arr;
	int			i2;
	int			i;

	i = 0;
	i2 = 0;
	while (s2[i2] != c2 && s2[i2])
		i2++;
	arr = (char *)malloc(sizeof(char) * (i2 + 1));
	return (arr);
}

static char		**copy(char **mass, const char *s, char c, int f)
{
	int			l;
	int			i;
	int			k;

	i = 0;
	l = 0;
	k = 0;
	while (f)
	{
		if (s[i] != c && s[i])
		{
			mass[l] = words_len(&s[i], c);
			while (s[i] != c && s[i])
				mass[l][k++] = s[i++];
			mass[l++][k] = '\0';
			k = 0;
			f--;
		}
		i++;
	}
	mass[l] = 0;
	return (mass);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**mass;
	int			f;

	if (!s)
		return (NULL);
	f = words(s, c);
	mass = (char **)malloc(sizeof(char*) * (f + 1));
	if (mass == NULL)
		return (NULL);
	return (copy(mass, s, c, f));
}
