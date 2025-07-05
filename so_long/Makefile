# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youbella <youbella@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 13:59:00 by youbella          #+#    #+#              #
#    Updated: 2025/04/08 20:23:47 by youbella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit

SRC_DIR = mandatory
SRC_DIR_B = bonus

SRC = $(SRC_DIR)/so_long.c $(SRC_DIR)/utils.c $(SRC_DIR)/get_next_line.c $(SRC_DIR)/ft_split.c \
		$(SRC_DIR)/control.c $(SRC_DIR)/draw_map.c $(SRC_DIR)/check_map.c $(SRC_DIR)/utils2.c $(SRC_DIR)/check_map2.c \
		$(SRC_DIR)/check_map3.c

SRC_B = $(SRC_DIR_B)/so_long_bonus.c $(SRC_DIR_B)/utils_bonus.c $(SRC_DIR_B)/get_next_line_bonus.c $(SRC_DIR_B)/ft_split_bonus.c \
		$(SRC_DIR_B)/control_bonus.c $(SRC_DIR_B)/draw_map_bonus.c $(SRC_DIR_B)/check_map_bonus.c $(SRC_DIR_B)/utils2_bonus.c \
		$(SRC_DIR_B)/ft_itoa_bonus.c  $(SRC_DIR_B)/check_map2_bonus.c $(SRC_DIR_B)/check_map3_bonus.c

OBJS = $(SRC:.c=.o)
OBJS_B = $(SRC_B:.c=.o)

NAME = so_long
NAME_B = so_long_bonus

HEADERS = mandatory/so_long.h
HEADERS_B = bonus/so_long_bonus.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX) $(OBJS) -o $@

bonus: $(NAME_B)

$(NAME_B): $(OBJS_B)
	$(CC) $(CFLAGS) $(MLX) $(OBJS_B) -o $@

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_DIR_B)/%.o: $(SRC_DIR_B)/%.c $(HEADERS_B)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(NAME) $(NAME_B)

re: fclean all

.PHONY: clean
