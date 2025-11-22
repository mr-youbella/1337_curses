# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/16 18:21:53 by youbella          #+#    #+#              #
#    Updated: 2025/11/21 23:40:26 by youbella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp WrongAnimal.cpp WrongCat.cpp
OBJ_SRC = $(SRC:.cpp=.o)

NAME = brain 

all: $(NAME)

$(NAME): $(OBJ_SRC)
	$(CC) $(CFLAGS) $(OBJ_SRC) -o $(NAME)

%.o: %.cpp Animal.hpp Cat.hpp Dog.hpp Brain.hpp WrongAnimal.hpp WrongCat.hpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ_SRC)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
