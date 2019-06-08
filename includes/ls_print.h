/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 14:37:30 by efischer          #+#    #+#             */
/*   Updated: 2019/06/08 14:37:38 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_PRINT_H
# define LS_PRINT_H

# include "ft_ls.h"

char	*ft_print_color(t_dir *dir, t_padding *padding, uint16_t flags);
void	ft_print_dir_info(t_dir *dir, t_padding *padding, uint16_t flags);
void	ft_printlist(t_list *lst, t_padding *padding, uint16_t flags,
				int print);

#endif
