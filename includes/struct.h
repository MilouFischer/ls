/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:43:41 by efischer          #+#    #+#             */
/*   Updated: 2019/06/06 16:25:50 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "ft_ls.h"

typedef	struct		s_dir
{
	char		*size;
	char		*name;
	char		*uid;
	char		*gid;
	char		*link;
	char		*major;
	char		*minor;
	char		*path;
	char		*s_link;
	char		mode[10];
	char		time[13];
	char		type;
	int			nb_mode;
	size_t		nb_blocks;
	int64_t		brut_time;
}					t_dir;

typedef struct		s_padding
{
	size_t			size;
	size_t			name;
	size_t			uid;
	size_t			gid;
	size_t			link;
	size_t			type;
	size_t			major;
	size_t			minor;
	size_t			total;
	size_t			ws_col;
}					t_padding;

#endif
