# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivaliev <ivaliev@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 08:37:49 by ivaliev           #+#    #+#              #
#    Updated: 2023/01/13 08:37:50 by ivaliev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = philo
SRC = philo.c philo_utils.c start_prog.c initialize.c check_done_eat_and_die.c routine.c
OBJS = $(SRC:.c=.o)
CC = gcc -pthread
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	${CC} -lpthread ${CFLAGS} ${OBJS} -o $@

%.o: %.c philosophers.h
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all