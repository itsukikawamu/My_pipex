/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:10:37 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/12 00:16:26 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char *ep[])
{
	t_ctx	ctx;

	validate(ac, av);
	if (set_ctx(ac, av, ep, &ctx) == -1)
		error(ctx.err_str);
	if (pipex_core(&ctx) == -1)
		error(ctx.err_str);
	return (0);
}
