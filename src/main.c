/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:10:37 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/06 15:05:22 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	error();

int	main(int ac, char *av[], char *ep[])
{
	char	**arr;

	(void)ep;
	if (ac < 2)
		return (1);
	// ft_printf("av[1]: %s\n", av[1]);
	arr = split_cmd_str(av[1]);
	if (!arr)
		error();
	return (0);
}

static void	error()
{
	if (errno == SYNTAX_ERROR1)
		ft_putstr_fd("syntax error: unterminated quote or dangling \\\n", 2);
	else if (errno == SYNTAX_ERROR2)
	ft_putstr_fd("syntax error: line ends with \\\n", 2);
}