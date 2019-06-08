/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:06:14 by efischer          #+#    #+#             */
/*   Updated: 2019/06/08 13:15:21 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "ft_ls.h"

void	ft_format_s_link(t_dir *dir_info);
void	ft_free_dir_info(t_dir *dir);
void	ft_free_struct_list(void *content, size_t content_size);
char	*ft_print_color(t_dir *dir, t_padding *padding, uint16_t flags);
void	ft_print_dir_info(t_dir *dir, t_padding *padding, uint16_t flags);
void	ft_printlist(t_list *lst, t_padding *padding, uint16_t flags,
				int print);

#endif
