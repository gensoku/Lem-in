/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integrity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 06:24:43 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/01 06:24:44 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			check_integrity(t_env *e, char *line, int *breaker, size_t num)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = ft_strlen(line);
	if (!line || !len)
	{
		push_back_err(line, num, EMPTY_LINE, e);
		*breaker = 0 | ERR_BREAKER;
	}
	else if (line[0] == '#' && (!line[1] || line[1] != '#'))
		checking_comment(line, num, breaker, e);
	else if (!ft_strncmp(line, "##", 2))
		checking_modifiers(line, num, breaker, e);
	else
		checking_room_tube(line, num, breaker, e);
}
