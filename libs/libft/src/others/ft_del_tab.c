/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 06:34:03 by tsedigi           #+#    #+#             */
/*   Updated: 2017/05/27 06:34:04 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_del_tab(void ***arr)
{
	int			i;

	if (!arr || !*arr)
		return ;
	i = 0;
	while (*arr && (*arr)[i])
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
		++i;
	}
	free(*arr);
	*arr = NULL;
}
