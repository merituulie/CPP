# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 19:58:45 by meskelin          #+#    #+#              #
#    Updated: 2023/10/21 15:17:54 by meskelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = diamondTrap

BUILD_FLAGS = -Wall -Wextra -std=c++98 -Wshadow -Werror

SRC = ClapTrap \
		ScavTrap \
		FragTrap \
		DiamondTrap

H = ClapTrap \
	ScavTrap \
	FragTrap \
	DiamondTrap

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
