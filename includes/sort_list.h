/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:03:48 by efischer          #+#    #+#             */
/*   Updated: 2019/06/06 17:51:31 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_LIST_H
# define SORT_LIST_H

# include "ft_ls.h"

void	ft_sort(t_list **lst, uint16_t flags);
void	ft_sort_input(t_list **lst1, t_list **lst2, t_list **head);
void	ft_sort_name(t_list **lst1, t_list **lst2, t_list **head);
void	ft_sort_time(t_list **lst1, t_list **lst2, t_list **head);
void	ft_sort_rev(t_list **lst1, t_list **lst2, t_list **head);

#endif
