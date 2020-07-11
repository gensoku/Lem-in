/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_send.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 05:36:09 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/13 05:36:10 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		send_first(t_noob *path, size_t *ant_num,
	size_t *last_path, t_env *e)
{
	*last_path = path->size;
	path->path->empty = 1;
	path->path->ant_num = *ant_num;
	display_ants(get_room(path->path->name, e->rooms), *ant_num, e);
	*ant_num += 1;
	e->ants--;
}

void			try_send(t_noob *path, size_t *ant_num,
	size_t *last_path, t_env *e)
{
	if (!e->ants || (e->max && e->ants == 1) || !path || !path->path)
		return ;
	if (*last_path == 0)
	{
		if ((e->max && (size_t)e->ants > path->size) || (!e->max && e->ants))
			send_first(path, ant_num, last_path, e);
	}
	else
	{
		if (((size_t)e->ants >= *last_path &&
			(size_t)e->ants >= path->size) || !e->max)
		{
			*last_path = path->size;
			path->path->empty = 1;
			path->path->ant_num = *ant_num;
			display_ants(get_room(path->path->name, e->rooms), *ant_num, e);
			*ant_num += 1;
			e->ants--;
		}
	}
}
