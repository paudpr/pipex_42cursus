/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauladelpinoramirez <pauladelpinoramire    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:43:19 by pvillena          #+#    #+#             */
/*   Updated: 2022/03/26 00:19:08 by pauladelpin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (argv[i])
	{
		j = 0;
		flag = 0;
		while (argv[i][j])
		{
			if (argv[i][j++] == 39)
				flag++;
		}
		if (flag % 2 != 0)
		{
			write(2, "quote not close\n", 17);
			exit(1);
		}
		i++;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	char	***cmds;
	int		status;

	if (!envp || !*envp)
		exit(1);
	else if (argc < 5 || argc > 5)
		return (1);
	check_args(argv);
	cmds = get_cmd(argv, argc);
	status = pipex(argv[1], argv[argc - 1], cmds, envp);
	free_machine(cmds);
	return (status);
}