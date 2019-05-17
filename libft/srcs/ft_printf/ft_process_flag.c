/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:56:32 by efischer          #+#    #+#             */
/*   Updated: 2019/04/18 15:59:04 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_percent(char c, t_flag *flag)
{
	char	*format;

	format = ft_strdup("%");
	flag->plus = 0;
	if (flag->width)
		format = ft_width(c, format, flag);
	return (format);
}

static char	*ft_flag_error(char c, t_flag *flag)
{
	char	*format;
	char	*tmp;
	int		len;

	format = ft_strndup(&c, 1);
	if ((len = flag->width - ft_strlen(format)) > 0)
	{
		if (!(tmp = (char*)malloc(sizeof(char) * (len + 1))))
		{
			ft_strdel(&format);
			return (NULL);
		}
		tmp[len--] = '\0';
		while (len >= 0)
			tmp[len--] = ' ';
		if (flag->min)
			format = ft_join_free(format, tmp, 3);
		else
			format = ft_join_free(tmp, format, 3);
	}
	return (format);
}

static char	*ft_manage_z(char c, t_flag *flag)
{
	char	*s;

	s = ft_strdup("Z");
	if (flag->width)
		s = ft_width(c, s, flag);
	return (s);
}

static char	*ft_all_conv(char c, va_list *arg, t_flag *flag)
{
	if (c == 'c' || c == 'C' || c == 's' || c == 'S' || c == 'p')
		return (ft_manage_str(c, arg, flag));
	else if (c == 'd' || c == 'D' || c == 'i' || c == 'o' || c == 'O'
	|| c == 'u' || c == 'U' || c == 'x' || c == 'X' || c == 'f' || c == 'F'
	|| c == 'b')
	{
		if (flag->precision >= 0 && c != 'f' && c != 'F')
			flag->zero = 0;
		return (ft_diouxxf(c, arg, flag));
	}
	else
		return (ft_manage_z(c, flag));
}

char		*ft_process_flag(char **s, va_list *arg, t_flag *flag)
{
	(*s)++;
	while (**s)
	{
		if (**s == '#' || **s == '0' || **s == '-' || **s == '+' || **s == ' '
		|| **s == '.')
			ft_manage_flag(**s, flag);
		else if (**s == 'h' || **s == 'l' || **s == 'L' || **s == 'j'
		|| **s == 'z')
			ft_manage_conv_flag(**s, flag);
		else if ((**s >= '1' && **s <= '9') || **s == '*')
			ft_precision_width(arg, flag, s);
		else if (**s == 'c' || **s == 'C' || **s == 's' || **s == 'S'
		|| **s == 'p' || **s == 'd' || **s == 'D' || **s == 'i' || **s == 'o'
		|| **s == 'O' || **s == 'u' || **s == 'U' || **s == 'x' || **s == 'X'
		|| **s == 'f' || **s == 'F' || **s == 'b' || **s == 'Z')
			return (ft_all_conv(**s, arg, flag));
		else if (**s == '%')
			return (ft_percent(**s, flag));
		else
			return (ft_flag_error(**s, flag));
		(*s)++;
	}
	return (ft_strdup("\0"));
}
