CC=gcc
CFLAGS=-Wall -Werror -Wextra
INC = -Iinlcude/ -I$(LIB_DIR)/
SRC_NAME=push_swap.c
OBJ_NAME=$(SRC_NAME:.c=.o)
OBJ=$(addprefix $(OBJ_DIR),$(OBJ_NAME))
SRC=$(addprefix $(SRC_DIR),$(SRC_NAME))
LIB_DIR=libft/
SRC_DIR=src/
OBJ_DIR=obj/
NAME=push_swap

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_DIR) --silent
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIB_DIR) -lft
	rm -f *.o

#$(OBJ): $(SRC)
#	$(CC) $(CFLAGS) -c $(SRC) $(INC)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "##### Creating" [ $@ ] " #####"
	@gcc $(FLAGS) -o $@ -c $^ $(INC)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

