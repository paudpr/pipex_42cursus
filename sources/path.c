/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-pin <pdel-pin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:10:24 by pdel-pin          #+#    #+#             */
/*   Updated: 2022/04/18 13:10:25 by pdel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char	*find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
			return (env[i]);
		i++;
	}
	return (NULL);
}

char	*check_valid(char *path, char *argv)
{
	int		i;
	char	**path_div;
	char	*aux;
	char	*str_cmd;
	char	*cmd_path;

	path_div = ft_split(path, ':');
	cmd_path = NULL;
	i = 0;
	while (path_div[i])
	{
		aux = ft_strjoin(path_div[i], "/");
		str_cmd = ft_strjoin(aux, argv);
		if (access(str_cmd, F_OK) == 0)
			cmd_path = ft_strdup(aux);
		free(aux);
		free(str_cmd);
		i++;
	}
	ft_free_double(path_div);
	if (cmd_path == NULL)
		print_error(0);
	return (cmd_path);
}

char	**get_path(t_vals *vals, int argc, char **argv)
{
	int		i;
	int		j;
	char	*path;
	char	**cmd_path;
	char	**argv_split;

	path = find_path(vals->env);
	if (path == NULL)
		print_error(0);
	cmd_path = malloc(sizeof(char *) * (argc - 3 + 1));
	if (cmd_path == NULL)
		print_error(0);
	i = 2;
	j = 0;
	while (argv[i] && i > 1 && i < argc - 1)
	{
		argv_split = ft_split(argv[i], ' ');
		cmd_path[j] = check_valid(path, argv_split[0]);
		j++;
		i++;
		ft_free_double(argv_split);
	}
	cmd_path[j] = NULL;
	return (cmd_path);
}
