/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diouxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:59:06 by efischer          #+#    #+#             */
/*   Updated: 2019/04/11 18:48:20 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_manage_d(va_list *arg, t_flag *flag)
{
	int			nb;
	short		sh;
	char		c;

	nb = va_arg(*arg, int);
	if (flag->hh)
	{
		c = (char)nb;
		nb = c;
	}
	else if (flag->h)
	{
		sh = (short)nb;
		nb = sh;
	}
	return (ft_itoa(nb));
}

static char		*ft_manage_u(va_list *arg, char conv, int base, t_flag *flag)
{
	unsigned int		u;
	unsigned char		c;
	unsigned short		sh;
	char				*s;

	u = va_arg(*arg, unsigned int);
	if (flag->hh)
	{
		c = (unsigned char)u;
		u = c;
	}
	else if (flag->h)
	{
		sh = (unsigned short)u;
		u = sh;
	}
	s = ft_itoa_base_u(u, base);
	if (*s == '0' && (conv == 'x' || conv == 'X'))
		flag->sharp = 0;
	else if (flag->sharp && u && conv == 'o')
		s = ft_join_free("0", s, 2);
	return (s);
}

char			*ft_diouxx(char c, va_list *arg, t_flag *flag)
{
	if ((c == 'o' || c == 'u' || c == 'x' || c == 'X')
	&& (flag->space || flag->plus))
	{
		flag->space = 0;
		flag->plus = 0;
	}
	if (c == 'd' || c == 'i')
		return (ft_manage_d(arg, flag));
	else if (c == 'o')
		return (ft_manage_u(arg, c, 8, flag));
	else if (c == 'u')
		return (ft_manage_u(arg, c, 10, flag));
	else if (c == 'x' || c == 'X')
		return (ft_manage_u(arg, c, 16, flag));
	else if (c == 'b')
		return (ft_manage_u(arg, c, 2, flag));
	else
		return (NULL);
}
