/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:15:18 by efischer          #+#    #+#             */
/*   Updated: 2019/05/14 15:17:26 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NBR_H
# define NBR_H

int			ft_atoi(const char	*str);
long long	ft_atoi_base(char *str, int base);
char		*ft_itoa(long long n);
char		*ft_itoa_base(long long int nb, long long int base);
char		*ft_itoa_base_u(unsigned long long nb, int base);
int			ft_power(int nbr, int pow);
int			ft_factorial(int nb);
size_t		ft_intlen(long long nb, int base);
size_t		ft_intlen_u(unsigned long long nb, int base);

#endif
