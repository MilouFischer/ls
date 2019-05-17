/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:13:54 by efischer          #+#    #+#             */
/*   Updated: 2018/11/13 15:41:17 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*tmp_dst;
	unsigned const char	*tmp_src;
	unsigned char		stop;

	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned const char *)src;
	stop = (unsigned char)c;
	while (n)
	{
		*tmp_dst = *tmp_src;
		if ((unsigned char)*tmp_src == stop)
			return (++tmp_dst);
		tmp_dst++;
		tmp_src++;
		n--;
	}
	return (NULL);
}
