/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:29:10 by efischer          #+#    #+#             */
/*   Updated: 2018/11/14 14:33:05 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char			*cpy;
	unsigned int	i;

	i = 0;
	if (!(cpy = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (n && s1[i])
	{
		cpy[i] = s1[i];
		i++;
		n--;
	}
	cpy[i] = '\0';
	return (cpy);
}
