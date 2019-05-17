/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:35:57 by efischer          #+#    #+#             */
/*   Updated: 2019/02/22 17:49:20 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_matrix(int **matrix, unsigned int x, unsigned int y)
{
	unsigned int	i;
	unsigned int	j;

	if (!matrix)
		return ;
	j = 0;
	while (j < y && matrix[j])
	{
		i = 0;
		while (i < x && matrix[j][i])
		{
			ft_putnbr(matrix[j][i++]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
		j++;
	}
}
