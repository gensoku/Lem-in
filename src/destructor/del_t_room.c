/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_t_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 07:20:16 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/01 07:20:17 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			del_t_room(t_room *lst)
{
	t_room		*tmp;
	t_room		*tmp2;

	if (!lst)
		return ;
	tmp = lst;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		del_t_t_room(tmp2->lst);
		ft_memdel((void **)&tmp2->name);
		tmp2->start = 0;
		tmp2->end = 0;
		tmp2->x = 0;
		tmp2->y = 0;
		ft_memdel((void **)&tmp2);
	}
}
