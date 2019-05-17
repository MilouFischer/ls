/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 12:04:14 by efischer          #+#    #+#             */
/*   Updated: 2019/04/19 16:01:02 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static char		*ft_p_precision(char *s, t_flag *flag)
{
	int		len;
	char	*tmp;

	if ((len = flag->precision - ft_strlen(s)) > 0)
	{
		if (!(tmp = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		tmp[len--] = '\0';
		while (len >= 0)
			tmp[len--] = '0';
		if (flag->min)
			s = ft_join_free(s, tmp, 3);
		else
			s = ft_join_free(tmp, s, 3);
	}
	return (s);
}

static char		*ft_p_width(void *p, char *s, t_flag *flag)
{
	int		len;
	char	*tmp;
	char	c;

	if ((len = flag->width - ft_strlen(s)) > 0)
	{
		if (!(tmp = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		c = ' ';
		if (p == 0 && flag->zero)
		{
			c = '0';
			flag->min = 1;
		}
		tmp[len--] = '\0';
		while (len >= 0)
			tmp[len--] = c;
		if (flag->min)
			s = ft_join_free(s, tmp, 3);
		else
			s = ft_join_free(tmp, s, 3);
	}
	return (s);
}*/

char			*ft_manage_p(va_list *arg, t_flag *flag)
{
	void	*p;
	char	*s;
	char	*tmp;

	p = va_arg(*arg, void*);
	if (flag->precision == 0)
		s = ft_strdup("");
	else
		s = ft_itoa_base_u((unsigned long)p, 16);
	if (flag->precision)
		s = ft_precision('p', s, flag);
	s = ft_join_free("0x", s, 2);
	if (flag->width)
		s = ft_width('p', s, flag);
	tmp = s;
	s = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (s);
}
