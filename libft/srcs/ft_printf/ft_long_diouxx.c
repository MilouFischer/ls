/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_diouxx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:59:12 by efischer          #+#    #+#             */
/*   Updated: 2019/04/11 15:10:10 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_manage_long_o(va_list *arg, t_flag *flag)
{
	unsigned long	u;
	char			*s;

	(void)flag;
	u = va_arg(*arg, unsigned long);
	s = ft_itoa_base_u(u, 8);
	if (flag->sharp && u)
		s = ft_join_free("0", s, 2);
	return (s);
}

static char		*ft_manage_long_diu(char c, va_list *arg, t_flag *flag)
{
	long long int	nb;
	unsigned long	u;

	if (c == 'd' || c == 'D' || c == 'i')
	{
		nb = va_arg(*arg, long long int);
		return (ft_itoa_base(nb, 10));
	}
	else
	{
		u = va_arg(*arg, unsigned long);
		if (!u)
			flag->sharp = 0;
		return (ft_itoa_base_u(u, 10));
	}
}

char			*ft_long_diouxx(char c, va_list *arg, t_flag *flag)
{
	unsigned long	u;
	char			*s;

	if (c == 'd' || c == 'D' || c == 'i' || c == 'u' || c == 'U')
		return (ft_manage_long_diu(c, arg, flag));
	else if (c == 'o' || c == 'O')
		return (ft_manage_long_o(arg, flag));
	else if (c == 'x' || c == 'X')
	{
		u = va_arg(*arg, unsigned long);
		s = ft_itoa_base_u(u, 16);
		if (*s == '0')
			flag->sharp = 0;
		return (s);
	}
	else
		return (NULL);
}
