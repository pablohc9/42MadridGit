/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pherranz <pherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:48:50 by ltejedor          #+#    #+#             */
/*   Updated: 2021/04/14 18:56:39 by pherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		treat_spec(va_list args, int *len, t_flags fl)
{
	if (fl.spe_c == '%')
		print_spec_pct(len, fl);
	if (fl.spe_c == 'c')
		print_spec_c(len, fl, va_arg(args, int));
	if (fl.spe_c == 's')
		print_spec_s(len, fl, va_arg(args, char *));
	if (fl.spe_c == 'p')
		print_spec_p(len, fl, va_arg(args, unsigned long int));
	if (fl.spe_c == 'i' || fl.spe_c == 'd' || fl.spe_c == 'u')
		print_spec_i_d_u(len, fl, args);
	if (fl.spe_c == 'x' || fl.spe_c == 'X')
		print_spec_x(len, fl, args);
}

static t_flags	treat_star(va_list args, t_flags fl, int *j)
{
	int	value;

	(*j)++;
	value = va_arg(args, int);
	if (fl.point == 0)
	{
		fl.width = (value >= 0) ? value : -value;
		fl.minus = (value >= 0) ? fl.minus : 1;
	}
	if (fl.point == 1)
	{
		if (value >= 0)
			fl.precision = value;
		else
			fl.point = 0;
	}
	return (fl);
}

static t_flags	treat_flags(va_list args, t_flags fl)
{
	int		j;

	j = 0;
	while (ft_strchr_01(FLAGS, fl.set[j]))
	{
		if (fl.set[j] == '0')
			fl.pad_c = '0';
		j++;
	}
	if (fl.set[j] == '*')
		fl = treat_star(args, fl, &j);
	while (fl.set[j] != '\0' && ft_strchr_01(DIGITS, fl.set[j]))
		fl.width = 10 * fl.width + fl.set[j++] - '0';
	if (fl.set[j] == '.')
	{
		fl.point = 1;
		if (fl.set[++j] == '*')
			fl = treat_star(args, fl, &j);
		while (fl.set[j] != '\0' && ft_strchr_01(DIGITS, fl.set[j]))
			fl.precision = 10 * fl.precision + fl.set[j++] - '0';
	}
	return (fl);
}

static void		get_fspecs(va_list args, const char *s, int *lens)
{
	t_flags	fl;
	int		j;

	j = 0;
	while (ft_strchr_01(ALL_FL, s[*i]))
		fl.set[j++] = s[(*i)++];
	fl.set[j] = '\0';
	if (ft_strchr_01(FSPECS, s[*i]))
	{
		fl.spe_c = s[(*i)++];
		fl.minus = ft_strchr_01(fl.set, '-');
		fl.space = ft_strchr_01(fl.set, ' ');
		fl.width = 0;
		fl.point = 0;
		fl.precision = 0;
		fl.pad_c = ' ';
		fl = treat_flags(args, fl);
		treat_spec(args, lens, fl);
	}
}

int				ft_printf(const char *str, ...)
{
	va_list	args;
	int		lenS;

	va_start(args, s);
	lenS = 0;

	while (*s != '\0')
	{
		if (*s != '%')
			lenS += write(1, &s, 1);
		else
		{
			s++;
			get_fspecs(args, s, &lenS);
		}
	}
	va_end(args);
	return (lenS);
}
