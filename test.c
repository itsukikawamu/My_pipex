/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 22:50:40 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/12 14:41:21 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>

int main()
{
	errno = ENOENT;
	perror("test");
}


// if (err == EACCES || err == ENOEXEC || err == EPERM)
// 		exit(126);
// 	if (err == ENOENT || err == ENOTDIR)
// 		exit(127);
// 	exit(EXIT_FAILURE);