# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 09:53:47 by lspazzin          #+#    #+#              #
#    Updated: 2021/01/22 09:26:21 by lspazzin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#  -*- Makefile -*-

SRCS		=	ft_memset.c \
				ft_strmapi.c \
				ft_atoi.c \
				ft_putchar_fd.c \
				ft_strncmp.c \
				ft_bzero.c \
				ft_putendl_fd.c \
				ft_strnstr.c \
				ft_calloc.c \
				ft_putnbr_fd.c \
				ft_strrchr.c \
				ft_isalnum.c \
				ft_putstr_fd.c \
				ft_strtrim.c \
				ft_isalpha.c \
				ft_split.c \
				ft_substr.c \
				ft_isascii.c \
				ft_strchr.c \
				ft_tolower.c \
				ft_isdigit.c \
				ft_memccpy.c \
				ft_strdup.c \
				ft_toupper.c \
				ft_isprint.c \
				ft_memchr.c \
				ft_strjoin.c \
				ft_itoa.c \
				ft_memcmp.c \
				ft_strlcat.c \
				ft_memcpy.c \
				ft_strlcpy.c \
				ft_memmove.c \
				ft_strlen.c \

SRCS_BONUS	=	ft_lstadd_front.c \
				ft_lstadd_back.c \
				ft_lstmap.c \
				ft_lstclear.c \
				ft_lstlast.c \
				ft_lstiter.c \
				ft_lstdelone.c \
				ft_lstnew.c \
				ft_lstsize.c \

FLAGS		=	-Wall -Wextra -Werror

CC			=	gcc

NAME		=	libft.a

RM			=	/bin/rm -f

OBJCS		=	$(SRCS:.c=.o)

OBJCS_BONUS	=	$(SRCS_BONUS:.c=.o)

%.o:			%.c
				$(CC) $(FLAGS) -c $<

$(NAME):		$(OBJCS)
				ar -rc $(NAME) $(OBJCS)
				ranlib $(NAME)

bonus:			$(NAME) $(OBJCS_BONUS)
				ar -rc $(NAME) $(OBJCS_BONUS)
				ranlib $(NAME)

all:			$(NAME)

clean:
				$(RM) $(OBJCS) $(OBJCS_BONUS)

karen:
				@ norminette *.c
				@ norminette *.h

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			clean all objects karen re fclean bonus
