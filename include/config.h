/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 23:13:15 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/06 23:14:07 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

#include <stdlib.h>

typedef struct s_ctx{
	int		in_fd;
	int		out_fd;
	char	*err_str;
	size_t	cmd_num;
	char	**cmd;
	char	**ep;
}	t_ctx;

#endif