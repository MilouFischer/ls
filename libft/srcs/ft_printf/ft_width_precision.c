/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:36:23 by efischer          #+#    #+#             */
/*   Updated: 2019/04/19 15:49:48 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_process_precision(char *format, int len)
{
	char	c;
	char	*str;

	c = '0';
	if (!*format)
		return (format);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
	{
		ft_strdel(&format);
		return (NULL);
	}
	str[len--] = '\0';
	while (len > -1)
		str[len--] = c;
	if (*format == '-')
	{
		str[0] = '-';
		format[0] = '0';
	}
	format = ft_join_free(str, format, 3);
	return (format);
}

char			*ft_precision(char conv, char *format, t_flag *flag)
{
	int		len;

	if (!flag->precision && *format == '0' && !((conv == 'o' || conv == 'O')
	&& flag->sharp))
	{
		ft_strdel(&format);
		return (ft_strdup(""));
	}
	len = flag->precision - ft_strlen(format);
	if (*format == '-')
		len++;
	if (conv == 'f' || conv == 'F')
	{
		format = ft_round(format, flag->precision);
	}
	else if (len > 0 && conv != 's')
		format = ft_process_precision(format, len);
	if (flag->sharp && (conv == 'x' || conv == 'X'))
	{
		format = ft_join_free("0x", format, 2);
		flag->sharp = 0;
	}
	else if (conv == 's')
		format = ft_strndup_free(format, flag->precision);
	return (format);
}

static char		*ft_process_str(char *str, char x, char *format, t_flag *flag)
{
	if (flag->plus && flag->zero && !flag->min)
		str = ft_join_free("+", str, 2);
	if (flag->sharp && (x == 'x' || x == 'X') && flag->zero && !flag->min)
		str = ft_join_free("0x", str, 2);
	if (flag->space && flag->min && *format != '-')
		format = ft_join_free(" ", format, 2);
	else if (flag->space)
		str[0] = ' ';
	if (*format == '-' && flag->zero && !flag->min)
	{
		str[0] = '-';
		format[0] = '0';
	}
	if (flag->min && flag->null)
	{
		ft_strdel(&format);
		format = ft_memjoin("\0", str, 1, ft_strlen(str));
		ft_strdel(&str);
	}
	else if (flag->min)
		format = ft_join_free(format, str, 3);
	else
		format = ft_join_free(str, format, 3);
	return (format);
}

static char		*ft_process_width(int len, char *format, char x, t_flag *flag)
{
	char	*str;
	char	c;
	int		i;

	if (flag->plus)
		len--;
	c = '0';
	if (!(flag->zero && !flag->min))
	{
		c = ' ';
		if (flag->plus)
			format = ft_join_free("+", format, 2);
		if (flag->sharp && (x == 'x' || x == 'X'))
			format = ft_join_free("0x", format, 2);
	}
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
	{
		ft_strdel(&format);
		return (NULL);
	}
	while (i < len)
		str[i++] = c;
	str[i] = '\0';
	return (ft_process_str(str, x, format, flag));
}

char			*ft_width(char c, char *format, t_flag *flag)
{
	int		len;

	if (flag->space && flag->min && *format != '-')
		flag->width--;
	len = flag->width - ft_strlen(format);
	if (len > 0)
		format = ft_process_width(len, format, c, flag);
	else if (flag->plus)
		format = ft_join_free("+", format, 2);
	else if (flag->space && *format != '-')
		format = ft_join_free(" ", format, 2);
	else if (flag->sharp > 0 && (c == 'x' || c == 'X') && *format != '0')
		format = ft_join_free("0x", format, 2);
	return (format);
}
