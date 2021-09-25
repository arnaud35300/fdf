# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    m                                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/25 05:23:48 by arguilla          #+#    #+#              #
#    Updated: 2021/09/25 05:50:49 by arguilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# [ VARIABLES ] #

SHELL			=	/bin/sh
NAME			=	fdf
RM				= 	/bin/rm -rf
MAKE			= 	make
LIBFT			= 	libft
MINILIBX		=	mlx_linux

# [ COLORS ] #

_RED			=	\e[31m
_GREEN			=	\e[32m
_YELLOW			=	\e[33m
_END			=	\e[0m
_BOLDGREEN  	=	\033[1m\033[32m

# [ COMPILATION VARIABLES ] #

CC				=	gcc
CFLAGS			=	-g -Wall -Wextra -Werror
LIBFT_INC		=	-I./libft -I./libft/char -I./libft/file -I./libft/int -I./libft/lst -I./libft/mem -I./libft/print -I./libft/str
MINILIBX_INC	=	-I./mlx_linux -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
INC				=

# [ SOURCES ]

SRCS				=	main.c\
					error.c\
					parser.c\
					free.c\

# [ OBJECTS ] #

OBJ			=	./objs
OBJS		=	$(addprefix $(OBJ)/, $(SRCS:.c=.o))

# [ PATH ] #

VPATH		=	includes:srcs:libft:mlx_linux:

# [ RULES ] #

all:		$(NAME)

$(NAME):	$(OBJS)
			$(MAKE) -s -C $(LIBFT)
			$(MAKE) -C  $(MINILIBX) all
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I./includes $(LIBFT_INC) $(PROG_INC) $(LIBFT)/libft.a $(MINILIBX_INC)

$(OBJ):
			mkdir -p $(OBJ)

$(OBJS):	| $(OBJ)

$(OBJ)/%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@ -I./includes $(LIBFT_INC) $(PROG_INC) -I./mlx_linux
clean:
			$(RM) $(OBJ)
			$(MAKE) clean -C $(LIBFT)
			$(MAKE) -C $(MINILIBX) clean

fclean:		clean
			@$(RM) $(NAME) 2>/dev/null
			@$(MAKE) fclean -C $(LIBFT)

re:			fclean all

.PHONY:		all clean re fclean

