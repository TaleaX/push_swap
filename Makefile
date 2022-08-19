CC=gcc #-fsanitize=address -g
CFLAGS=-Wall -Werror -Wextra -g
INC_LIB=-Iinlcude/ -I$(LIB_DIR)/
INC_SRC=-Iinlcude/ -I$(INC_DIR)/
SRC_NAME=push_swap.c create_stack.c lst_utils.c sort_big.c visual.c utils.c sort_small.c sort_b_utils.c lst_utils2.c op_shifts.c op_swap_push.c libft_adds.c init.c op_both.c
CHECKER_SRC_NAME=checker.c create_stack.c lst_utils.c sort_big.c visual.c utils.c sort_small.c sort_b_utils.c lst_utils2.c op_shifts.c op_swap_push.c libft_adds.c init.c checker_utils.c op_both.c
OBJ_NAME=$(SRC_NAME:.c=.o)
CHECKER_OBJ_NAME=$(CHECKER_SRC_NAME:.c=.o)
OBJ=$(addprefix $(OBJ_DIR),$(OBJ_NAME))
SRC=$(addprefix $(SRC_DIR),$(SRC_NAME))
CHECKER_OBJ=$(addprefix $(OBJ_DIR),$(CHECKER_OBJ_NAME))
CHECKER_SRC=$(addprefix $(SRC_DIR),$(CHECKER_SRC_NAME))
LIB_DIR=libft/
SRC_DIR=src/
OBJ_DIR=obj/
INC_DIR=includes/
NAME=push_swap
CHECKER=checker

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(CFLAGS) -o $@ -c $^ $(INC_LIB)

$(NAME): $(OBJ)
	@make -C $(LIB_DIR) --silent
	@mv $(LIB_DIR)*.o $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIB_DIR) -lft

bonus: $(CHECKER_OBJ)
	@make -C $(LIB_DIR) --silent
	@mv $(LIB_DIR)*.o $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $(CHECKER) $(CHECKER_OBJ) -L $(LIB_DIR) -lft

clean:
	rm -f $(OBJ_DIR)*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

