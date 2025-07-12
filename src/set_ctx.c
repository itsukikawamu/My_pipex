/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ctx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:07:59 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/12 22:17:51 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "pipex.h"
#include "libft.h"

static int	open_files(int ac, char *av[], t_ctx *ctx);
static char	**get_path_env(char **ep);

int	set_ctx(int ac, char **av, char **ep, t_ctx *ctx)
{
	ctx->err_str = NULL;
	open_files(ac, av, ctx);
	ctx->cmd_num = ac - 3;
	ctx->cmds = av + 2;
	ctx->cp.ep = ep;
	ctx->cp.env_paths = get_path_env(ep);

	if (!ctx->cp.env_paths)
		return (-1);
	ctx->cp.input = ctx->infile;
	return (0);
}

static int	open_files(int ac, char *av[], t_ctx *ctx)
{
	ctx->infile = open(av[1], O_RDONLY);
	if (ctx->infile == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		error(av[1]);
	}
	ctx->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ctx->outfile == -1)
	{
		if (ctx->infile != -1)
			close(ctx->infile);
		ft_putstr_fd("pipex: ", 2);
		error(av[ac -1]);
	}
	return (0);
}

static char	**get_path_env(char **ep)
{
	char	*path;
	
	path = ft_getenv(ep, "PATH");
	return (ft_split(path, ':'));
}
