/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:00:27 by efischer          #+#    #+#             */
/*   Updated: 2018/11/13 15:08:21 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	char			*tmp;
	size_t			n;

	tmp = (char *)haystack;
	if (!*needle)
		return (tmp);
	while (*tmp && len)
	{
		i = 0;
		n = len;
		if (*tmp == needle[i])
		{
			while (tmp[i] == needle[i] && n && needle[i])
			{
				i++;
				n--;
			}
			if (!needle[i])
				return (tmp);
		}
		tmp++;
		len--;
	}
	return (0);
}
