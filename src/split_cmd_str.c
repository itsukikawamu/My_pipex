/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:11:42 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/06 15:08:15 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_cmd_str.h"

static char 	**free_arr(char **arr);
static char 	*dup_token(char *src, size_t n);
static size_t	count_arr(char *str);
static char 	*get_token(char **str);

char	**split_cmd_str(char *str)
{
	char	**arr;
	size_t	cnt;
	size_t	i;

	errno = 0;
	cnt = count_arr(str);
	if (errno)
		return (NULL);
	arr = ft_calloc(sizeof(char *), cnt + 1);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < cnt)
	{
		arr[i] = get_token(&str);
		if (!arr[i])
			return (free_arr(arr));
		i++;
	}
	return (arr);
}

static size_t	count_arr(char *str)
{
	size_t	cnt;
	int		state;

	cnt = 0;
	state = NORMAL;
	while (*str)
	{
		while (*str && is_delimiter(*str, NORMAL))
			str++;
		if (*str)
			cnt++;
		while (*str && !is_delimiter(*str, state))
		{
			state = update_state(*str, state);
			str++;
		}
	}
	if (state & (SINGLE_QUOTE | DOUBLE_QUOTE | ESCAPED))
	{
		errno = SYNTAX_ERROR1;
		return (0);
	}
	return (cnt);
}

static char *get_token(char **str)
{
	char	*head;
	int		state;

	state = NORMAL;
	while (**str && is_delimiter(**str, NORMAL))
		(*str)++;
	head = *str;
	while (**str && !is_delimiter(**str, state))
	{
		state = update_state(**str, state);
		(*str)++;
	}
	return (dup_token(head, *str - head));
}

static char *dup_token(char *src, size_t n)
{
	char	*token;
	size_t	len;

	if (n >= SIZE_MAX - 1|| !src)
		return (NULL);
	len = count_token_len(src, n);
	token = ft_calloc(sizeof(char), len + 1);
	if (!token)
		return (NULL);
	return (cpy_token(token, src, n));
}

static char **free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}