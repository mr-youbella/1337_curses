# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/10 23:58:08 by youbella          #+#    #+#              #
#    Updated: 2025/06/17 21:42:07 by youbella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = philosophers.c utils.c routine.c manage_time.c init.c
OBJS = $(SRC:.c=.o)
NAME = philo

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
RESET = \033[0m

define print
	@echo "$(RED) _____ _   _ _                 _               "
	@sleep 0.1
	@echo "|  _  | |_|_| |___ ___ ___ ___| |_ ___ ___ ___ "
	@sleep 0.1
	@echo "|   __|   | | | . |_ -| . | . |   | -_|  _|_ -|"
	@sleep 0.1
	@echo "$(GREEN)|__|  |_|_|_|_|___|___|___|  _|_|_|___|_| |___|"
	@sleep 0.1
	@echo "|__|  |_|_|_|_|___|___|___|  _|_|_|___|_| |___|"
	@sleep 0.1
	@echo "                          |_|                  $(RESET)"
endef

all: print $(NAME)

print: 
	$(print)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "$(GREEN)✅ Compilation Completed Successfully!$(RESET)"

%.o: %.c philosophers.h
	@echo "$(YELLOW)⚙️  Compiling $<...$(RESET)"
	@printf "$(BLUE)⚙️  Norminette:$(RESET)$(GREEN) " && norminette $< && echo "$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "$(RED)🧹 Object files removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)🗑️  Program removed.$(RESET)"

re: fclean all

.PHONY: clean
