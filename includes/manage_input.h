/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_input.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:55:45 by efischer          #+#    #+#             */
/*   Updated: 2019/06/06 15:57:26 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGE_INPUT_H
# define MANAGE_INPUT_H

# include "ft_ls.h"

void	ft_manage_input(char **av, t_list **lst_dir,
				t_list **lst_file, uint16_t flags);

#endif
