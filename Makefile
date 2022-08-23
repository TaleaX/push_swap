CC=gcc
CFLAGS=-Wall -Werror -Wextra -g
INC_LIB=-Iinlcude/ -I$(LIB_DIR)/
INC_SRC=-Iinlcude/ -I$(INC_DIR)/
SRC_NAME=push_swap.c create_stack.c lst_utils.c sort_big.c visual.c utils.c sort_small.c sort_b_utils.c lst_utils2.c op_shifts.c op_swap_push.c libft_adds.c init.c op_both.c error.c
CHECKER_SRC_NAME=checker.c create_stack.c lst_utils.c sort_big.c visual.c utils.c sort_small.c sort_b_utils.c lst_utils2.c op_shifts.c op_swap_push.c libft_adds.c init.c checker_utils.c op_both.c error.c
OBJ_NAME=$(SRC_NAME:.c=.o)
CHECKER_OBJ_NAME=$(CHECKER_SRC_NAME:.c=.o)
OBJ=$(addprefix $(OBJ_DIR),$(OBJ_NAME))
SRC=$(addprefix $(SRC_DIR),$(SRC_NAME))
CHECKER_OBJ=$(addprefix $(OBJ_DIR),$(CHECKER_OBJ_NAME))
CHECKER_SRC=$(addprefix $(SRC_DIR),$(CHECKER_SRC_NAME))
LIB_DIR=libft/
LIBFT=$(LIB_DIR)libft.a
SRC_DIR=src/
OBJ_DIR=obj/
INC_DIR=includes/
NAME=push_swap
NAME_BONUS=checker

all: $(NAME)

bonus: $(NAME_BONUS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(CFLAGS) -o $@ -c $^ $(INC_LIB)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIB_DIR) -lft

$(NAME_BONUS): $(LIBFT) $(CHECKER_OBJ)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(CHECKER_OBJ) -L $(LIB_DIR) -lft

$(LIBFT):
	make -C $(LIB_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C $(LIB_DIR)

re: fclean all
