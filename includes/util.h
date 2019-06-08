/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:06:14 by efischer          #+#    #+#             */
/*   Updated: 2019/06/08 15:06:47 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "ft_ls.h"

void	ft_sort(t_list **lst, uint16_t flags);
void	ft_format_s_link(t_dir *dir_info);
void	ft_free_dir_info(t_dir *dir);
void	ft_free_struct_list(void *content, size_t content_size);

#endif
