# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: garevalo <garevalo@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 15:23:49 by garevalo          #+#    #+#              #
#    Updated: 2026/04/20 14:38:22 by garevalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = 	main.c \
<<<<<<< HEAD
		src/init.c \
=======
>>>>>>> 660e178 (editing makefile)
		philo_utils.c

CC = gcc

CFLAGS = -Werror -Wextra -Wall

OBJS = $(SRCS:.c=.o)

PTHREAD = -lpthread

%.o  = %.c
	$(CC) $(CFLAGS) $(PTHREAD) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(PTHREAD) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY all clean fclean re
