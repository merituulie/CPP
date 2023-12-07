
NAME = ex00

BUILD_FLAGS = -Wall -Wextra -std=c++98 -Werror

SRC =	test_int \
		test_string \
		test_awesome

H = whatever

SRC_SUFF = $(addsuffix .cpp, $(SRC))
HEADER_SUFF = $(addsuffix .hpp, $(H))

SRCO = $(addsuffix .o, $(SRC))

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): main.cpp $(SRC_SUFF) $(HEADER_SUFF)
	c++ $(BUILD_FLAGS) $(SRC_SUFF) main.cpp -o $(NAME)

clean:
	rm -f $(SRCSO)

fclean: clean
	rm -f $(NAME)

re: fclean all
