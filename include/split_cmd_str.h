/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd_str.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:36:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/06 15:07:53 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_CMD_STR_H
# define SPLIT_CMD_STR_H

# include "libft.h"
# include <errno.h>
# include <stdbool.h>

# define NORMAL			0x00
# define SINGLE_QUOTE	0x01
# define DOUBLE_QUOTE	0x02
# define ESCAPED		0x10

# define SYNTAX_ERROR1	1001
# define SYNTAX_ERROR2	1002

// typedef struct s_ctx{
// 	char	*head;
// 	int		in_token;
// 	int		state;
// 	size_t	cnt;
// }	t_token_ctx;

char	**split_cmd_str(char *str);
// split_util.c
size_t	count_token_len(char *str, size_t n);
char	*cpy_token(char *token, char *src, size_t n);
bool	is_delimiter(char c, int state);
int		update_state(char c, int state);

#endif