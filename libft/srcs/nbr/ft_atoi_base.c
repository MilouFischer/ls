/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:30:35 by efischer          #+#    #+#             */
/*   Updated: 2019/04/11 18:30:38 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi_base(char *str, int base)
{
	long long	nb;

	nb = 0;
	if (base < 2 || base > 16)
		return (0);
	str = ft_strupcase(str);
	while (*str && (ft_isdigit(*str) || (*str >= 'A' && *str <= 'F')))
	{
		if (*str - '0' < 10)
			nb = *str++ - '0' + nb * base;
		else
			nb = *str++ - 'A' + 10 + nb * base;
	}
	return (nb);
}
