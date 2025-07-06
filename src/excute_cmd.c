/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:59:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/07 00:12:55 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int excute_cmd(t_ctx *ctx)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execute(*ctx->cmd, ctx->cp.ep, ctx->cp.input, ctx->cp.output);
	}
	return (0);
}