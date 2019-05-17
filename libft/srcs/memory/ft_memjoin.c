/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:57:37 by efischer          #+#    #+#             */
/*   Updated: 2019/04/11 18:57:40 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(void *s1, void *s2, size_t len1, size_t len2)
{
	void				*dst;
	unsigned char		*tmp_dst;
	unsigned const char	*tmp_src;
	size_t				len;
	size_t				i;

	len = len1 + len2;
	dst = ft_memalloc(len);
	dst = ft_memcpy(dst, s1, len1);
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned const char *)s2;
	i = len1;
	while (i < len)
		tmp_dst[i++] = *tmp_src++;
	return (tmp_dst);
}
