# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/10 23:58:02 by youbella          #+#    #+#              #
#    Updated: 2025/06/14 17:08:32 by youbella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

BNS = philosophers_bonus.c manage_time_bonus.c routine_bonus.c handling_bonus.c
OBJB = $(BNS:.c=.o)
NAME = philo_bonus

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

bonus: all

print: 
	$(print)

$(NAME): $(OBJB)
	@$(CC) $(CFLAGS) $(OBJB) -o $@
	@echo "$(GREEN)✅ Compilation Completed Successfully!$(RESET)"

%.o: %.c philosophers_bonus.h
	@echo "$(YELLOW)⚙️  Compiling $<...$(RESET)"
	@printf "$(BLUE)⚙️  Norminette:$(RESET)$(GREEN) " && norminette $< && echo "$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJB)
	@echo "$(RED)🧹 Object files removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)🗑️  Program removed.$(RESET)"

re: fclean all

.PHONY: clean
