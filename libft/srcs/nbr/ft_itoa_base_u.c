/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 12:07:09 by efischer          #+#    #+#             */
/*   Updated: 2019/03/12 12:07:12 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_u(unsigned long long nb, int base)
{
	size_t	len;
	char	*str;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_intlen_u(nb, base);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	str[len--] = '\0';
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
