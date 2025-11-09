/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahiz <kanahiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:26:33 by kanahiz           #+#    #+#             */
/*   Updated: 2025/11/06 03:17:45 by kanahiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lennbr(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_fil(long n)
{
	int		len;
	long	m;
	char	*res;

	m = n;
	len = ft_lennbr(m);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (m < 0)
	{
		res[0] = '-';
		m = -m;
	}
	else if (m == 0)
		res[0] = '0';
	while (m != 0)
	{
		res[--len] = (m % 10) + '0';
		m = m / 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	long	m;
	char	*p;

	if (n == 0)
		return (ft_strdup("0"));
	m = n;
	p = ft_fil(m);
	if (!p)
		return (NULL);
	return (p);
}
