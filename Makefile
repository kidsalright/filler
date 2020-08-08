# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yberries <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 05:28:15 by yberries          #+#    #+#              #
#    Updated: 2020/08/08 15:24:34 by yberries         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = yberries.filler

LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = libft/
LIBFT_LNK = -L $(LIBFT_DIR) -lft

SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(SRCS))
SRCS = filler.c \
       get_input.c \
       map_handler.c \
       piece_placing.c

OBJ_DIR = obj/
OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJ = $(addprefix $(OBJ_DIR), $(OBJS))

HDRS = filler.h
HDR_DIR = include/
HDR = $(addprefix $(HDR_DIR), $(HDRS))

INCLUDES = -I $(HDR_DIR) -I $(LIBFT_DIR)

FLAGS = -Wall -Wextra -Werror

.PHONY: clean all re fclean

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(INCLUDES) $(OBJ) $(LIBFT_LNK)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -sC $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HDR)
	gcc $(FLAGS) -c $(INCLUDES) $< -o $@

clean:
	make -sC $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	make -sC $(LIBFT_DIR) fclean
	
re: fclean all
