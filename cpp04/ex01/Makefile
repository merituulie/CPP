# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 19:58:45 by meskelin          #+#    #+#              #
#    Updated: 2023/10/23 12:50:45 by meskelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animal

BUILD_FLAGS = -Wall -Wextra -std=c++98 -Werror

SRC =	Brain \
		Animal \
		Dog \
		Cat \
		WrongAnimal \
		WrongCat

H =		Brain \
		Animal \
		Dog \
		Cat \
		WrongAnimal \
		WrongCat

SRC_SUFF = $(addsuffix .cpp, $(SRC))
HEADER_SUFF = $(addsuffix .hpp, $(SRC))

SRCO = $(addsuffix .o, $(SRC))

.PHONY: all $(NAME) clean fclean re
all: $(NAME)

$(NAME): main.cpp $(SRC_SUFF) $(HEADER_SUFF)
	c++ $(BUILD_FLAGS) $(SRC_SUFF) main.cpp -o $(NAME)

clean:
	rm -f $(SRCSO)

fclean: clean
	rm -f $(NAME)

re: fclean all
