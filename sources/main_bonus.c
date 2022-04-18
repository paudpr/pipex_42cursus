/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-pin <pdel-pin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:10:15 by pdel-pin          #+#    #+#             */
/*   Updated: 2022/04/18 13:10:17 by pdel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int argc, char **argv, char **environ)
{
	t_vals		vals;
	char		*infile;

	if (!environ)
		print_error(0);
	if (argc < 5)
		print_error(0);
	infile = NULL;
	vals.num = 0;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		heredoc(argv);
		vals.num = 1;
		infile = "/tmp/file";
	}
	if (infile == NULL)
		infile = argv[1];
	init_vals(&vals, environ, argc, argv);
	pipex(infile, argv[argc - 1], &vals);
	return (0);
}
