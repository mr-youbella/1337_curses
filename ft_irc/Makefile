NAME = ircserv

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc -fsanitize=address -g

SRC = src/main.cpp src/server.cpp src/client.cpp src/command_handler.cpp src/parse.cpp src/channel.cpp src/bot.cpp src/fileTransfer.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp inc/server.hpp inc/client.hpp inc/command_handler.hpp inc/bot.hpp inc/fileTransfer.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
