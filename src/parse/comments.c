/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 06:52:38 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/01 06:52:39 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		checking_comment(char *line, size_t num, int *breaker, t_env *e)
{
	if (modifier_on(breaker))
	{
		push_back_err(line, num, EXPECT_ROOM_NOT_COMMENT, e);
		*breaker = 0 | ERR_BREAKER;
	}
	else
		*breaker = 0;
}
