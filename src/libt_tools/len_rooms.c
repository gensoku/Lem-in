/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 11:57:35 by tsedigi           #+#    #+#             */
/*   Updated: 2017/07/18 11:57:37 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				len_rooms(t_room *rooms)
{
	int			ret;
	t_room		*r;

	ret = 0;
	r = rooms;
	while (r)
	{
		ret++;
		r = r->next;
	}
	return (ret);
}
