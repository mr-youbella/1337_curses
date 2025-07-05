# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youbella <youbella@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 21:04:42 by youbella          #+#    #+#              #
#    Updated: 2025/02/27 04:52:34 by youbella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT_SRCS = mandatory/client.c mandatory/ft_atoi.c
SERVER_SRCS = mandatory/server.c mandatory/ft_putnbr.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CLIENT_SRCS_B = bonus/client_bonus.c bonus/ft_atoi_bonus.c
SERVER_SRCS_B = bonus/server_bonus.c bonus/ft_putnbr_bonus.c bonus/ft_bzero_bonus.c 
CLIENT_OBJS_B = $(CLIENT_SRCS_B:.c=.o)
SERVER_OBJS_B = $(SERVER_SRCS_B:.c=.o)

NAME = client
NAME_SERVER = server

NAME_CLIENT_B = client_bonus
NAME_SERVER_B = server_bonus

all: $(NAME) $(NAME_SERVER)

$(NAME): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(NAME) 

$(NAME_SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(NAME_SERVER)

bonus: $(NAME_CLIENT_B) $(NAME_SERVER_B)

$(NAME_CLIENT_B): $(CLIENT_OBJS_B)
	$(CC) $(CFLAGS) $(CLIENT_OBJS_B) -o $(NAME_CLIENT_B)

$(NAME_SERVER_B): $(SERVER_OBJS_B)
	$(CC) $(CFLAGS) $(SERVER_OBJS_B) -o $(NAME_SERVER_B)

mandatory/%.o: mandatory/%.c mandatory/client.h mandatory/server.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/client_bonus.h bonus/server_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS) $(CLIENT_OBJS_B) $(SERVER_OBJS_B)

fclean: clean
	rm -f $(NAME) $(NAME_SERVER) $(NAME_CLIENT_B) $(NAME_SERVER_B)

re: fclean all
