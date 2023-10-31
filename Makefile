NAME  	= tic_tac_toe
OS    	= $(shell uname)
CC    	= @cc
FLAGS	= -fsanitize=address -static-libsan -g #-Wall -Wextra -Werror
INC   	= -I./include -I./libft -I./mlx -I./mlx_macos 
SRC   	= 	$(wildcard src/*.c) $(wildcard src/render/*.c)
OBJ   	= $(patsubst src/%.c, obj/%.o, $(SRC))

ifeq ($(OS), Darwin)
	INC_MLX = mlx_macos
    MLX 	= $(INC_MLX)/libmlx.a
    LIB 	= -L$(INC_MLX) -lmlx -framework OpenGL -framework AppKit
else
	INC_MLX = mlx
    MLX 	= $(INC_MLX)/libmlx.a
    LIB 	= -L$(INC_MLX) -lmlx -lXext -lX11
endif

all: $(MLX) obj $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $@ $^ $(LIB)

$(MLX):
	@make -sC $(INC_MLX) > /dev/null 2>&1

obj:
	@mkdir -p obj

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
	@make -sC $(INC_MLX) clean > /dev/null
	@rm -rf $(OBJ) obj

fclean: clean
	@rm -rf $(NAME)

re: fclean all

run:
	@make re && ./$(NAME)

.PHONY: all