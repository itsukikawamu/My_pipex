/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:06:06 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/06 17:03:09 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_cmd_str.h"
#include <errno.h>

void	error(char *str)
{
	if (errno == SYNTAX_ERROR1)
		ft_putstr_fd("pipex: unterminated quote or dangling \\\n", 2);
	else if(errno == ENOENT)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(127);
	}
	else if (errno == EACCES)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		exit(126);		
	}
	else if(errno == ENOMEM)
		ft_putstr_fd("pipex: Cannot allocate memory\n", 2);
	exit(1);
}