/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:10:37 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/06 17:08:35 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


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
