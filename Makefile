# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yberries <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 05:28:15 by yberries          #+#    #+#              #
#    Updated: 2020/08/03 06:57:54 by yberries         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = yberries.filler

LIBFT_DIR = libft/
LIBFT_LNK = -L $(LIBFT_DIR) -lft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR)/, $(SRCS))
SRCS = main.c

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

HDR_DIR = include/
HDRS = filler.h
INCLUDES = $(addprefix $(HDR_DIR), $(HDRS))

FLAGS = -Wall -Wextra -Werror

.PHONY: clean all re fclean

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT) $(INCLUDES)
	gcc $(FLAGS) -o $@ $(OBJ) $(LIBFT_LNK)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -sC $(LIBFT_DIR)

$(OBJ): $(SRC) $(INCLUDES)
	gcc $(FLAGS) -I $(HDR_DIR) -I $(LIBFT_DIR) -o $@ -c $<

clean:
	make -sC $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	make -sC $(LIBFT_DIR) fclean
	
re: fclean all
