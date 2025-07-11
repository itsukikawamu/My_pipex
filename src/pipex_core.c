/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:51:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/11 20:19:49 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "pipex.h"


static int	set_cp(t_ctx *ctx);

int	pipex_core(t_ctx *ctx)
{
	ctx->cp->input = ctx->infile;
	while (ctx->cmd_num--)
	{
		if (set_cp(ctx) == -1)
		{
			errno = PIPE_ERROR;
			return (-1);
		}
		if (excute_cmd(ctx) == -1)
		{
			close(ctx->cp->output);
			errno = EXCUTE_ERROR;
			return (-1);
		}
		ctx->cmd++;
	}
	return (0);
}

static int	set_cp(t_ctx *ctx)
{
	int	tmp;

	if (ctx->cmd_num == 0)
		ctx->cp->output = ctx->outfile;
	else
	{
		tmp = ctx->cp->output;
		if (newpipe(tmp, ctx->cp->output) == -1)
			return (-1);
	}
	return (0);	
}
