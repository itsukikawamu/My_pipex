/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_child_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:59:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/06 23:57:11 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int create_child_process(int **pipefd, t_ctx *ctx)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execute_cmd(*ctx->cmd, ctx->cp.path, ctx->infile, pipefd[1]);
	}
	return (0);
}