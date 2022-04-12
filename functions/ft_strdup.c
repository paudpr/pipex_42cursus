/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-pin <pdel-pin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:38:01 by pdel-pin          #+#    #+#             */
/*   Updated: 2022/04/12 14:54:48 by pdel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		i;

	cpy = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

/*
#include <stdio.h>
void pdel_pin()
{
	system("leaks -q a.out");
}

int main(int argc, char **argv)
{
	char *pepe;
	char *juan;

	pepe = "Mierda congelada";

	juan = ft_strdup(pepe);
	printf("probando a imprimir juan:    %s\n", juan);

	if (argc < 2)
		return(0);
	printf("probando a imprimir un argumento:    %s\n", argv[1]);
	atexit(pdel_pin);
	return(0);
		
}
*/