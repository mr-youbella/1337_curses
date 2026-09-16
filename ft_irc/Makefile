NAME = ircserv

CPP= c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc

SRC = src/main.cpp src/server.cpp src/client.cpp src/command_handler.cpp src/parse.cpp src/channel.cpp src/bot.cpp src/fileTransfer.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp inc/server.hpp inc/client.hpp inc/command_handler.hpp inc/bot.hpp inc/fileTransfer.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
