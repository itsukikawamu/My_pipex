/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 19:55:49 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/01 23:38:03 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	invalid_usage(char *name);
static void	show_help(char *name);

void	validate(int ac, char *av[])
{
	if (ac < 5)
		invalid_usage(av[0]);
	else if (ft_strcmp(av[1], "--help") == 0 || ft_strcmp(av[1], "-h") == 0)
		show_help(av[0]);
	return ;
}

static void	show_help(char *name)
{
	ft_printf("Usage:\n\t%s <file1> <cmd1> <cmd2> <file2>\n\n", name);
	ft_printf("It must take 4 arguments.\n");
	ft_printf("\tfile1 and file2 are file names.\n");
	ft_printf("\tcmd1 and cmd2 are shell commands with their parameters.\n");
	ft_printf("It must behave exactly like the following shell command:\n");
	ft_printf("\t$> < file1 cmd1 | cmd2 > file2\n\n");
	ft_printf("Multiple pipes are available.\n");
	ft_printf("This program also support « and »"\
		" when the first parameter is \"here_doc\".\n");
	ft_printf("Example:\n\t$> ./pipex here_doc LIMITER cmd cmd1 file\n");
	ft_printf("behave like:\n\tcmd << LIMITER | cmd1 >> file\n");
	exit(0);
}

static void	invalid_usage(char *name)
{
	ft_putstr_fd("pipex: not enough arguments\n", 2);
	ft_putstr_fd("Try '", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(" --help' for more information.\n", 2);
	exit(1);
}
