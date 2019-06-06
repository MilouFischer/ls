/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directories.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:46:28 by efischer          #+#    #+#             */
/*   Updated: 2019/06/06 15:49:52 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIRECTORIES_H
# define DIRECTORIES_H

# include "ft_ls.h"

void	ft_open_dir(char *path, uint16_t flags);
void	ft_directories(t_list *lst_dir, uint16_t flags);

#endif
