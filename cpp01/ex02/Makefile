# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 11:12:25 by meskelin          #+#    #+#              #
#    Updated: 2023/09/05 17:05:02 by meskelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = HiThisIsBrain

BUILD_FLAGS = -Wall -Wextra -std=c++98 -Werror

SRC =

H =

SRC_SUFF = $(addsuffix .cpp, $(SRC))
HEADER_SUFF = $(addsuffix .hpp, $(H))

SRCSO = $(addsuffix .o, $(SRC))

.PHONY = all $(NAME) clean fclean re
all: $(NAME)

$(NAME): main.cpp
	c++ $(BUILD_FLAGS) main.cpp -o $(NAME)

clean:
	rm -f $(SRCSO)

fclean: clean
	rm -f $(NAME)

re: fclean all
