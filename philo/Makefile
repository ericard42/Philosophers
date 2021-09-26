# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ericard@student.42.fr <ericard>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/28 17:22:57 by ericard           #+#    #+#              #
#    Updated: 2021/09/26 16:12:08 by ericard@stu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

INCLUDE	=	philosophers.h

CC		=	clang

CFLAGS	=	-Werror -Wall -Wextra -I $(INCLUDE)

SRCS	=	main.c \
			ft_atoi.c \
			init.c \
			messages.c \
			errors.c \
			life.c \

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(INCLUDE)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lpthread

clean	:
			rm -rf $(OBJS)

fclean	:	clean
			rm $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re