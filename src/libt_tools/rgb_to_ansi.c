/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_ansi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 05:05:25 by tsedigi           #+#    #+#             */
/*   Updated: 2017/07/18 05:05:26 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		set_ito(int *ito, char type, int nb)
{
	static int	f[18] = {0, 0, 0, 1, 2, 1, 1, 2, 2, 0, 0, 0, 1, 2, 1, 1, 2, 2};
	static int	s[18] = {0, 1, 2, 0, 0, 1, 2, 1, 2, 0, 1, 2, 0, 0, 1, 2, 1, 2};

	if (type == 'r')
	{
		*ito += nb <= 9 ? 36 * 4 : 36 * 5;
		*ito += 6 * f[nb];
		*ito += s[nb];
	}
	else
	{
		if (type == 'g')
			*ito += nb <= 9 ? 6 * 4 : 6 * 5;
		else
			*ito += nb <= 9 ? 4 : 5;
		*ito += 36 * f[nb];
		*ito += type == 'g' ? s[nb] : 6 * s[nb];
	}
}

char		*get_color_(int nb, char type)
{
	char		*ret;
	char		*ato;
	int			ito;

	if (nb == 0 || nb > 18)
		return (NULL);
	ret = ft_strnew(15);
	ft_strcat(ret, "\033[38;5;");
	ito = 16;
	set_ito(&ito, type, nb);
	ft_strcat(ret, ato = ft_itoa(ito));
	ft_strcat(ret, "m");
	ft_memdel((void **)&ato);
	return (ret);
}
