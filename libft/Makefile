# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arguilla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/26 21:39:55 by arguilla          #+#    #+#              #
#    Updated: 2021/10/09 01:40:41 by arguilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# [ VARIABLES ] #

SHELL			=	/bin/sh
NAME 			=	libft.a
RM				=	/bin/rm -rf
MAKE			=	make

# [ COLORS ] #

_RED			=	\e[31m
_GREEN			=	\e[32m
_YELLOW			=	\e[33m
_END			=	\e[0m
_BOLDGREEN  	=	\033[1m\033[32m

# [ COMPILATION VARIABLES ] #

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
INC				=	-I./ -I./char -I./file -I./int -I./lst -I./mem -I./print -I./str 

# [ SOURCES ] #

SRC				=	ft_strlen.c\
	  			  	ft_toupper.c\
	  		  		ft_tolower.c\
			  		ft_isspace.c\
	  		  		ft_isalpha.c\
	  		  		ft_isdigit.c\
	  		  		ft_isalnum.c\
	  		  		ft_isprint.c\
	  		  		ft_isascii.c\
	  		  		ft_atoi.c\
			  		ft_strtol.c\
					ft_abs.c\
	  		  		ft_bzero.c\
	  		  		ft_calloc.c\
	  		  		ft_strchr.c\
	  		  		ft_strrchr.c\
			  		ft_strrstr.c\
	  		  		ft_strdup.c\
	  		  		ft_strncmp.c\
	  		  		ft_strlcat.c\
	  		  		ft_strlcpy.c\
	  		  		ft_memset.c\
	  		  		ft_memcpy.c\
	  		  		ft_memccpy.c\
	  		  		ft_strnstr.c\
	  		  		ft_memchr.c\
	  		  		ft_memcmp.c\
	  		  		ft_memmove.c\
	  		  		ft_itoa.c\
	  		  		ft_substr.c\
	  		  		ft_strjoin.c\
	  		  		ft_strtrim.c\
	  		  		ft_split.c\
	  		  		ft_strmapi.c\
	  		  		ft_putchar_fd.c\
	  		  		ft_putstr_fd.c\
	  		  		ft_putendl_fd.c\
	  		  		ft_putnbr_fd.c\
			  		get_next_line.c\
			  		get_next_line_utils.c\
			  		ft_lstnew.c\
	   		  		ft_lstadd_front.c\
	   		  		ft_lstsize.c\
	   		  		ft_lstlast.c\
	   		  		ft_lstadd_back.c\
	   		  		ft_lstdelone.c\
	   		  		ft_lstclear.c\
	   		  		ft_lstiter.c\
	   		  		ft_lstmap.c\

# [ OBJECTS ] #

O				=	obj/
OBJ				=	$(SRC:%=$O%.o)

# [ PATH ] #

VPATH 			=	char:file:int:lst:mem:print:str

# [ RULES ] #

all:			$(NAME)

$(NAME):		$(OBJ)
				@ar rc $@ $^
				@ranlib $@
				@printf "%-55b %b" "$(_GREEN)Library $(NAME) created.$(_END)" "[ $(_BOLDGREEN)OK$(_END) ]\n"

$O:
				@mkdir -p $@

$O%.o: %		| $O
				@$(CC) $(CFLAGS) $(INC) -c -o $@ $<
				@printf "%-55b %b" "Compiling $(_YELLOW) $@ $(_END)" "[ $(_GREEN)OK$(_END) ]\n"

clean:
				@$(RM) $(OBJ)
				@$(RM) $O
				@printf "%-55b %b" "$(_RED)Delete$(_END) $O" "[ $(_GREEN)OK$(_END) ]\n"

fclean: clean
				@$(RM) $(NAME)
				@printf "%-55b %b" "$(_RED)Delete$(_END) $(NAME)" "[ $(_GREEN)OK$(_END) ]\n"

re:				fclean all

.PHONY: all re clean fclean
