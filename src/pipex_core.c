/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:51:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/07 00:10:41 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	pipex_core(t_ctx *ctx)
{
	int		pipefd[2];
	size_t	i;

	ctx->cp.input = ctx->infile;
	while (i < ctx->cmd_num)
	{
		// if (set_fd() == -1)
		// 	return (-1);
		if (excute_cmd(ctx) == -1)
			return (-1);
		ctx->cmd++;
		i++;
	}
	return (0);
}
