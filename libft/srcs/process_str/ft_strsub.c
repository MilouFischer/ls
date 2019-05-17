/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:53:20 by efischer          #+#    #+#             */
/*   Updated: 2018/11/09 16:07:46 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*part;

	i = 0;
	if (!s || !*s)
		return (NULL);
	if (!(part = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
		part[i++] = s[start++];
	part[i] = '\0';
	return (part);
}
