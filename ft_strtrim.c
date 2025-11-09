/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahiz <kanahiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:49:21 by kanahiz           #+#    #+#             */
/*   Updated: 2025/11/06 03:05:59 by kanahiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(const char *s, const char *set)
{
	int	count;
	int	j;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (set[j])
		{
			if (s[i] == set[j])
			{
				count++;
				break ;
			}
			j++;
		}
		if (set[j] == '\0')
			return (count);
		i++;
	}
	return (count);
}

static int	ft_checkend(const char *s, const char *set)
{
	int	count;
	int	j;
	int	i;

	count = 0;
	if (ft_strlen(s) == 0)
		return (0);
	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		j = 0;
		while (set[j])
		{
			if (s[i] == set[j])
			{
				count++;
				break ;
			}
			j++;
		}
		if (set[j] == '\0')
			return (count);
		i--;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	int		len;
	char	*p;

	if (!s1 || !set)
		return (NULL);
	start = ft_check(s1, set);
	end = ft_strlen(s1) - ft_checkend(s1, set);
	if (end <= start)
		return (ft_strdup(""));
	i = 0;
	len = end - start;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (start < end)
	{
		p[i] = s1[start];
		start++;
		i++;
	}
	p[i] = '\0';
	return (p);
}
