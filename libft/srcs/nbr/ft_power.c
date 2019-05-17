/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:58:21 by efischer          #+#    #+#             */
/*   Updated: 2018/11/13 18:17:44 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int nbr, int pow)
{
	long	res;

	res = 1;
	if (pow == 0)
		return (0);
	while (pow)
	{
		if (res * nbr > 2147483647)
			return (0);
		res *= nbr;
		pow--;
	}
	return ((int)res);
}
