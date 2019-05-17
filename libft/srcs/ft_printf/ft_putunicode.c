/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 12:32:14 by efischer          #+#    #+#             */
/*   Updated: 2019/04/18 16:14:43 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_init_str(char *s, int n)
{
	int		i;

	i = 0;
	while (i < n)
		s[i++] = '\0';
}

static char		*ft_print_unicode(char *s)
{
	char	unicode[5];
	char	tmp[3];
	char	*str;
	int		i;
	int		tmp_i;

	i = 0;
	tmp_i = 0;
	ft_init_str(unicode, 5);
	while (*s && i < 5)
	{
		tmp[tmp_i++] = *s;
		if (tmp_i == 2)
		{
			tmp[tmp_i] = '\0';
			unicode[i++] = ft_atoi_base(tmp, 16);
			tmp_i = 0;
			ft_init_str(tmp, 3);
		}
		s++;
	}
	str = ft_strdup(unicode);
	return (str);
}

size_t			ft_wchar_tlen(wchar_t *ws)
{
	size_t	len;

	len = 0;
	while (ws[len])
		len++;
	return (len);
}

char			*ft_putunicode(wchar_t *ws)
{
	char			*str;
	char			*tmp;
	unsigned int	c;

	str = NULL;
	if (!*ws)
		return (ft_strdup("\0"));
	while (*ws)
	{
		c = (wchar_t)*ws;
		if ((c >= 0xD800 && c <= 0xDFFF) || c > 0x10FFFF)
		{
			ft_strdel(&str);
			return (NULL);
		}
		if (*ws > 127 && ft_check_unicode(ft_itoa_base(*ws, 2), *ws))
			c = ft_convert_to_unicode(*ws);
		tmp = ft_itoa_base_u(c, 16);
		str = ft_join_free(str, ft_print_unicode(tmp), 3);
		ft_strdel(&tmp);
		ws++;
	}
	return (str);
}
