/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 08:14:44 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/01 08:14:45 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		checking_room(char *line, size_t num, int *breaker, t_env *e)
{
	char	**arr;

	arr = ft_strsplit(line, ' ');
	(!arr) ? display_er(e, 1) : 0;
	if (is_not_valid(arr[0][0]) || ft_strchr(arr[0], '-'))
	{
		push_back_err(line, num, INVALID_ROOM_NAME, e);
		*breaker = 0 | ERR_BREAKER;
	}
	else if (!ft_isnum_str(arr[1]) || !ft_isnum_str(arr[2]))
	{
		push_back_err(line, num, INVALID_COORD_ROOM, e);
		*breaker = 0 | ERR_BREAKER;
	}
	else
		*breaker |= IS_ROOM;
	ft_del_tab((void ***)&arr);
	arr = NULL;
}
