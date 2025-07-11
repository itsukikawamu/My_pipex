/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ctx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:07:59 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/11 20:47:17 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "pipex.h"

static int	open_files(int ac, char *av[], t_ctx *ctx);
static char	**get_path_env(char **ep);
static char	*ft_getenv(char **ep, const char *name);
static int	init_cp(int ac, char **av, char **ep, t_cp *cp);

int	set_ctx(int ac, char **av, char **ep, t_ctx *ctx)
{
	ctx->err_str = NULL;
	if (open_files(ac, av, ctx) == -1)
		return (-1);
	ctx->cmd_num = ac - 3;
	ctx->cmd = av + 2;
	init_cp(ac, av, ep, ctx->cp);

	return (0);
}

static int	init_cp(int ac, char **av, char **ep, t_cp *cp)
{
	cp->ep = ep;
	cp->path_env = get_path_env(ep);	
}

static int	open_files(int ac, char *av[], t_ctx *ctx)
{
	ctx->infile = open(av[1], O_RDONLY);
	if (ctx->infile == -1)
	{
		ctx->err_str = av[1];
		return (-1);
	}
	ctx->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ctx->outfile == -1)
	{
		close(ctx->infile);
		ctx->err_str = av[ac - 1];
		return (-1);
	}
	return (0);
}

static char	**get_path_env(char **ep)
{
	char	*path;

	path = ft_getenv(ep, "PATH");
	return (ft_split(path, ':'));
}

static char	*ft_getenv(char **ep, const char *name)
{
	int	name_len;
	int	i;

	if (!ep || !name)
		return (NULL);
	name_len = ft_strlen(name);
	i = 0;
	while (ep[i])
	{
		if (ft_strncmp(ep[i], name, name_len) == 0 && ep[i][name_len] == '=')
			return (ep[i] + name_len + 1);
		i++;
	}
	return (NULL);
}
