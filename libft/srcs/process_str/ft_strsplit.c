/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:31:48 by efischer          #+#    #+#             */
/*   Updated: 2018/11/13 16:46:26 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill_tab(char **tab, char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	size_t			len;

	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			i = 0;
			len = 0;
			while (s[len] != c && s[len])
				len++;
			if (!(tab[j] = (char *)malloc(sizeof(char) * (len + 1))))
			{
				tab = NULL;
				return ;
			}
			while (i < len)
				tab[j][i++] = *s++;
			tab[j++][i] = '\0';
		}
		else
			s++;
	}
}

char		**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;
	char			**tab;

	i = 0;
	count = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	if (!(tab = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	ft_fill_tab(tab, s, c);
	tab[count] = 0;
	return (tab);
}
