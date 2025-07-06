/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:16:33 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/06 14:51:53 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_cmd_str.h"

int	update_state(char c, int state)
{
	if (!(state & (SINGLE_QUOTE | ESCAPED)) && c == '\\')
		return (state | ESCAPED);
	if (state & ESCAPED)
		return (state & ~ESCAPED);
	if ((state & SINGLE_QUOTE) &&  c == '\'')
		return (state & ~SINGLE_QUOTE);
	if ((state & DOUBLE_QUOTE) && !(state & ESCAPED) && c == '"')	
		return (state & ~DOUBLE_QUOTE);
	if ((state & (SINGLE_QUOTE | DOUBLE_QUOTE | ESCAPED)) == 0)
	{
		if (c == '\'')
			return (state | SINGLE_QUOTE);
		if (c == '"')
			return (state | DOUBLE_QUOTE);
	}
	return (state);
}

bool	is_syntax_error(int state)
{
	if (state & (SINGLE_QUOTE | DOUBLE_QUOTE | ESCAPED))
	{
		errno = SYNTAX_ERROR1;
		return (true);
	}
	return (false);
}

bool	is_delimiter(char c, int state)
{
	if (state & (SINGLE_QUOTE | DOUBLE_QUOTE | ESCAPED))
		return 0;
	return (c == ' ' || c == '\t' || c == '\n');
}
