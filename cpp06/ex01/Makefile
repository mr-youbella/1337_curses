# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/27 11:51:28 by youbella          #+#    #+#              #
#    Updated: 2026/01/29 17:45:49 by youbella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp Serializer.cpp
OBJ_SRC = $(SRC:.cpp=.o)

NAME = serializer

all: $(NAME)

$(NAME): $(OBJ_SRC)
	$(CC) $(CFLAGS) $(OBJ_SRC) -o $(NAME)

%.o: %.cpp Serializer.hpp Data.hpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ_SRC)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
