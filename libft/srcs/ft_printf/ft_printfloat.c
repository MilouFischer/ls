/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:58:01 by efischer          #+#    #+#             */
/*   Updated: 2019/04/18 18:27:12 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	**ft_init_pm(char **tab)
{
	tab[0] = PM1;
	tab[1] = PM2;
	tab[2] = PM3;
	tab[3] = PM4;
	tab[4] = PM5;
	tab[5] = PM6;
	tab[6] = PM7;
	tab[7] = PM8;
	tab[8] = PM9;
	tab[9] = PM10;
	tab[10] = PM11;
	tab[11] = PM12;
	tab[12] = PM13;
	tab[13] = PM14;
	tab[14] = PM15;
	tab[15] = PM16;
	tab[16] = PM17;
	tab[17] = PM18;
	tab[18] = PM19;
	tab[19] = PM20;
	tab[20] = PM21;
	tab[21] = PM22;
	tab[22] = PM23;
	tab[23] = 0;
	return (tab);
}

static void	ft_init_tab(char *tab)
{
	int	i;

	i = 0;
	while (i < 23)
		tab[i++] = '0';
	tab[i] = '\0';
}

static char	*ft_add(char *s1, char *s2)
{
	int		i;
	int		nb;
	int		ret;

	i = 0;
	ret = 0;
	while (s2[i + 1])
		i++;
	while (i > -1)
	{
		nb = s1[i] - '0' + s2[i] - '0';
		if (ret)
		{
			nb += 1;
			ret = 0;
		}
		if (nb >= 10)
		{
			nb -= 10;
			ret = 1;
		}
		s1[i] = nb + '0';
		i--;
	}
	return (s1);
}

static char	*ft_print_mentice(char *str)
{
	char	*tab;
	char	*pm[24];
	int		i;

	i = 0;
	ft_init_pm(pm);
	if (!(tab = (char*)malloc(sizeof(char) * 12)))
		return (NULL);
	while (i < 11)
		tab[i++] = '0';
	tab[i] = '\0';
	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			tab = ft_add(tab, pm[i]);
		i++;
	}
	return (tab);
}

char		*ft_printfloat(double f)
{
	long long	nb;
	int			i;
	char		tab[24];
	char		*str;

	i = 0;
	ft_init_tab(tab);
	nb = (long long)f;
	str = ft_itoa(nb);
	if (f < 0)
	{
		f *= -1;
		nb *= -1;
	}
	str = ft_join_free(str, ".", 1);
	f -= nb;
	while (f && i < 23)
	{
		f *= 2;
		tab[i++] = (int)f + '0';
		f -= (int)f;
	}
	str = ft_join_free(str, ft_print_mentice(tab), 3);
	return (str);
}
