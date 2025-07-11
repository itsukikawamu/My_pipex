/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:13:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/12 19:13:48 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define _GNU_SOURCE
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include "libft.h"
# include "config.h"

// excute_cmfd.c
int	excute_cmd(t_ctx *ctx);

// utils.c
char	*join_dir_and_file_name(char *dir, char *name);
int		check_access(char *path);
void	free_str_arr(char **arr);
int		ft_strcmp(char *s1, char *s2);
char	*ft_getenv(char **ep, const char *name);

// error_handle.c
void	open_failed(char *file_name);
void	error(char *str);

#endif