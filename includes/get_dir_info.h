/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir_info.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:52:07 by efischer          #+#    #+#             */
/*   Updated: 2019/06/08 13:15:17 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_DIR_INFO_H
# define GET_DIR_INFO_H

# include "ft_ls.h"

void	ft_get_padding(t_padding *padding, t_dir *dir_info);
void	ft_get_main_info(t_dir *dir_info, char *name, char *path,
				struct stat stat);
void	ft_get_other_info(t_dir *dir_info, struct stat stat);
int		ft_get_dir_info(char *path, char *name, t_dir *dir_info,
				uint16_t flags);

#endif
