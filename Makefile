# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 10:47:43 by lodovico          #+#    #+#              #
#    Updated: 2021/03/05 18:31:27 by lodovico         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(DB)\
			$(EM)\
			$(MAIN)\
			$(IM)\
			$(TM)\
			$(UT)


MLX_F	=	-lmlx -lXext -lX11 -lm -lbsd

# MLX_F	=	-lmlx -framework OpenGL -framework AppKit

TM		=	img_manage/textures/ft_get_txtcolor.c\
			img_manage/textures/ft_txt_init.c

IM		=	img_manage/color_manage/ft_color.c\
			img_manage/ft_img_fill.c\
			img_manage/ft_img_init.c\
			img_manage/ft_img_pixel_put.c\
			img_manage/ft_img_floor.c\
			img_manage/ft_img_wall.c\
			img_manage/ft_sprite_sort.c\
			img_manage/ft_sprite.c

EM		=	event_manage/ft_close.c\
			event_manage/ft_new_frame.c\
			event_manage/ft_movement.c

MAIN	=	main/ft_init.c\
			main/ft_cub_init.c


UT		=	utils/ft_split.c\
			utils/ft_strchr.c\
			utils/ft_strdup.c\
			utils/ft_strjoin.c\
			utils/ft_strlcat.c\
			utils/ft_strlcpy.c\
			utils/ft_strlen.c\
			utils/ft_get_next_line.c\
			utils/ft_atoi.c\
			utils/ft_strncmp.c

DB		= 	debuggin/debug.c\
			debuggin/debugstr.c\
			debuggin/debugint.c

NAME	=	akira2021.a

CFLAGS	=	-Wall -Werror -Wextra -g

CC		=	gcc

OBJCS	=	$(SRCS:.c=.o)

$(NAME):	$(OBJCS)
			ar -rc $(NAME) $(OBJCS)
			ranlib $(NAME)

compile:	$(NAME)
			$(CC) $(CFLAGS) main/ft_akira2021.c $(NAME) $(MLX_F) -o akira2021

run:		compile
			./akira2021

all:		$(NAME)

clean:
			rm -f $(OBJCS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re compile run
