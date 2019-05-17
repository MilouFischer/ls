/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_unicode.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:31:00 by efischer          #+#    #+#             */
/*   Updated: 2019/04/11 18:31:03 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_one_byte(unsigned int nb)
{
	unsigned int	c;
	unsigned int	tmp;

	c = 49280;
	c |= nb % 64;
	tmp = nb / 64;
	tmp <<= 8;
	c |= tmp;
	return (c);
}

static unsigned int	ft_two_byte(unsigned int nb)
{
	unsigned int	c;
	unsigned int	tmp;

	c = 14712960;
	c |= nb % 64;
	tmp = nb / 4096;
	tmp <<= 8;
	tmp |= nb % 4096 / 64;
	tmp <<= 8;
	c |= tmp;
	return (c);
}

static unsigned int	ft_three_byte(unsigned int nb)
{
	unsigned int	c;
	unsigned int	tmp;

	c = 4034953344;
	c |= nb % 64;
	tmp = nb / 262144;
	tmp <<= 8;
	tmp |= nb % 262144 / 4096;
	tmp <<= 8;
	tmp |= nb % 4096 / 64;
	tmp <<= 8;
	c |= tmp;
	return (c);
}

unsigned int		ft_convert_to_unicode(unsigned int c)
{
	if (c < 2048)
		return (ft_one_byte(c));
	else if (c <= 65535)
		return (ft_two_byte(c));
	else if (c <= 2097152)
	{
		return (ft_three_byte(c));
	}
	return (0);
}
