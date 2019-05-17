/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:12:02 by efischer          #+#    #+#             */
/*   Updated: 2019/04/11 18:18:04 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup_free(char *s1, size_t n)
{
	char	*cpy;

	cpy = ft_strndup(s1, n);
	ft_strdel(&s1);
	return (cpy);
}
