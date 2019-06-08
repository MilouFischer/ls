/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:28:16 by efischer          #+#    #+#             */
/*   Updated: 2019/06/08 15:01:24 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <string.h>
# include <errno.h>
# include <stdint.h>
# include <sys/ioctl.h>
# include "libft.h"
# include "struct.h"
# include "directories.h"
# include "flags.h"
# include "get_dir_info.h"
# include "manage_input.h"
# include "mode_time.h"
# include "print_column.h"
# include "ls_print.h"
# include "sort_list.h"
# include "util.h"

# define SIX_MONTHS		15768000
# define HIDE_TOTAL		0
# define PRINT_TOTAL	1

# define FLAG_L			0x001
# define FLAG_A			0x002
# define FLAG_REV		0x004
# define FLAG_T			0x008
# define FLAG_R			0x010
# define FLAG_G			0x020
# define FLAG_D			0x040
# define FLAG_1			0x080
# define FLAG_N			0x100
# define FLAG_S			0x200

# define OTH_X			0x001
# define OTH_W			0x002
# define OTH_R			0x004
# define GRP_X			0x008
# define GRP_W			0x010
# define GRP_R			0x020
# define USR_X			0x040
# define USR_W			0x080
# define USR_R			0x100
# define STICKY_BIT		0x200
# define SET_GID		0x400
# define SET_UID		0x800

# define TYPE_P			0x1
# define TYPE_C			0x2
# define TYPE_D			0x4
# define TYPE_B			0x6
# define TYPE_F			0x8
# define TYPE_L			0xA
# define TYPE_S			0xC

#endif
