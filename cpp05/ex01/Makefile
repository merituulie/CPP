# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 15:56:21 by meskelin          #+#    #+#              #
#    Updated: 2023/11/14 16:24:35 by meskelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01

BUILD_FLAGS = -Wall -Wextra -std=c++98 -Werror

SRC =	Bureaucrat \
		Form \
		tests

H =		Bureaucrat \
		Form

SRC_SUFF = $(addsuffix .cpp, $(SRC))
HEADER_SUFF = $(addsuffix .hpp, $(H))

SRCO = $(addsuffix .o, $(SRC))

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(SRC_SUFF) $(HEADER_SUFF) main.cpp
	c++ $(BUILD_FLAGS) $(SRC_SUFF) main.cpp -o $(NAME)

clean:
	rm -f $(SRCSO)

fclean: clean
	rm -f $(NAME)

re: fclean all
