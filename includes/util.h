/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:18:57 by efischer          #+#    #+#             */
/*   Updated: 2019/05/21 17:34:38 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "ft_ls.h"

void	ft_free_dir_info(t_dir *dir_info);
void	ft_free_lst(t_list **lst);
void	ft_print_dir_info(t_dir *dir, t_padding *padding, uint8_t flags);
void	ft_printlist(t_list *lst, t_padding *padding, uint8_t flags);

#endif
