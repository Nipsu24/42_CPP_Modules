# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 11:47:56 by mmeier            #+#    #+#              #
#    Updated: 2024/11/27 11:55:51 by mmeier           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = violence
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++11

SRC_DIR = ./
OBJ_DIR = obj

FILES = Weapon.cpp \
		HumanA.cpp \
		HumanB.cpp \
		main.cpp

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(FILES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ_FILES)
	@echo "\033[32m violence has been built successfully!\033[0m"

fsanitize: 
	$(CC) -o $(NAME) $(FILES) -g -fsanitize=address -static-libsan 
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)Weapon.hpp $(SRC_DIR)HumanA.hpp $(SRC_DIR)HumanB.hpp | $(OBJ_DIR) 
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
