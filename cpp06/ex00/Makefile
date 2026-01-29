# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/27 11:51:28 by youbella          #+#    #+#              #
#    Updated: 2026/01/29 10:03:56 by youbella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp ScalarConverter.cpp
OBJ_SRC = $(SRC:.cpp=.o)

NAME = convert

all: $(NAME)

$(NAME): $(OBJ_SRC)
	$(CC) $(CFLAGS) $(OBJ_SRC) -o $(NAME)

%.o: %.cpp ScalarConverter.hpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ_SRC)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
