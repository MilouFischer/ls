# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efischer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 15:49:28 by efischer          #+#    #+#              #
#    Updated: 2019/05/31 19:03:48 by efischer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

#=====================================HEAD======================================

INCLUDES += includes/
LIBINCLUDES += libft/includes/
HEAD += ft_ls.h
IFLAGS += -I

#=====================================PATH======================================

PATHO += objs/
PATHI += $(INCLUDES)
PATHLIB += libft/

#===================================COMPILE=====================================

CC = gcc
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
COMPILE = $(CC) -c

#=====================================SRCS======================================

SRCS += ft_ls.c
SRCS += directories.c
SRCS += get_dir_info.c
SRCS += sort.c
SRCS += util.c
SRCS += flags.c
SRCS += manage_input.c
SRCS += mode_time.c
SRCS += print_column.c

#=====================================OBJS======================================

OBJS = $(patsubst %.c, $(PATHO)%.o, $(SRCS))

LIBFT = $(PATHLIB)libft.a

vpath %.c srcs/
vpath %.h $(PATHI)

all: $(NAME)

$(NAME): $(LIBFT) $(PATHO) $(OBJS) $(HEAD)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT) -o $@

$(OBJS): $(PATHO)%.o: %.c
	$(COMPILE) $(CFLAGS) $< $(IFLAGS) $(INCLUDES) $(IFLAGS) $(LIBINCLUDES) -o $@

$(LIBFT): FORCE
	make -C $(PATHLIB)

$(PATHO):
	mkdir $@

clean:
	$(RM) $(OBJS)
	$(RM) -R $(PATHO)
	make clean -C $(PATHLIB)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(PATHLIB)

re: fclean all

FORCE:

.PHONY: all clean fclean re FORCE
