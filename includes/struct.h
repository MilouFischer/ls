/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:26:04 by efischer          #+#    #+#             */
/*   Updated: 2019/05/21 17:29:13 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef	struct		s_dir
{
	char			*size;
	char			*name;
	char			mode[10];
	char			*uid;
	char			*gid;
	char			*link;
	char			time[13];
	char			type;
	unsigned long	brut_time;
}					t_dir;

typedef struct	s_padding
{
	size_t		size;
	size_t		name;
	size_t		uid;
	size_t		gid;
	size_t		link;
	size_t		type;
}				t_padding;

#endif
