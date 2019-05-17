/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:58:40 by efischer          #+#    #+#             */
/*   Updated: 2019/04/18 14:47:15 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flag(t_flag *flag)
{
	flag->width = 0;
	flag->precision = -1;
	flag->sharp = 0;
	flag->zero = 0;
	flag->min = 0;
	flag->space = 0;
	flag->plus = 0;
	flag->dot = 0;
	flag->h = 0;
	flag->hh = 0;
	flag->l = 0;
	flag->ll = 0;
	flag->j = 0;
	flag->z = 0;
	flag->null = 0;
	flag->exit = 0;
}

void	ft_manage_flag(char c, t_flag *flag)
{
	if (c == '#')
		flag->sharp = 1;
	else if (c == '0' && !flag->min)
		flag->zero = 1;
	else if (c == '+')
	{
		flag->plus = 1;
		flag->space = 0;
	}
	else if (c == '-')
		flag->min = 1;
	else if (c == '.')
	{
		flag->dot = 1;
		flag->precision = 0;
	}
	else if (c == ' ' && !flag->plus)
		flag->space = 1;
}

void	ft_manage_conv_flag(char c, t_flag *flag)
{
	if (c == 'l' && flag->l)
		flag->ll = 1;
	else if (c == 'l')
		flag->l = 1;
	else if (c == 'h' && flag->h)
		flag->hh = 1;
	else if (c == 'h')
		flag->h = 1;
	else if (c == 'j')
		flag->j = 1;
	else if (c == 'z')
		flag->z = 1;
}

void	ft_precision_width(va_list *arg, t_flag *flag, char **s)
{
	int		nb;

	if (**s == '*')
	{
		nb = va_arg(*arg, int);
		if (nb < 0 && !flag->dot)
		{
			flag->min = 1;
			nb *= -1;
		}
	}
	else
	{
		nb = ft_atoi(*s);
		while (ft_isdigit(**s))
			(*s)++;
		(*s)--;
	}
	if (flag->dot)
		flag->precision = nb;
	else
		flag->width = nb;
	flag->dot = 0;
}

char	*ft_apply_flag(char c, char *format, t_flag *flag)
{
	if (flag->sharp && *format != '0' && (c == 'x' || c == 'X' || c == 'o'
	|| c == 'O'))
	{
		if (c == 'x' || c == 'X')
			format = ft_join_free("0x", format, 2);
		else if (c == 'o' || c == 'O')
			format = ft_join_free("0", format, 2);
	}
	else if (c == 'o' || c == 'O')
		return (format);
	else if (flag->plus)
		format = ft_join_free("+", format, 2);
	else if (flag->space)
		format = ft_join_free(" ", format, 2);
	return (format);
}
