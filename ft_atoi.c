/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahiz <kanahiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:08:34 by kanahiz           #+#    #+#             */
/*   Updated: 2025/11/05 14:41:06 by kanahiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int				sign;
	unsigned long	res;

	res = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr++ == '-')
			sign = -1;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (sign == 1 && (res > LONG_MAX / 10
				|| (res == LONG_MAX / 10 && *nptr - '0' > 7)))
			return (-1);
		if (sign == -1 && (res > LONG_MAX / 10
				|| (res == LONG_MAX / 10 && *nptr - '0' > 8)))
			return (0);
		res = res * 10 + (*nptr++ - '0');
	}
	return (res * sign);
}
