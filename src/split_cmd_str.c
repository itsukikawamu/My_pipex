/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:11:42 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/06 13:19:40 by ikawamuk         ###   ########.fr       */
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
		arr[i] = get_token(&str);
		if (!arr[i])
			return (free_arr(arr));
		i++;
	}
	return (arr);
}

static char *get_token(char **str)
{
	char	*token;

	
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