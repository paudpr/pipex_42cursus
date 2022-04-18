/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-pin <pdel-pin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:10:18 by pdel-pin          #+#    #+#             */
/*   Updated: 2022/04/18 13:10:20 by pdel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int argc, char **argv, char **environ)
{
	t_vals		vals;

	if (!environ)
		print_error(0);
	if (argc != 5)
		print_error(0);
	init_vals(&vals, environ, argc, argv);
	pipex(argv[1], argv[argc - 1], &vals);
	return (0);
}
