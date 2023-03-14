SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./inc

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

UCFLAGS = -Wall  -I $(INC_DIR)
CFLAGS = -Wall -Werror -Wextra

NAME = philo
ARGS = 6 90 60 70

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $@

$(NAME): $(OBJ)
	gcc -o $@ $(OBJ)

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -c $(CFLAGS) -I $(INC_DIR) $< -o $@

run: all
	@echo "\033[92m \033[3mRunning \033[0m \033[0m"
	@./$(NAME) $(ARGS)

clean: 
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: fclean all