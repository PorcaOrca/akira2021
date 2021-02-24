# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 10:47:43 by lodovico          #+#    #+#              #
#    Updated: 2021/02/24 09:58:16 by lodovico         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(MAPS)\
			$(DB)\
			$(EM)\
			$(MAIN)
			

MLX_F	=	-lmlx -lXext -lX11

EM		=	event_manage/ft_close.c

MAIN	=	main/ft_init.c

MAPS	=	maps/ft_map_fill.c\
			maps/ft_map_free.c\
			maps/ft_map_matrix.c\
			maps/ft_map_read.c\
			maps/ft_map_size.c\
			maps/ft_map_str.c

DB		= 	debuggin/debug.c\
			debuggin/debugstr.c\
			debuggin/debugint.c

NAME	=	akira2021.a

CFLAGS	=	-Wall -Werror -Wextra

CC		=	gcc

OBJCS	=	$(SRCS:.c=.o)

$(NAME):	$(OBJCS)
			ar -rc $(NAME) $(OBJCS)
			ranlib $(NAME)

compile:	$(NAME)
			$(CC) $(CFLAGS) main/ft_akira2021.c $(NAME) $(MLX_F) -o akira2021

run:		compile
			make clean
			./akira2021

all:		$(NAME)

clean:
			rm -f $(OBJCS) 

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re