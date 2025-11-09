/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahiz <kanahiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:42:12 by kanahiz           #+#    #+#             */
/*   Updated: 2025/11/06 03:17:06 by kanahiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		count++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static void	ft_free_all(char **strall, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strall[i]);
		i++;
	}
	free (strall);
}

static char	*ft_fil(char const *s, char c, int *index)
{
	int		i;
	char	*out;
	int		j;

	i = (*index);
	j = 0;
	while (s[i] == c)
	{
		i++;
		(*index)++;
	}
	while (s[i] != c && s[i])
		i++;
	out = malloc(i - (*index) + 1);
	if (!out)
		return (NULL);
	while ((*index) < i)
	{
		out[j] = s[(*index)];
		(*index)++;
		j++;
	}
	out[j] = '\0';
	return (out);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	int		i;
	int		len;
	char	**strall;

	index = 0;
	i = 0;
	if (!s)
		return (NULL);
	len = ft_count_words(s, c);
	strall = malloc(sizeof(char *) * (len + 1));
	if (!strall)
		return (NULL);
	while (i < len)
	{
		strall[i] = ft_fil(s, c, &index);
		if (strall[i] == NULL)
		{
			ft_free_all(strall, i);
			return (NULL);
		}
		i++;
	}
	strall[i] = NULL;
	return (strall);
}
