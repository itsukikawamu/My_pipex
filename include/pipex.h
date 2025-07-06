/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:10:14 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/06 16:52:50 by ikawamuk         ###   ########.fr       */
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
}	t_ctx;

void	validate(int ac, char *av[]);

#endif