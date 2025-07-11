/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:06:06 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/11 19:46:36 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_cmd_str.h"
#include <errno.h>

static void	file_not_found(char *str);
static void	permission_denied(char *file_name);

void	error(char *str)
{
	if (errno == ENOENT)
		file_not_found(str);
	else if (errno == EACCES)
		permission_denied(str);
	else if (errno == ENOMEM)
		ft_putstr_fd("pipex: Cannot allocate memory\n", 2);
	else if (errno == SYNTAX_ERROR1)
		ft_putstr_fd("pipex: unterminated quote or dangling \\\n", 2);
	exit(EXIT_FAILURE);
}

static void	permission_denied(char *file_name)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(file_name, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	exit(126);
}

static void	file_not_found(char *file_name)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(file_name, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	exit(127);
}
