/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahiz <kanahiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:12:17 by kanahiz           #+#    #+#             */
/*   Updated: 2025/11/06 02:21:58 by kanahiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	all;
	void	*p;

	all = nmemb * size;
	if (nmemb != 0 && all / nmemb != size)
		return (NULL);
	p = (void *)malloc(all);
	if (!p)
		return (NULL);
	return (ft_memset(p, 0, all));
}
