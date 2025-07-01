/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:20:11 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/02 00:11:57 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h> 
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>


char	*get_cmd_path(char **cmd, char **ep);

void	open_failed(char *file_name);
void	execute_cmd(char *arg, char **ep, int fd1, int fd2);
void	file_not_found(char *path);


int	main(int ac, char *av[], char **ep)
{
	int		in_fd;
	int		out_fd;
	int		pipefd[2];
	pid_t	pid;

	validate(ac, av);
	in_fd = open(av[1], O_RDONLY);
	if (in_fd == -1)
		open_failed(av[1]);
	out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out_fd == -1)
		open_failed(av[ac -1]);

		
	if (pipe(pipefd) == -1)
		failed();

	pid = fork();
	if (pid == 0)
	{
		close(pipefd[0]);
		execute_cmd(av[2], ep, in_fd, pipefd[1]);
	}
	
	pid = fork();
	if (pid == 0)
	{
		close(pipefd[1]);
		execute_cmd(av[3], ep, pipefd[0], out_fd);
	}
	wait(NULL);
	return (0);
}

void	execute_cmd(char *arg, char **ep, int fd1, int fd2)
{
	char	**cmd;
	char	*path;


	cmd = ft_split(arg, ' ');
	if (!cmd)
		malloc_failed(cmd, NULL);
	if (!cmd[0])
	{
		free(cmd);
		exit(1);
	}
	if (ft_strchr(cmd[0], '/'))
	{
		path = arg;
		if (access(path, F_OK) == 0)
		{
			if (access(path, X_OK) != 0)
				permission_denied(cmd, path);
		}
		else
			file_not_found(path);
	}
	else
	{
		path = get_cmd_path(cmd, ep);
		if (!path)
			malloc_failed(cmd, path);
	}
	if (dup2(fd1, STDIN_FILENO) == -1)
		dup_failed(fd1);
	close(fd1);
	if (dup2(fd2, STDOUT_FILENO) == -1)
		dup_failed(fd2);
	close(fd2);
	if (execve(path, cmd, ep) == -1)
		exec_failed(cmd, path);
}

void	file_not_found(char *path)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}