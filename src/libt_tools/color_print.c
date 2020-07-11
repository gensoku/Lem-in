/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 02:11:16 by tsedigi           #+#    #+#             */
/*   Updated: 2017/06/06 02:11:17 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_color(char *color, char *msg, int fd, size_t num)
{
	ft_putstr_fd(color, fd);
	if (msg)
		ft_putstr_fd(msg, fd);
	else
		ft_putnbr_fd(num, fd);
	ft_putstr_fd(RESET, fd);
}
