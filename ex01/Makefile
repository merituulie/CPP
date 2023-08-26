# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 11:12:25 by meskelin          #+#    #+#              #
#    Updated: 2023/08/26 11:34:18 by meskelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

BUILD_FLAGS = -Wall -Wextra -std=c++98 #-Werror

SRC = megaphone

SRC_SUFF = $(addsuffix .cpp, $(SRC))

.PHONY = all $(NAME) clean fclean re
all: $(NAME)

$(NAME):
	c++ $(BUILD_FLAGS) $(SRC_SUFF) -o $(NAME)

clean:
	rm -f $(SRCSO)

fclean: clean
	rm -f $(NAME)

re: fclean all
