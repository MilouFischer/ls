# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efischer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 15:49:28 by efischer          #+#    #+#              #
#    Updated: 2019/05/18 17:46:19 by efischer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

#=====================================HEAD======================================

IFLAGS += -I
INCLUDES += includes/
LIBINCLUDES += libft/includes/
HEAD += ft_ls.h 

#=====================================PATH======================================

PATHO += objs/
PATHI += $(INCLUDES)
PATHLIB += libft/

#===================================COMPILE=====================================

CC = gcc
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
DFLAGS += $(CFLAGS)
DFLAGS += -fsanitize=address,undefined
DFLAGS += -g3
COMPILE = $(CC) -c

#=====================================SRCS======================================

SRCS += ft_ls.c
SRCS += ft_get_dir_info.c
SRCS += ft_merge_sort.c

#=====================================OBJS======================================

OBJS = $(patsubst %.c, $(PATHO)%.o, $(SRCS))

LIBFT = $(PATHLIB)libft.a

vpath %.c srcs/
vpath %.h $(PATHI)

vpath %$(INCLUDES) $(IFLAGS)

all: $(NAME)

$(NAME): $(LIBFT) $(PATHO) $(OBJS) $(HEAD)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT) -o $@

$(OBJS): $(PATHO)%.o: %.c
	$(COMPILE) $(CFLAGS) $< $(IFLAGS) $(INCLUDES) $(IFLAGS) $(LIBINCLUDES) -o $@

$(LIBFT):
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

.PHONY: all clean fclean re
