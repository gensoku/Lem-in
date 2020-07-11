/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_implode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 06:55:45 by tsedigi           #+#    #+#             */
/*   Updated: 2017/05/27 06:55:47 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		implode_norm(char **tab1)
{
	int			max;
	int			i;

	max = 0;
	i = 0;
	while (*tab1)
	{
		max += ft_strlen(*tab1) + 1;
		tab1++;
	}
	return (max);
}

static char		*implode_norm_2(char **tab1, char c, int i, char *ret)
{
	int			j;
	int			y;

	j = 0;
	y = 0;
	while (tab1[i])
	{
		while (tab1[i][j])
		{
			ret[y] = tab1[i][j];
			j++;
			y++;
		}
		ret[y] = c;
		i++;
		if (!tab1[i])
			ret[y] = 0;
		j = 0;
		y++;
	}
	return (ret);
}

char			*ft_implode(char **tab1, char c)
{
	char		*ret;
	int			max;

	if (!tab1)
		return (NULL);
	if (!c)
		c = ' ';
	max = implode_norm(tab1);
	if ((ret = (char *)ft_memalloc(sizeof(char) * max)) == NULL)
		return (NULL);
	return (implode_norm_2(tab1, c, 0, ret));
}
