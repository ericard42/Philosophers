# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ericard <ericard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/28 17:22:57 by ericard           #+#    #+#              #
#    Updated: 2021/11/02 13:50:46 by ericard          ###   ########.fr        #
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
			time.c \
			forks.c \
			close.c \
			ft_putstr_fd.c \
			
OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(INCLUDE)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lpthread

clean	:
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re