NAME = computor
CC = g++

SRC = Computor.cpp Computor_add_funcs.cpp Computor_calc_equation.cpp
OBJ = $(SRC:.cpp=.o)
CFLAGS = -c -O0 -std=c++11 -Wall -Wextra -Werror
HEADERS = Computor.hpp Unknown.hpp

all: $(NAME)

$(NAME) : $(OBJ) $(HEADERS)
	@$(CC) $(OBJ) -o $(NAME)
	@echo "\033[0;36m$(NAME) is compiled\033[0m"

%.o : %.cpp $(HEADERS)
	@$(CC) $(CFLAGS) $<

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all