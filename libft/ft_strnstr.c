/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:49:15 by ireva             #+#    #+#             */
/*   Updated: 2016/12/22 16:24:17 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack && len > 0)
	{
		if (*haystack == *needle)
			if (len >= ft_strlen(needle))
				if (!ft_strncmp(haystack, needle, ft_strlen(needle)))
					return ((char*)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
