/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ireva <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:10:33 by ireva             #+#    #+#             */
/*   Updated: 2016/12/09 13:39:36 by ireva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int b)
{
	int		c;

	c = 1;
	if (b < 0)
		c++;
	if (b == -2147483648)
		return (11);
	if (b == 0)
		return (1);
	while (b >= 10 || b <= -10)
	{
		b = b / 10;
		c++;
	}
	return (c);
}

char		*ft_itoa(int n)
{
	int		f;
	char	*mass;
	int		a;

	a = 0;
	f = len(n);
	mass = ft_strnew(f);
	if (mass == NULL)
		return (NULL);
	if (n < 0)
		mass[0] = '-';
	if (n == 0)
		mass[f - 1] = n + '0';
	while (n != 0)
	{
		a = n % 10;
		if (a < 0)
			a = -a;
		n = n / 10;
		mass[f - 1] = a + '0';
		f--;
	}
	if (n < 10 && n > 0)
		mass[0] = n + '0';
	return (mass);
}
