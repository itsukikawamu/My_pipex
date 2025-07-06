/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:51:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/07 00:06:56 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	pipex_core(t_ctx *ctx)
{
	int		pipefd[2];
	size_t	i;

	
	while (i < ctx->cmd_num)
	{
		// if (set_fd() == -1)
		// 	return (-1);
		if (f(&pipefd, ctx) == -1)
			return (-1);
		ctx->cmd++;
		i++;
	}
	return (0);
}
