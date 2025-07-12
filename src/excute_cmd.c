/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:59:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/12 18:28:31 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "split_cmd_str.h"
#include <sys/wait.h>


static int	excute(t_cp *cp);
static int	connect_to_pipe(t_cp *cp);
static int	find_exec_file(t_cp *cp);
static int	get_cmd_path(char **path, char **cmd, char **dir_arr);
static int	update_status(int cp_status);

int	excute_cmd(t_ctx *ctx)
{
	pid_t	pid;
	int		status;
	
	ctx->cp.cmd = split_cmd_str(*ctx->cmds);
	if (!ctx->cp.cmd)
		return (-1);
	if (find_exec_file(&ctx->cp) == -1)
	{
		if (errno == CMD_NOT_FOUND)
			ctx->status = 127;
		else if (errno == PERM_DENIED)
			ctx->status = 126;
		return (-1);
	}
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
		excute(&ctx->cp);
	close(ctx->cp.input);
	close(ctx->cp.output);
	free_str_arr(ctx->cp.cmd);
	waitpid(pid, &status, 0);
	ctx->status = update_status(status);
	return (0);
}

static int	update_status(int cp_status)
{
	if (WIFEXITED(cp_status))
		return (WEXITSTATUS(cp_status));
	else if (WIFSIGNALED(cp_status))
		return (WTERMSIG(cp_status));
	return (1);
}

static int	excute(t_cp *cp)
{
	if (connect_to_pipe(cp) == -1)
		return (-1);
	execve(cp->cmd_path, cp->cmd, cp->ep);
	error(cp->cmd[0]);
	if (errno == CMD_NOT_FOUND)
		exit(127);
	else if (errno == PERM_DENIED)
		exit(126);
	else
		exit(1);
	return (-1);
}

static int	connect_to_pipe(t_cp *cp)
{
	if (dup2(cp->input, STDIN_FILENO) == -1)
		return (-1);
	close(cp->input);
	if (dup2(cp->output, STDOUT_FILENO) == -1)
		return (-1);
	close(cp->output);
	return (0);
}

static int	find_exec_file(t_cp *cp)
{
	int	rev;

	if (ft_strchr(cp->cmd[0], '/'))
	{
		cp->cmd_path = cp->cmd[0];
		rev = check_access(cp->cmd_path);
		
		if (rev == PERM_DENIED)
			return (errno = PERM_DENIED, -1);
		else if (rev == CMD_NOT_FOUND)
			return (errno = CMD_NOT_FOUND, -1);
	}
	else
	{
		
		rev = get_cmd_path(&cp->cmd_path, cp->cmd, cp->env_paths);
		
		if (rev == PERM_DENIED)
			return (errno = PERM_DENIED, -1);
		else if (rev == CMD_NOT_FOUND)
			return (errno = CMD_NOT_FOUND, -1);	
	}
	return (0);
}

static int	get_cmd_path(char **path, char **cmd, char **dir_arr)
{
	size_t	i;
	int		rev;

	i = 0;
	while (dir_arr[i])
	{
		*path = join_dir_and_file_name(dir_arr[i], cmd[0]);
		if (!path)
			return (-3);
		rev = check_access(*path);
		if (rev == PERM_DENIED || rev == 0)
			return (rev);
		free(*path);
		i++;
	}
	return (CMD_NOT_FOUND);
}
