/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:11:42 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/06 14:07:00 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_cmd_str.h"

static char *free_arr(char **arr);

char	**split_cmd_str(char *str)
{
	char	**arr;
	size_t	cnt;
	size_t	i;

	cnt = count_arr(str);
	arr = ft_calloc(sizeof(char *), cnt + 1);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < cnt)
	{
		while (*str && is_delimiter(*str, NORMAL))
			str++;
		arr[i] = get_token(&str);
		if (!arr[i])
			return (free_arr(arr));
		i++;
	}
	return (arr);
}

static char *get_token(char **str)
{
	char	*head;
	int		state;

	state = NORMAL;
	head = *str;
	while (**str && !is_delimiter(**str, state))
	{
		state = update_state(**str, state);
		(*str)++;
	}
	return (dup_token(head, *str - head));
}

static char *free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}