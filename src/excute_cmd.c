/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:59:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/11 22:24:21 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "split_cmd_str.h"


static int	excute(t_cp *cp);
static int	connect_child_process(t_cp *cp);
static int	find_exec_file(t_cp *cp);

int	excute_cmd(t_ctx *ctx)
{
	int		rev;

	ctx->cp->cmd = split_cmd_str(*ctx->cmds);
	if (!ctx->cp->cmd)
		return (-1);
	rev = excute(ctx->cp);
	free_str_arr(ctx->cp->cmd);
	return (rev);
}

static int	excute(t_cp *cp)
{
	if (find_exec_file(cp) == -1)
		return (-1);
	if (connect_child_process(cp) == -1)
		return (-1);
	if (execve(cp->cmd_path, cp->cmd, cp->ep) == -1)
		return (-1);
	return (0);
}

static int	connect_child_process(t_cp *cp)
{
	(void)cp;
	return (0);
}

static int	find_exec_file(t_cp *cp)
{
	int	rev;

	if (ft_strchr(cp->cmd[0], '/'))
	{
		cp->cmd_path = cp->cmd[0];
		rev = check_access(cp->cmd_path);
		if (rev == PERMISSION_DENIED)
			return (errno = EACCES, PERMISSION_DENIED);
		else if (rev == COMMAND_NOT_FOUND)
			return (errno == ENOENT, COMMAND_NOT_FOUND);
	}
	else
	{
		cp->cmd_path = get_cmd_path(cp->cmd, cp->env_paths);
		if (!cp->cmd_path)
		{
			errno = ENOMEM;
			return (-1);
		}
	}
	return (0);
}
