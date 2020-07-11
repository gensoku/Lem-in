/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 06:46:55 by tsedigi           #+#    #+#             */
/*   Updated: 2017/05/27 06:46:58 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_get_file(char *path, int fd)
{
	char	*ret;
	char	buff[BUFF_SIZE + 1];
	int		cur_fd;
	char	*tmp;

	ret = NULL;
	if (!path)
		return (ret);
	cur_fd = (fd != -1) ? fd : -1;
	ft_bzero(&buff, BUFF_SIZE + 1);
	if ((fd = open(path, O_RDONLY, O_SYNC)) != -1)
	{
		while (read(fd, buff, BUFF_SIZE) > 0)
		{
			tmp = (ret) ? ft_strjoin(ret, buff) : ft_strdup(buff);
			(ret) ? free(ret) : 0;
			ret = ft_strdup(tmp);
			ft_memdel((void **)&tmp);
			ft_bzero(&buff, BUFF_SIZE);
		}
		close(fd);
	}
	(!ret) ? ret = ft_strdup("") : 0;
	return (ret);
}
