/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exclude_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 09:16:49 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/09 09:16:50 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				as_a_link(t_t_room *s1, t_t_room *s2)
{
	t_t_room	*tmp;

	while (s1)
	{
		tmp = s2;
		while (tmp)
		{
			if (!ft_strcmp(s1->name, tmp->name))
				return (1);
			tmp = tmp->next;
		}
		s1 = s1->next;
	}
	return (0);
}

int				exclude_path(t_t_room *path, t_t_room *best, t_noob *stack)
{
	t_noob		*tmp;

	if (!best || !stack)
		return (1);
	tmp = stack;
	if (!cmp_path2(best, path))
		return (0);
	while (tmp)
	{
		if (as_a_link(tmp->path, path))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
