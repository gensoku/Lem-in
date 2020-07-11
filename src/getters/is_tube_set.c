/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_tube_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 04:37:50 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/06 04:37:51 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			is_tube_set(char *line, t_tubes *lst)
{
	t_tubes	*tmp;
	char	*trim;

	if (!line || !lst)
		return (0);
	tmp = lst;
	trim = ft_strtrim(line);
	while (tmp)
	{
		if (!ft_strcmp(trim, tmp->full) || !ft_strcmp(trim, tmp->full_rotate))
		{
			ft_memdel((void **)&trim);
			return (1);
		}
		tmp = tmp->next;
	}
	ft_memdel((void **)&trim);
	return (0);
}
