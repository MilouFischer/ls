/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 11:28:14 by efischer          #+#    #+#             */
/*   Updated: 2019/04/19 16:01:03 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_manage_str(char c, va_list *arg, t_flag *flag)
{
	flag->plus = 0;
	if (c == 'C' || (flag->l && (c == 'c')))
		return (ft_manage_unicode_char(arg, flag));
	else if (c == 'S' || (flag->l && (c == 's')))
		return (ft_manage_unicode_str(arg, flag));
	else if (c == 'c')
		return (ft_manage_c(arg, flag));
	else if (c == 's')
		return (ft_manage_s(arg, flag));
	else
		return (ft_manage_p(arg, flag));
}

static char		*ft_manage_conv(char c, va_list *arg, t_flag *flag)
{
	char	*str;
	double	f;

	if (c == 'f' || c == 'F')
	{
		f = va_arg(*arg, double);
		str = ft_printfloat(f);
	}
	else if (flag->l || flag->ll || flag->j || flag->z || c == 'D' || c == 'O'
	|| c == 'U')
		str = ft_long_diouxx(c, arg, flag);
	else
		str = ft_diouxx(c, arg, flag);
	if ((c == 'x' || c == 'X') && flag->sharp && flag->width
	&& flag->precision == -1)
		flag->width -= 2;
	return (str);
}

char			*ft_diouxxf(char c, va_list *arg, t_flag *flag)
{
	char	*format;

	format = ft_manage_conv(c, arg, flag);
	if (*format == '-')
	{
		flag->plus = 0;
		flag->space = 0;
	}
	if (flag->precision == -1 && (c == 'f' || c == 'F'))
		format = ft_round(format, 6);
	if (flag->precision >= 0 || flag->width)
	{
		if (flag->precision >= 0)
			format = ft_precision(c, format, flag);
		if (flag->width)
			format = ft_width(c, format, flag);
		else if (flag->space)
			format = ft_join_free(" ", format, 2);
		else if (flag->plus)
			format = ft_join_free("+", format, 2);
	}
	else
		format = ft_apply_flag(c, format, flag);
	return (c == 'X' ? ft_strupcase(format) : format);
}
