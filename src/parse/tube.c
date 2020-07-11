/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 07:48:21 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/01 07:48:22 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		check_valid_tube(char *line, size_t num, t_env *e, int *breaker)
{
	char		**arr;
	char		*f_norme;

	arr = ft_strsplit(line, '-');
	if (modifier_on(breaker))
	{
		push_back_err(line, num, EXPECTED_ROOM_NOT_TUBE, e);
		ft_del_tab((void ***)&arr);
		return (0);
	}
	if (is_not_valid(arr[0][0]) || is_not_valid(arr[1][0]))
	{
		f_norme = ft_strjoin(BAD_TUBE_ROOM_CHAR, BTRC_DETAIL);
		push_back_err(line, num, f_norme, e);
		ft_memdel((void **)&f_norme);
		ft_del_tab((void ***)&arr);
		return (0);
	}
	ft_del_tab((void ***)&arr);
	return (1);
}

void			checking_tube(char *line, size_t num, int *breaker, t_env *e)
{
	char		**arr;
	size_t		len;

	arr = ft_strsplit(line, '-');
	(!arr) ? display_er(e, 1) : 0;
	len = ft_len_tab(arr);
	if (len != 2)
	{
		push_back_err(line, num, BAD_TUBE_FORMAT, e);
		*breaker = 0 | ERR_BREAKER;
		ft_del_tab((void ***)&arr);
		arr = NULL;
		return ;
	}
	*breaker = (!check_valid_tube(line, num, e, breaker)) ?
		(0 | ERR_BREAKER) : (0 | IS_TUBE);
	ft_del_tab((void ***)&arr);
	arr = NULL;
}
