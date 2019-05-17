/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 15:21:04 by efischer          #+#    #+#             */
/*   Updated: 2019/05/14 15:22:34 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_STR_H
# define IS_STR_H

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isblank(int c);
int		ft_iscntrl(int c);
int		ft_isgraph(int c);
int		ft_islower(int c);
int		ft_isspace(int c);
int		ft_isupper(int c);
int		ft_isxdigit(int c);
int		ft_str_is_alpha(const char *str);
int		ft_str_is_lowercase(const char *str);
int		ft_str_is_numeric(const char *str);
int		ft_str_is_printable(const char *str);
int		ft_str_is_uppercase(const char *str);

#endif
