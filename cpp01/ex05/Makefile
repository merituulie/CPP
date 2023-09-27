# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 11:12:25 by meskelin          #+#    #+#              #
#    Updated: 2023/09/12 10:41:58 by meskelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = complain

BUILD_FLAGS = -Wall -Wextra -std=c++98 -Werror

SRC =	Harl

SRC_SUFF = $(addsuffix .cpp, $(SRC))
HEADER_SUFF = $(addsuffix .hpp, $(SRC))

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
