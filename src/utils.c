/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 02:45:38 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/06 16:48:41 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getenv(char **ep, const char *name)
{
	int	name_len;
	int	i;

	if (!ep || !name)
		return (NULL);
	name_len = ft_strlen(name);
	i = 0;
	while (ep[i])
	{
		if (ft_strncmp(ep[i], name, name_len) == 0 && ep[i][name_len] == '=')
			return (ep[i] + name_len + 1);
		i++;
	}
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	free_str_arr(char **arr)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return ;
}
