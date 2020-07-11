/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 06:58:53 by tsedigi           #+#    #+#             */
/*   Updated: 2017/05/27 06:58:54 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tab_dup(char **src)
{
	char	**dup;
	int		i;

	i = -1;
	if (!src || !*src)
		return (NULL);
	if (!(dup = (char **)ft_memalloc(sizeof(char *) * ft_len_tab(src) + 1)))
		return (NULL);
	while (src[++i])
		dup[i] = ft_strdup(src[i]);
	dup[i] = NULL;
	return (dup);
}
