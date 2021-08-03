# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ericard <ericard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/28 17:22:57 by ericard           #+#    #+#              #
#    Updated: 2021/07/29 17:00:27 by ericard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

INCLUDE	=	philosophers.h

CC		=	clang

CFLAGS	=	-Werror -Wall -Wextra -I $(INCLUDE)

SRCS	=	main.c \

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(INCLUDE)
			$(CC) $(CFLAGS) $(OBJS) -o (NAME)

clean	:
			rm -rf $(OBJS)

fclean	:	clean
			rm $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re