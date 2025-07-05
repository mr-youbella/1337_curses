# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youbella <youbella@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/10 01:40:15 by youbella          #+#    #+#              #
#    Updated: 2025/04/11 21:20:44 by youbella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = mandatory
BNS_DIR = bonus

SRC = $(SRC_DIR)/push_swap.c $(SRC_DIR)/operations_a.c $(SRC_DIR)/operations_b.c $(SRC_DIR)/put_num_stack_a.c $(SRC_DIR)/small_sort.c $(SRC_DIR)/big_sort.c \
		$(SRC_DIR)/utils.c $(SRC_DIR)/utils_linked_list.c $(SRC_DIR)/ft_split.c
BNS = $(BNS_DIR)/push_swap_bonus.c $(BNS_DIR)/operations_a_bonus.c $(BNS_DIR)/operations_b_bonus.c $(BNS_DIR)/put_num_stack_a_bonus.c \
		$(BNS_DIR)/utils_bonus.c $(BNS_DIR)/utils_linked_list_bonus.c $(BNS_DIR)/ft_split_bonus.c $(BNS_DIR)/get_next_line_bonus.c $(BNS_DIR)/get_next_line_utils_bonus.c \
		$(BNS_DIR)/use_op_bonus.c

OBJS = $(SRC:.c=.o)
OBJB = $(BNS:.c=.o)

NAME = push_swap
NAME_BNS = checker

all: $(NAME)

bonus: $(NAME_BNS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(NAME_BNS): $(OBJB)
	$(CC) $(CFLAGS) $(OBJB) -o $@

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BNS_DIR)/%.o: $(BNS_DIR)/%.c $(BNS_DIR)/push_swap_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJB)

fclean: clean
	rm -f $(NAME) $(NAME_BNS)

re: fclean all

.PHONY: clean
