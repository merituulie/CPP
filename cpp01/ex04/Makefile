# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 11:12:25 by meskelin          #+#    #+#              #
#    Updated: 2023/11/14 17:47:05 by meskelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fileHandler

BUILD_FLAGS = -Wall -Wextra -std=c++98 -Werror

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): main.cpp
	c++ $(BUILD_FLAGS) main.cpp -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all
