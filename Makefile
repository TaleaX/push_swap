CC=gcc
CFLAGS=-Wall -Werror -Wextra
INC_LIB=-Iinlcude/ -I$(LIB_DIR)/
INC_SRC=-Iinlcude/ -I$(INC_DIR)/
SRC_NAME=push_swap.c create_stack.c operations.c list_utils.c
OBJ_NAME=$(SRC_NAME:.c=.o)
OBJ=$(addprefix $(OBJ_DIR),$(OBJ_NAME))
SRC=$(addprefix $(SRC_DIR),$(SRC_NAME))
LIB_DIR=libft/
SRC_DIR=src/
OBJ_DIR=obj/
INC_DIR=includes/
NAME=push_swap

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -o $@ -c $^ $(INC_LIB)
#$(OBJ_DIR)%.o: $(SRC_DIR)%.c
#@gcc $(FLAGS) -o $@ -c $^ $(INC_LIB)
#@echo "##### Creating" [ $@ ] " #####"
#@gcc $(FLAGS) -o $@ -c $^ $(INC_LIB)

$(NAME): $(OBJ)
	@make -C $(LIB_DIR) --silent
	@mv $(LIB_DIR)*.o $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIB_DIR) -lft
#rm -f *.o
#@gcc $(FLAGS) $(OBJ) $(INC_SRC)
#$(OBJ): $(SRC)
#	$(CC) $(CFLAGS) -c $(SRC) $(INC)



clean:
	rm -f $(OBJ_DIR)*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

