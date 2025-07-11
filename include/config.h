/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 23:13:15 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/12 00:12:13 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include <stdlib.h>
# include <sys/types.h>




# define SYNTAX_ERROR1	1001
# define SYNTAX_ERROR2	1002
# define PIPE_ERROR		1003
# define EXCUTE_ERROR	1004
# define CMD_NOT_FOUND	1005
# define PERM_DENIED	1006

typedef struct s_cp{
	pid_t	pid;
	char	**cmd;
	int		input;
	int		output;
	char	**ep;
	char	**env_paths;
	char	*cmd_path;
}	t_cp;

typedef struct s_ctx{
	int		infile;
	int		outfile;
	int		prev_pipe_to_read;
	char	*err_str;
	size_t	cmd_num;
	char	**cmds;
	t_cp	*cp;
}	t_ctx;

#endif