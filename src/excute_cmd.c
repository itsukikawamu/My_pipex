/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:59:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/11 21:40:52 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "split_cmd_str.h"

int	excute_cmd(t_ctx *ctx)
{
	char	**argv;
	int		rev;

	argv = split_cmd_str(ctx->cmds);
	if (!argv)
		return (-1);
	rev = execute(ctx);
	free_str_arr(argv);
	return (rev);
}

int	excute(t_cp *cp)
{
	if (find_exec_file(cp) == -1)
		return (-1);
	if (connect_child_process(cp) == -1)
		return (-1);
	if (execve(cp->cmd_path, cp->cmd, cp->ep) == -1)
		return (-1);
	return (0);
}
