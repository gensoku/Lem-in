/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 05:56:16 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/13 05:56:17 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_t_room			*dump_path(t_t_room *path, t_t_room *cur, t_env *e)
{
	t_t_room		*ret;
	t_t_room		*tmp;

	ret = NULL;
	tmp = path;
	while (tmp)
	{
		ret = push_back_link(tmp->name, ret, e);
		tmp = tmp->next;
	}
	ret = push_back_link(cur->name, ret, e);
	return (ret);
}

int					cmp_path2(t_t_room *s1, t_t_room *s2)
{
	if (s1 == s2)
		return (0);
	if ((!s2 && s2) || (s2 && !s1))
		return (1);
	while (s1)
	{
		if (!s2)
			return (1);
		if (ft_strcmp(s1->name, s2->name))
			return (1);
		s1 = s1->next;
		s2 = s2->next;
	}
	if (!s1 && !s2)
		return (0);
	return (1);
}

int					already_found(t_t_room *path, t_env *e)
{
	t_noob			*tmp;

	tmp = e->resolved;
	if (!tmp)
		return (0);
	while (tmp)
	{
		if (!cmp_path2(path, tmp->path))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
