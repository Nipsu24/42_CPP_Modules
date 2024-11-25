# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 11:47:56 by mmeier            #+#    #+#              #
#    Updated: 2024/11/25 16:09:03 by mmeier           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++11

SRC_DIR = ./
OBJ_DIR = obj

FILES = Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp \
		main.cpp

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(FILES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ_FILES)
	@echo "\033[32m zombie has been built successfully!\033[0m"

fsanitize: 
	$(CC) -o $(NAME) $(FILES) -g -fsanitize=address -static-libsan 
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)Zombie.hpp | $(OBJ_DIR) 
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
