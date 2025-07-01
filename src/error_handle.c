/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 08:58:06 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/02 00:09:05 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include "utils.h"

void	failed()
{
	
	exit(EXIT_FAILURE);
}

void	dup_failed(int fd)
{
	perror("dup2");
	close(fd);
	exit(EXIT_FAILURE);
}

void	open_failed(char *file_name)
{
	char *str;

	str = strerror(errno);
	ft_putstr_fd("pipex: ",2);
	ft_putstr_fd(file_name, 2);
	ft_putstr_fd(": ",2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	malloc_failed(char **cmd, char *path)
{
	perror("malloc");
	free_str_arr(cmd);
	free(path);
	exit(EXIT_FAILURE);
}

void	exec_failed(char **cmd, char *path)
{
	perror("execve");
	free_str_arr(cmd);
	free(path);
	exit(EXIT_FAILURE);
}
