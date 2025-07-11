/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:06:06 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/11 22:57:19 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_cmd_str.h"
#include <errno.h>
#include <string.h>

void	error(char *str)
{
	int	err;

	err = errno;
	ft_putstr_fd("pipex: ", 2);
	if (err == SYNTAX_ERROR1)
		ft_putstr_fd("unterminated quote or dangling \\\n", 2);
	else
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
		if (err < 1000)
			ft_putendl_fd(strerror(err), 2);
		else if (err == CMD_NOT_FOUND)
			ft_putstr_fd("command not found\n", 2);
		else if (err == PERM_DENIED)
			ft_putstr_fd("permission denied\n", 2);
	}
	if (err == EACCES || err == ENOEXEC || err == EPERM)
		exit(126);
	if (err == ENOENT || err == ENOTDIR)
		exit(127);
	exit(EXIT_FAILURE);
}

