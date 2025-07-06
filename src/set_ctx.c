/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ctx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:07:59 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/06 19:03:03 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "pipex.h"

static int	open_files(int ac, char *av[], t_ctx *ctx);

int	set_ctx(int ac, char **av, t_ctx *ctx)
{
	ctx->err_str = NULL;
	if (open_files(ac, av, ctx) == -1)
		return (-1);
	ctx->cmd_num = ac - 3;
	ctx->cmd = av + 2;
	return (0);
}

static int	open_files(int ac, char *av[], t_ctx *ctx)
{
	ctx->in_fd = open(av[1], O_RDONLY);
	if (ctx->in_fd == -1)
	{
		ctx->err_str = av[1];
		return (-1);
	}
	ctx->out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ctx->out_fd == -1)
	{
		close(ctx->in_fd);
		ctx->err_str = av[ac - 1];
		return (-1);
	}
	return (0);
}
