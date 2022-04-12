/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-pin <pdel-pin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:17:08 by pdel-pin          #+#    #+#             */
/*   Updated: 2022/04/12 14:54:48 by pdel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

static size_t	ft_count_strings(const char *s, char c)
{
	int		new_str;
	size_t	str_n;
	size_t	i;

	new_str = 0;
	str_n = 0;
	 i = 0;
	while (s[i])
	{
		if (s[i] != c && new_str == 0)
		{
			new_str = 1;
			str_n++;
		}
		else if (s[i] == c)
			new_str = 0;
		i++;
	}
	return (str_n);
}

static size_t	ft_count_chrs(const char *s, char c)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[i] && s[i++] != c)
		len++;
	return (len);
}

static void	ft_free_tab(char **tab, size_t n)
{
	if (!tab[n])
	{
		while (n > 0)
			free(tab[n--]);
		free(tab);
	}
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	str_n;
	size_t	n;
	size_t	len;

	if (!s)
		return (0);
	str_n = ft_count_strings(s, c);
	split = malloc(sizeof(char *) * (str_n + 1));
	if (split == NULL)
		return (split);
	n = 0;
	while (n < str_n)
	{
		while (*s == c)
			s++;
		len = ft_count_chrs(s, c);
		split[n] = malloc(sizeof(char) * (len + 1));
		ft_free_tab(split, n);
		ft_strlcpy(split[n], s, len + 1);
		s = s + len;
		n++;
	}
	split[str_n] = 0;
	return (split);
}
