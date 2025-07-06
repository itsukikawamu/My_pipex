/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:10:37 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/06 17:02:38 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>

static void	error(char *str);
static int	set_ctx(int ac, char **av, t_ctx *ctx);


int	main(int ac, char *av[], char *ep[])
{
	t_ctx	ctx;

	(void)ep;
	validate(ac, av);
	if (set_ctx(ac, av, &ctx) == -1)
		error(ctx.err_str);
	return (0);
}

static int	set_ctx(int ac, char **av, t_ctx *ctx)
{
	ctx->err_str = NULL;
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
