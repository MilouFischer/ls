/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:37:34 by efischer          #+#    #+#             */
/*   Updated: 2018/11/14 17:58:22 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	unsigned int	i;

	i = 1;
	if (ft_islower(str[0]))
		str[0] = (char)ft_toupper(str[0]);
	while (str[i + 1])
	{
		if (ft_islower(str[i]) && !ft_isalnum(str[i - 1]))
			str[i] = (char)ft_toupper(str[i]);
		else if (ft_isupper(str[i]) && ft_isalnum(str[i - 1]))
			str[i] = (char)ft_tolower(str[i]);
		i++;
	}
	return (str);
}
