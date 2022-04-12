/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-pin <pdel-pin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:36:22 by pdel-pin          #+#    #+#             */
/*   Updated: 2022/04/12 14:59:37 by pdel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (c == '\0')
	{
		i = ft_strlen(s);
		return ((char *)&s[i]);
	}
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return ((char *) '\0');
}
