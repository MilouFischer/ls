/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_unicode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:47:02 by efischer          #+#    #+#             */
/*   Updated: 2019/04/18 14:42:54 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_two_byte(unsigned int c)
{
	unsigned int	nb;

	nb = 6;
	c >>= 6;
	if (c % 2 || !((c >> 1) % 2))
		return (1);
	c >>= 7;
	if (c != nb)
		return (1);
	return (0);
}

static int	ft_three_byte(unsigned int c)
{
	unsigned int	nb;

	nb = 14;
	c >>= 6;
	if (c % 2 || !((c >> 1) % 2))
		return (1);
	c >>= 8;
	if (c % 2 || !((c >> 1) % 2))
		return (1);
	c >>= 6;
	if (c != nb)
		return (1);
	return (0);
}

static int	ft_four_byte(unsigned int c)
{
	unsigned int	nb;

	nb = 30;
	c >>= 6;
	if (c % 2 || !((c >> 1) % 2))
		return (1);
	c >>= 8;
	if (c % 2 || !((c >> 1) % 2))
		return (1);
	c >>= 8;
	if (c % 2 || !((c >> 1) % 2))
		return (1);
	c >>= 5;
	if (c != nb)
		return (1);
	return (0);
}

int			ft_check_unicode(char *s, unsigned int c)
{
	int				len;

	len = ft_strlen(s);
	ft_strdel(&s);
	if (len != 16 && len != 24 && len != 32)
		return (1);
	if (len == 16)
		return (ft_two_byte(c));
	if (len == 24)
		return (ft_three_byte(c));
	else
		return (ft_four_byte(c));
}
