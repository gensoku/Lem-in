/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_tubes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 07:49:07 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/01 07:49:08 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	set_ants_or_err(char *line, size_t num, t_env *e, char **arr)
{
	size_t	len;

	len = ft_len_tab(arr);
	if (len != 1)
	{
		push_back_err(line, num, EXPECTED_ANTS_NB, e);
		return ((ERR_BREAKER));
	}
	else if (!ft_isnum_str(line))
	{
		push_back_err(line, num, ANTS_NB_INVALID_FORMAT, e);
		return ((ERR_BREAKER));
	}
	e->ants = ft_atoi(line);
	return (0);
}

void		checking_room_tube(char *line, size_t num, int *breaker, t_env *e)
{
	char	**arr;
	size_t	len;

	arr = ft_strsplit(line, ' ');
	if (!arr)
		display_er(e, 1);
	len = ft_len_tab(arr);
	if (e->ants == -1)
	{
		*breaker = set_ants_or_err(line, num, e, arr);
		ft_del_tab((void ***)&arr);
		arr = NULL;
		return ;
	}
	if (len == 1)
		checking_tube(line, num, breaker, e);
	else if (len == 3)
		checking_room(line, num, breaker, e);
	else
	{
		push_back_err(line, num, WRONG_FORMAT, e);
		*breaker = 0 | ERR_BREAKER;
	}
	ft_del_tab((void ***)&arr);
	arr = NULL;
}
