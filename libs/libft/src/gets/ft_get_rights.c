/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_rights.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 06:49:57 by tsedigi           #+#    #+#             */
/*   Updated: 2017/05/27 06:49:58 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

mode_t			get_rights(void)
{
	mode_t		ret;

	ret = 0;
	ret |= S_IWUSR;
	ret |= S_IRUSR;
	ret |= S_IRGRP;
	ret |= S_IROTH;
	return (ret);
}
