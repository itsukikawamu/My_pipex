/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:39:44 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/01 23:58:52 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define _GNU_SOURCE
# include <unistd.h>
# include "libft.h"

// utils.c
void	free_str_arr(char **arr);
char	*ft_getenv(char **ep, const char *name);
int		ft_strcmp(char *s1, char *s2);
// error
void	permission_denied(char **cmd, char *name);
void	cmd_not_found(char **cmd);

// error_handle.c
void	failed();
void	open_failed(char *file_name);
void	dup_failed(int fd);
void	malloc_failed(char **cmd, char *path);
void	exec_failed(char **cmd1, char *path);

#endif