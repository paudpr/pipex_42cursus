NAME = pipex

FUN_NAME = fun.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra
CFLAGS += -I $(INC_PATH)

FUN_PATH	= functions
INC_PATH	= includes
SRC_PATH	= sources
OBJ_PATH	= objects

SRC =	main.c \
		utils.c \
		path.c \
		pipex.c \
		
SRC_BONUS = main_bonus.c \
			pipex_bonus.c \
			utils_bonus.c \
			path_bonus.c \
			heredoc_bonus.c \


all: $(NAME)

OBJS_NAME = $(SRC:%.c=%.o)
OBJS_NAME_BONUS = $(SRC_BONUS:%.c=%.o)

SRCS_NAME = $(addprefix $(SRC_PATH)/, $(SRC))
SRCS_NAME_BONUS = $(addprefix $(SRC_PATH)/, $(SRC_BONUS))

OBJS =  $(addprefix $(OBJ_PATH)/, $(OBJS_NAME))
OBJS_BONUS = $(addprefix $(OBJ_PATH)/, $(OBJS_NAME_BONUS))

$(OBJ_PATH):
			mkdir -p $(OBJ_PATH) 2> /dev/null

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
			$(CC) $(CFLAGS) -c $< -o $@

			
$(NAME): $(OBJS)
		make -C $(FUN_PATH)
		$(CC) $^ -o $@ $(CFLAGS) $(addprefix $(FUN_PATH)/, $(FUN_NAME))

$(FUN_NAME):
			$(MAKE) all -sC $(FUN_PATH)


##RULES

debug: CFLAGS +=  -g3 -fsanitize=address
debug: $(NAME)

debug_bonus: CFLAGS +=  -g3 -fsanitize=address
debug_bonus: bonus

bonus: $(OBJS_BONUS)
		make -C $(FUN_PATH)
	@if [ ! -f /tmp/relink ]; then \
    	$(CC) $^ -o pipex $(CFLAGS) $(addprefix $(FUN_PATH)/, $(FUN_NAME)) ;\
		echo /tmp/relink > /tmp/relink ; \
	fi

norminette:
	norminette $(SRCS) 

clean:
	rm -rf $(OBJ_PATH) /tmp/relink
	make clean -sC $(FUN_PATH)

fclean: clean
		rm -rf $(NAME) 
		rm -rf $(OBJ_PATH)
		make fclean -sC $(FUN_PATH)

re: fclean all

PHONY.: all clean fclean re norminette bonus
