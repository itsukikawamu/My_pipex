/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 19:43:13 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/02 00:12:49 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	**split_path_env(char **ep);
static char	*join_dir_and_file_name(char *dir, char *name);

char	*get_cmd_path(char **cmd, char **ep)
{
	char	*path;
	char	**dir_arr;
	int		i;

	dir_arr = split_path_env(ep);
	i = 0;
	while (dir_arr[i])
	{
		path = join_dir_and_file_name(dir_arr[i], cmd[0]);
		if (!path)
			return (NULL);
		if (access(path, F_OK) == 0)
		{
			if (access(path, X_OK) != 0)
				permission_denied(cmd, path);
			return (path);
		}
		free(path);
		i++;
	}
	free_str_arr(dir_arr);
	cmd_not_found(cmd);
	return (NULL);
}

static char	*join_dir_and_file_name(char *dir, char *name)
{
	char	*path;
	char	*tmp;

	tmp = ft_strjoin(dir, "/");
	path = ft_strjoin(tmp, name);
	free(tmp);
	return (path);
}

static char	**split_path_env(char **ep)
{
	char	*path;

	path = ft_getenv(ep, "PATH");
	return (ft_split(path, ':'));
}

void	cmd_not_found(char **cmd)
{
	ft_putstr_fd(cmd[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	free_str_arr(cmd);
	exit(127);
}

void	permission_denied(char **cmd, char *name)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": permission denied\n", 2);
	free(name);
	free_str_arr(cmd);
	exit(126);
}
