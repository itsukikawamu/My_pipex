/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:51:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/11 22:22:09 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "pipex.h"


static int	set_cp(t_ctx *ctx);
static int	new_pipe(int *input, int *output);

int	pipex_core(t_ctx *ctx)
{
	ctx->cp->input = ctx->infile;
	while (ctx->cmd_num--)
	{
		if (set_cp(ctx) == -1)
		{
			ctx->err_str = "pipe";
			return (-1);
		}
		if (excute_cmd(ctx) == -1)
		{
			close(ctx->cp->output);
			ctx->err_str = *ctx->cp->cmd;
			return (-1);
		}
		ctx->cmds++;
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
		if (new_pipe(&ctx->cp->input, &ctx->cp->output) == -1)
			return (-1);
	}
	return (0);	
}

static int	new_pipe(int *input, int *output)
{
	int	rev;
	int	pipefd[2];

	rev = pipe(pipefd);
	if (!rev)
	{
		*input = pipefd[0];
		*output = pipefd[1];
	}
	else
	{
		*input = -1;
		*output = -1;
	}
	return (rev);
}