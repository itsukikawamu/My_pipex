/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:13:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/06 16:17:53 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define _GNU_SOURCE
# include <unistd.h>
# include "libft.h"

// utils.c
void	free_str_arr(char **arr);
char	*ft_getenv(char **ep, const char *name);
int		ft_strcmp(char *s1, char *s2);


#endif