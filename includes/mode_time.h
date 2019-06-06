/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_time.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:58:18 by efischer          #+#    #+#             */
/*   Updated: 2019/06/06 16:00:36 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODE_TIME_H
# define MODE_TIME_H

# include "ft_ls.h"

void	ft_get_mode(int nb_mode, t_dir *dir_info);
void	ft_get_type(int nb_mode, t_dir *dir_info);
void	ft_get_time(const char *brut_tm, t_dir *dir_info);

#endif
