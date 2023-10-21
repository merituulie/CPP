# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 19:58:45 by meskelin          #+#    #+#              #
#    Updated: 2023/10/21 12:48:56 by meskelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scavTrap

BUILD_FLAGS = -Wall -Wextra -std=c++98 -Werror

SRC = ClapTrap \
		ScavTrap

H = ClapTrap \
	ScavTrap

SRC_SUFF = $(addsuffix .cpp, $(SRC))
HEADER_SUFF = $(addsuffix .hpp, $(SRC))

SRCO = $(addsuffix .o, $(SRC))

.PHONY: all $(NAME) clean fclean re
all: $(NAME)

$(NAME): main.cpp $(SRC_SUFF) $(HEADER_SUFF)
	c++ $(BUILD_FLAGS) $(SRC_SUFF) main.cpp -o $(NAME) -I $(HEADER_SUFF)

clean:
	rm -f $(SRCSO)

fclean: clean
	rm -f $(NAME)

re: fclean all
