# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmirlico <bmirlico@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 18:44:26 by bmirlico          #+#    #+#              #
#    Updated: 2023/09/12 17:18:51 by bmirlico         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## MAIN VARIABLES

NAME = 			philo

CC = 			cc

CFLAGS = 		-g3 -Wall -Wextra -Werror

RM =			rm -f

RM_RF =			rm -rf

## SOURCES and FLAGS

SRC_DIR = 		./src

SRCS = 			$(SRC_DIR)/main.c \
				$(SRC_DIR)/parsing.c \
				$(SRC_DIR)/thread.c \
				$(SRC_DIR)/routine.c \
				$(SRC_DIR)/time.c \
				$(SRC_DIR)/utils.c \

PTHREAD_FLAGS = -pthread

## OBJECTS

OBJ_DIR =		./obj

OBJS = 			$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

## HEADERS

HDIR = 			./inc

HD = 			$(HDIR)/philo.h

INC_HD =		-I $(HDIR)

## RULES

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(INC_HD) $(OBJS) $(PTHREAD_FLAGS) -o $@

$(OBJS):		$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HD)
				mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) $(INC_HD) $(PTHREAD_FLAGS) -c $< -o $@

clean:
				$(RM_RF) $(OBJ_DIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY: 		all clean fclean re
