/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:46:57 by efischer          #+#    #+#             */
/*   Updated: 2019/03/12 12:19:52 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_fill_str(char *str, size_t len, long long int nb,
				long long int base)
{
	while (nb)
	{
		if (nb % base < 10)
			str[len--] = nb % base + '0';
		else
			str[len--] = (nb - 10) % base + 'a';
		nb /= base;
	}
	return (str);
}

char			*ft_itoa_base(long long int nb, long long int base)
{
	size_t	len;
	char	*str;

	if (base < 2 || base > 16)
		return (NULL);
	if (nb < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	len = ft_intlen(nb, base);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		str[0] = '0';
	str[len--] = '\0';
	str = ft_fill_str(str, len, nb, base);
	return (str);
}
