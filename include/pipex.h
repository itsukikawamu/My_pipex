/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:10:14 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/06 18:52:38 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "split_cmd_str.h"
# include "utils.h"
# include <stdio.h>

typedef struct s_ctx{
	int		in_fd;
	int		out_fd;
	char	*err_str;
	size_t	cmd_num;
}	t_ctx;

void	validate(int ac, char *av[]);
int		set_ctx(int ac, char **av, t_ctx *ctx);
int		pipex_core(t_ctx *ctx);
void	error(char *str);

#endif