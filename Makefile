# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/25 05:23:48 by arguilla          #+#    #+#              #
#    Updated: 2021/10/08 16:38:40 by arguilla         ###   ########.fr        #
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

SRC				=	main.c\
					error.c\
					parser.c\
					free.c\
					struct.c\

# [ OBJECTS ] #

O				=	obj/
OBJ				=	$(SRC:%=$O%.o)

# [ PATH ] #

VPATH			=	includes:srcs:libft:mlx_linux

# [ RULES ] #

all:			$(NAME)

$(NAME):		$(OBJ)
				@$(MAKE) -s -C $(LIBFT)
				@$(MAKE) -s -C  $(MINILIBX) all
				@printf "%-55b %b" "$(_GREEN)Library $(MINILIBX) created.$(_END)" "[ $(_BOLDGREEN)OK$(_END) ]\n"
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I./includes $(LIBFT_INC) $(PROG_INC) $(LIBFT)/libft.a $(MINILIBX_INC)
				@printf "%-55b %b" "$(_GREEN)Binary file $(NAME) created.$(_END)" "[ $(_BOLDGREEN)OK$(_END) ]\n"

$O:
				@mkdir -p $@


$O%.o: %		| $O
				@$(CC) $(CFLAGS) -c $< -o $@ -I./includes $(LIBFT_INC) $(PROG_INC) -I./mlx_linux
				@printf "%-55b %b" "Compiling $(_YELLOW) $@ $(_END)" "[ $(_GREEN)OK$(_END) ]\n"
clean:
				@$(MAKE) clean -s -C $(LIBFT)
				@$(MAKE) clean -s -C $(MINILIBX)
				@$(RM) $(OBJ)
				@$(RM) $O
				@printf "%-55b %b" "$(_RED)Delete$(_END) $O" "[ $(_GREEN)OK$(_END) ]\n"

fclean:		clean

			@$(MAKE) fclean -s -C $(LIBFT)
			@$(RM) $(NAME)
			@printf "%-55b %b" "$(_RED)Delete$(_END) $(NAME)" "[ $(_GREEN)OK$(_END) ]\n"

re:			fclean all

.PHONY:		all clean re fclean

