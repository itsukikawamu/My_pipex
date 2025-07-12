/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:10:37 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/12 22:10:18 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

int	main(int ac, char *av[], char *ep[])
{
	t_ctx	ctx;

	validate(ac, av);

	set_ctx(ac, av, ep, &ctx);
	pipex_core(&ctx);
	return (ctx.status);
}
