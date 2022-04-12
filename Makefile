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
			#heredoc.c


all: $(NAME)

##-L is used to include paths where the linker will look for libraries
##-l is used to link a library, which must be passed without the lib prefix and the extension
## -p para crear directorios uno dentro del otro

OBJS_NAME = $(SRC:%.c=%.o)
OBJS_NAME_BONUS = $(SRC_BONUS:%.c=%.o)

##addprefix "coge" el segundo argumento y el path del primer argumento. funciona como un while añadiendo paths a cada source
SRCS_NAME = $(addprefix $(SRC_PATH)/, $(SRC))
SRCS_NAME_BONUS = $(addprefix $(SRC_PATH)/, $(SRC_BONUS))

OBJS =  $(addprefix $(OBJ_PATH)/, $(OBJS_NAME))
OBJS_BONUS = $(addprefix $(OBJ_PATH)/, $(OBJS_NAME_BONUS))

$(OBJ_PATH):
			mkdir -p $(OBJ_PATH) 2> /dev/null

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
			$(CC) $(CFLAGS) -c $< -o $@

			
##s es para silenciar y C para que vaya al directorio
##	make -sC $(LIBFT_PATH)

##el | está para evitar que haga relink
##otra solución sería copiar la orden de $(LIBFT_NAME) para ejecutar antes de la compilación (dentro de $(NAME))
$(NAME): $(OBJS)
		make -C $(FUN_PATH)
		$(CC) $^ -o $@ $(CFLAGS) $(addprefix $(FUN_PATH)/, $(FUN_NAME))
## $(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(addprefix $(LIBFT_PATH)/, $(LIBFT_NAME))

$(FUN_NAME):
			$(MAKE) all -sC $(FUN_PATH)

##RULES

debug: CFLAGS +=  -g3 -fsanitize=address
debug: $(NAME)

debug_bonus: CFLAGS +=  -g3 -fsanitize=address
debug_bonus: bonus

bonus: $(OBJS_BONUS)
		make -C $(FUN_PATH)
		$(CC) $^ -o $(NAME) $(CFLAGS) $(addprefix $(FUN_PATH)/, $(FUN_NAME)) 

norminette:
	norminette $(SRCS) 

clean: 
	rm $(NAME) 
	rm -rf $(OBJ_PATH)
	make clean -sC $(FUN_PATH)

fclean: clean
		rm -rf $(NAME) 
		rm -rf $(OBJ_PATH)
		make fclean -sC $(FUN_PATH)

re: fclean all

PHONY.: all clean fclean re norminette bonus
