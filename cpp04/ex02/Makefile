# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/16 18:21:53 by youbella          #+#    #+#              #
#    Updated: 2025/11/23 10:00:40 by youbella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Animal.cpp Brain.cpp Cat.cpp Dog.cpp
OBJ_SRC = $(SRC:.cpp=.o)

NAME = brain 

all: $(NAME)

$(NAME): $(OBJ_SRC)
	$(CC) $(CFLAGS) $(OBJ_SRC) -o $(NAME)

%.o: %.cpp Animal.hpp Brain.hpp Cat.hpp Dog.hpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ_SRC)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
