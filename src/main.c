/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:10:37 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/12 15:18:52 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

int	main(int ac, char *av[], char *ep[])
{
	t_ctx	ctx;

	validate(ac, av);
	
	if (set_ctx(ac, av, ep, &ctx) == -1)
	{
		error(ctx.err_str);
		exit(EXIT_FAILURE);
	}
	pipex_core(&ctx);
	if (WIFEXITED(ctx.status))
		return (WEXITSTATUS(ctx.status));
	else if (WIFSIGNALED(ctx.status))
		return (128 + WTERMSIG(ctx.status));
	else
		return (1);
}
