# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/09 14:25:33 by vthomas           #+#    #+#              #
#    Updated: 2016/11/19 10:58:52 by vthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fractol
CC = clang
CFLAGS = -Wall -Wextra -Werror -Os -Ofast

DBG_OUT = /dev/ttys001

SRC_NAME = main.c\
		   draw/other/img_put_px.c\
		   draw/other/info.c\
		   draw/other/line.c\
		   draw/other/color_rainbow.c\
		   draw/other/zoom.c\
		   draw/mandel.c\
		   draw/mandel/expose.c\
		   draw/mandel/calculate.c\
		   draw/julia.c\
		   draw/julia/expose.c\
		   draw/julia/calculate.c\
		   draw/fish.c\
		   draw/fish/expose.c\
		   draw/fish/calculate.c\
		   draw/ship.c\
		   draw/ship/expose.c\
		   draw/ship/calculate.c\
		   event.c\
		   init.c\
		   usage.c
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_PATH = ./src/
OBJ_PATH = ./obj/

OBJ_SUB = draw\
		  draw/other\
		  draw/mandel\
		  draw/julia\
		  draw/fish\
		  draw/ship

SRC=$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ=$(addprefix $(OBJ_PATH),$(OBJ_NAME))

LIB = -L ./libft -lft -lmlx -lpthread
INC = -I ./include -I ./libft
FMW = -framework OpenGl -framework AppKit

all: $(NAME)

$(NAME): lib $(OBJ)
	@printf "\033[34;1m\n▶    \033[0;32;1m✔ \033[0;34;1mSources\033[0;32;1m ✔\033[0;34;1m    ◀\033[0m\n"
	@printf "\033[90m--------------------------------------------------------------------------------\033[0m\n"
	@printf "\033[34m▶    \033[4mLINK\033[0;34m    ◀\033[0m\n"
	@$(CC) $(CFLAGS) $(LIB) $(INC) $(FMW) $(OBJ) -o $@
	@chmod +x $(NAME)
	@printf "\033[34;1m\n▶    \033[0;32;1m✔ \033[0;34;1mLink\033[0;32;1m ✔\033[0;34;1m    ◀\033[0m\n"
	@printf "\033[90m--------------------------------------------------------------------------------\033[0m\n"

lib:
	@printf "\033[34m▶    \033[4mLIBRAIRIES\033[0;34m    ◀\033[0m\n"
	@printf "\033[32;4m▶\tLIBFT\033[0m\n"
	@make -C ./libft
	@printf "\033[34;1m\n▶    \033[0;32;1m✔ \033[0;34;1mLibrairies\033[0;32;1m ✔\033[0;34;1m    ◀\033[0m\n"
	@printf "\033[90m--------------------------------------------------------------------------------\033[0m\n"
	@printf "\033[34m▶    \033[4mSOURCES\033[0;34m    ◀\033[0m\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH) $(addprefix $(OBJ_PATH),$(OBJ_SUB))
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	-@rm -rf $(OBJ_PATH);
	@make -C ./libft $@

fclean: clean
	-@rm $(NAME)
	@make -C ./libft $@
	@printf "🦄  There is no more unicorn poop 🦄\n"

re: fclean all

test: all
	@clear
	@clear > $(DBG_OUT)
	./$(NAME) fish 2> $(DBG_OUT)
.PHONY: fclean clean
