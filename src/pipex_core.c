/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:51:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/06 19:07:39 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	pipex_core(t_ctx *ctx)
{
	int		pipefd[2];
	size_t	i;

	while (i < ctx->cmd_num)
	{
		if (pipe(pipefd) == -1)
			return (-1);
		if (create_child_process(&pipefd, ctx) == -1)
			return (-1);
		ctx->cmd++;
		i++;
	}
	return (0);
}
