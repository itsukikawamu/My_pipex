/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:51:22 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/06 18:57:20 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/types.h>

int	pipex_core(t_ctx *ctx)
{
	int		pipefd[2];
	pid_t	pid;
	size_t	i;

	while (i < ctx->cmd_num)
	{
		if (pipe(pipefd) == -1)
			return (-1);
		
		i++;
	}
	return (0);
}
