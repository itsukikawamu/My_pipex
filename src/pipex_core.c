/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:51:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/11 20:04:58 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "pipex.h"

int	pipex_core(t_ctx *ctx)
{
	ctx->cp->input = ctx->infile;
	while (ctx->cmd_num--)
	{
		// if (set_cp(ctx->cp, &tmpfd) == -1)
		// 	return (-1);
		if (excute_cmd(ctx) == -1)
		{
			close(ctx->cp->output);
			return (-1);
		}
		ctx->cmd++;
	}
	return (0);
}
