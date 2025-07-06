/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:10:14 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/06 23:16:54 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "config.h"

void	validate(int ac, char *av[]);
int		set_ctx(int ac, char **av, char **ep, t_ctx *ctx);
int		pipex_core(t_ctx *ctx);
void	error(char *str);

#endif