/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhexu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:02:01 by pmedina-          #+#    #+#             */
/*   Updated: 2021/04/06 20:07:17 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	transformhxmay(unsigned int x)
{
	char	c;

	if (x >= 16)
		transformhxmay(x / 16);
	x %= 16;
	if (x < 10)
		c = x + '0';
	else
		c = x + 55;
	write(1, &c, 1);
}

void	printhexu(t_printf *j, unsigned int x)
{
	int		space;
	int		zero;
	int		len;

	len = hxlen(x);
	zero = 0;
	if (j->precision < 0)
		j->precision = len;
	if (j->precision <= len)
		space = j->width - len;
	else
		space = j->width - j->precision;
	if (x == 0 && j->precision == 0 && j->dot == '.')
		space += 1;
	if (j->precision > len)
		zero = j->precision - len;
	while (space-- > 0 && j->tab != '-')
	{
		if (j->zero_space != '0' || (j->dot == '.' && j->precision >= 0))
			j->lenstr += write(1, " ", 1);
		else
			j->lenstr += write(1, "0", 1);
	}
	while (zero-- > 0)
		j->lenstr += write(1, "0", 1);
	if (!(j->precision == 0 && x == 0 && j->dot == '.'))
		transformhxmay(x);
	j->lenstr += len;
	if (j->tab == '-')
	{
		space++;
		while (space-- > 0)
			j->lenstr += write(1, " ", 1);
	}
	if (x == 0 && j->precision == 0 && j->dot == '.' && j->width >= 0)
		j->lenstr--;
}