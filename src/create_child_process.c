/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_child_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:59:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/07 00:07:22 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int f(int **pipefd, t_ctx *ctx)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execute_cmd(*ctx->cmd, ctx->cp.path, ctx->infile, pipefd[1]);
	}
	return (0);
}