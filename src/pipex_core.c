/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:51:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/12 22:13:33 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "pipex.h"


static int	set_cp(t_ctx *ctx);
static int	new_pipe(int *input, int *output);

int	pipex_core(t_ctx *ctx)
{
	while (ctx->cmd_num--)
	{
		if (set_cp(ctx) == -1)
		{
			ctx->err_str = "pipe";
			error(ctx->err_str);;
		}
		else if (excute_cmd(ctx) == -1)
		{
			close(ctx->cp.input);
			close(ctx->cp.output);
			ctx->err_str = *ctx->cmds;
			error(ctx->err_str);
		}
		ctx->cmds++;
		ctx->cp.input = ctx->prev_pipe_to_read;
	}
	return (0);
}

static int	set_cp(t_ctx *ctx)
{
	if (ctx->cmd_num == 0)
		ctx->cp.output = ctx->outfile;
	else
	{
		if (new_pipe(&ctx->prev_pipe_to_read, &ctx->cp.output) == -1)
			return (-1);
	}
	if (ctx->cp.input == -1 || ctx->cp.output == -1)
	{
		if (ctx->cp.input != -1)
			close(ctx->cp.input);
		if (ctx->cp.output != -1)
			close(ctx->cp.output);
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