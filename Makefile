# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: garevalo <garevalo@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 15:23:49 by garevalo          #+#    #+#              #
#    Updated: 2026/04/29 18:17:46 by garevalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = main.c \
	   philo.c \
	   philo_utils.c \
	   src/init.c \
	   src/monitor.c \
	   src/rutine.c

CC = cc

CFLAGS = -Werror -Wextra -Wall

PTHREAD = -lpthread

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@ $(PTHREAD)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
