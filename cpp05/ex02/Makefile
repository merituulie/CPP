# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 15:56:21 by meskelin          #+#    #+#              #
#    Updated: 2023/10/30 19:35:22 by meskelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02

BUILD_FLAGS = -Wall -Wextra -std=c++98 #-Werror

SRC =	Bureaucrat \
		AForm \
		ShrubberyCreationForm \
		tests

H =		Bureaucrat \
		ShrubberyCreationForm \
		AForm

SRC_PRE = $(addprefix ./src/, $(SRC))
SRC_SUFF = $(addsuffix .cpp, $(SRC_PRE))
HEADER_PRE = $(addprefix ./includes/, $(H))
HEADER_SUFF = $(addsuffix .hpp, $(HEADER_PRE))

SRCO = $(addsuffix .o, $(SRC))

.PHONY: all $(NAME) clean fclean re
all: $(NAME)

$(NAME): $(SRC_SUFF) $(HEADER_SUFF) main.cpp
	c++ $(BUILD_FLAGS) $(SRC_SUFF) main.cpp -o $(NAME)

clean:
	rm -f $(SRCSO)

fclean: clean
	rm -f $(NAME)

re: fclean all
