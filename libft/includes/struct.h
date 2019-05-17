/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 16:57:47 by efischer          #+#    #+#             */
/*   Updated: 2019/05/17 14:14:44 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_file
{
	char			*rest;
	char			*cur;
	int				fd;
}					t_file;

typedef	struct		s_dir
{
	long long int	size;
	char			*name;
	char			*mode;
	char			*uid;
	char			*gid;
	long int		link;
	char			time[13];
	char			type;
}					t_dir;

#endif
