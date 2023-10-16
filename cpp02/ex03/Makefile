# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 11:12:25 by meskelin          #+#    #+#              #
#    Updated: 2023/10/16 10:26:16 by meskelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BSP

BUILD_FLAGS = -Wall -Wextra -std=c++98 -Werror

SRC =	Fixed \
		Point \
		bsp

H = Fixed \
	Point

SRC_SUFF = $(addsuffix .cpp, $(SRC))
HEADER_SUFF = $(addsuffix .hpp, $(H))

SRCSO = $(addsuffix .o, $(SRC))

.PHONY = all $(NAME) clean fclean re
all: $(NAME)

$(NAME): main.cpp $(SRC_SUFF) $(HEADER_SUFF)
	c++ $(BUILD_FLAGS) $(SRC_SUFF) main.cpp -o $(NAME)

clean:
	rm -f $(SRCSO)

fclean: clean
	rm -f $(NAME)

re: fclean all
