# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 11:47:56 by mmeier            #+#    #+#              #
#    Updated: 2025/01/29 16:44:41 by mmeier           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = maggots
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++11

SRC_DIR = ./
OBJ_DIR = obj

FILES = Bureaucrat.cpp \
		Form.cpp \
		main.cpp

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(FILES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ_FILES)
	@echo "\033[32m maggots has been built successfully!\033[0m"

fsanitize: 
	$(CC) -o $(NAME) $(FILES) -g -fsanitize=address -static-libsan 
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR) 
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
