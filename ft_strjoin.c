/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahiz <kanahiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:25:21 by kanahiz           #+#    #+#             */
/*   Updated: 2025/11/04 02:11:29 by kanahiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_alo(const char *s, char *p)
{
	int	i;

	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	return (i);
}

static int	ft_alo2(const char *s, char *p, int i)
{
	int	j;

	j = 0;
	while (s[j])
	{
		p[i] = s[j];
		i++;
		j++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		i;

	if (s1 != NULL && s2 == NULL)
		return (ft_strdup(s1));
	if (s2 != NULL && s1 == NULL)
		return (ft_strdup(s2));
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	p = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return (NULL);
	i = ft_alo(s1, p);
	i = ft_alo2(s2, p, i);
	p[i] = '\0';
	return (p);
}
