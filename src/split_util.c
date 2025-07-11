/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:16:33 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/11 19:46:05 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_cmd_str.h"

static bool	is_char_to_display(const char *str, int state);

char	*cpy_token(char *token, char *src, size_t n)
{
	size_t	i;
	int		state;

	i = 0;
	state = NORMAL;
	while (n--)
	{
		if (is_char_to_display(src, state))
			token[i++] = *src;
		state = update_state(*src, state);
		src++;
	}
	return (token);
}

size_t	count_token_len(char *str, size_t n)
{
	size_t	len;
	int		state;

	len = 0;
	state = NORMAL;
	while (n--)
	{
		if (is_char_to_display(str, state))
			len++;
		state = update_state(*str, state);
		str++;
	}
	return (len);
}

int	update_state(char c, int state)
{
	if (!(state & (SINGLE_QUOTE | ESCAPED)) && c == '\\')
		return (state | ESCAPED);
	if (state & ESCAPED)
		return (state & ~ESCAPED);
	if ((state & SINGLE_QUOTE) && c == '\'')
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

static bool	is_char_to_display(const char *str, int state)
{
	if (state == NORMAL && (*str == '\''))
		return (false);
	else if (state == NORMAL && (*str == '"'))
		return (false);
	else if (state == NORMAL && (*str == '\\'))
		return (false);
	else if ((state & SINGLE_QUOTE) && (*str == '\''))
		return (false);
	else if ((state & DOUBLE_QUOTE) && (*str == '"'))
		return (false);
	else if ((state & DOUBLE_QUOTE) && (*str == '\\'))
		if (str[1] == '\\' || str[1] == '"')
			return (false);
	return (true);
}

bool	is_delimiter(char c, int state)
{
	if (state & (SINGLE_QUOTE | DOUBLE_QUOTE | ESCAPED))
		return (0);
	return (c == ' ' || c == '\t' || c == '\n');
}
