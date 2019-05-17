/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:58:04 by efischer          #+#    #+#             */
/*   Updated: 2019/04/18 16:38:45 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_manage_unicode_char(va_list *arg, t_flag *flag)
{
	wchar_t	*ws;
	char	*s;

	if (!(ws = (wchar_t*)malloc(sizeof(wchar_t) * 2)))
		return (NULL);
	ws[0] = va_arg(*arg, unsigned int);
	ws[1] = '\0';
	if (!ws[0])
	{
		if (flag->width && !flag->min)
			flag->width--;
		flag->null = 1;
		s = ft_strdup("\0");
	}
	else
		s = ft_putunicode(ws);
	free(ws);
	if (!s)
	{
		flag->exit = 1;
		return (NULL);
	}
	if (flag->width)
		s = ft_width('C', s, flag);
	return (s);
}

static int		ft_count_byte(char *s, t_flag *flag)
{
	char	*tmp;
	int		i;
	int		nb_byte;
	int		len;

	i = 0;
	len = 0;
	while (flag->precision > 0)
	{
		tmp = ft_itoa_base((unsigned char)s[i], 2);
		nb_byte = 0;
		if ((unsigned int)s[i] > 128)
			while (tmp[nb_byte] == '1')
				nb_byte++;
		if (nb_byte == 0)
			nb_byte = 1;
		if ((flag->precision -= nb_byte) >= 0)
		{
			len += nb_byte;
			i += nb_byte;
		}
		ft_strdel(&tmp);
	}
	return (len);
}

static char		*ft_unicode_str_precision(char *s, t_flag *flag)
{
	size_t	len;
	char	*format;

	len = ft_count_byte(s, flag);
	if (len == 0)
		format = ft_strdup("");
	else
		format = ft_strndup(s, len);
	ft_strdel(&s);
	return (format);
}

static char		*ft_unicode_str_width(char *s, t_flag *flag)
{
	int		len;
	char	*tmp;
	char	c;

	len = ft_strlen(s);
	if (len < flag->width)
	{
		len = flag->width - len;
		if (!(tmp = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		c = flag->zero ? '0' : ' ';
		tmp[len--] = '\0';
		while (len)
			tmp[len--] = c;
		tmp[len] = c;
		if (flag->min)
			s = ft_join_free(s, tmp, 3);
		else
			s = ft_join_free(tmp, s, 3);
	}
	return (s);
}

char			*ft_manage_unicode_str(va_list *arg, t_flag *flag)
{
	wchar_t	*ws;
	char	*s;

	if (!(ws = va_arg(*arg, wchar_t*)))
		s = ft_strdup("(null)");
	else
		s = ft_putunicode(ws);
	if (!s)
	{
		flag->exit = 1;
		return (NULL);
	}
	if (flag->precision >= 0)
		s = ft_unicode_str_precision(s, flag);
	if (flag->width)
		s = ft_unicode_str_width(s, flag);
	return (s);
}
