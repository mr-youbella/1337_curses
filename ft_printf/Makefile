# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youbella <youbella@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 12:17:45 by youbella          #+#    #+#              #
#    Updated: 2024/12/06 12:17:46 by youbella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c
BNS = BNS/ft_printf.c BNS/ft_putnbr_hash_bonus.c BNS/ft_putnbr_space_bonus.c BNS/ft_putnbr_plus_bonus.c
LBF = LBF/ft_putchar.c LBF/ft_putstr.c LBF/ft_putnbr_add.c LBF/ft_putnbr.c LBF/ft_putnbr_un.c LBF/ft_putnbr_hex.c

OBJS = $(SRC:.c=.o) $(LBF:.c=.o)
OBJB = $(BNS:.c=.o) $(LBF:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

bonus: $(OBJB)
	ar -rc $(NAME) $(OBJB)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

BNS/%.o: BNS/%.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

LBF/%.o: LBF/%.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
