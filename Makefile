# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 10:47:43 by lodovico          #+#    #+#              #
#    Updated: 2021/03/10 11:37:39 by lodovico         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(MAIN)\
			$(DB)\
			$(EM)\
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
			img_manage/ft_sprite.c\
			img_manage/ft_skybox.c

EM		=	event_manage/ft_close.c\
			event_manage/ft_new_frame.c\
			event_manage/ft_movement.c\
			event_manage/ft_key_press.c\
			event_manage/ft_key_release.c

MAIN	=	main/ft_akira2021.c\
			main/ft_init.c\
			main/ft_cub_init.c


UT		=	utils/ft_get_next_line.c\
			
DB		= 	debuggin/debug.c\
			debuggin/debugstr.c\
			debuggin/debugint.c

NAME	=	akira2021

CFLAGS	=	-Wall -Werror -Wextra -g

CC		=	gcc

OBJCS	=	$(SRCS:.c=.o)

$(NAME):	$(OBJCS)
			@$(MAKE) bonus -C ./libft
			$(CC) $(OBJCS) $(CFLAGS) $(MLX_F) ./libft/libft.a -o $(NAME)

lib:		$(OBJCS)
			ar -rc akira2021.a $(OBJCS)
			ranlib akira2021.a
			
run:		$(NAME)
			./akira2021

all:		$(NAME)

clean:
			@$(MAKE) clean -C ./libft
			rm -f $(OBJCS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re run
