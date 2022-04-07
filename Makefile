NAME = pipex

LIBFT_NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra
CFLAGS += -I $(INC_PATH) -I $(LIBFT_PATH)

LDFLAGS = -L $(LIBFT_PATH)
LDLIBS = -lft

LIBFT_PATH	= libft
INC_PATH	= includes
SRC_PATH	= sources
OBJ_PATH	= objects

SRC =	main.c \
		utils.c \
		path.c \
		access.c \
		pipex.c \
		
		



all: $(NAME)

##-L is used to include paths where the linker will look for libraries
##-l is used to link a library, which must be passed without the lib prefix and the extension
## -p para crear directorios uno dentro del otro

OBJS_NAME = $(SRC:%.c=%.o)

##addprefix "coge" el segundo argumento y el path del primer argumento. funciona como un while añadiendo paths a cada source
SRCS_NAME = $(addprefix $(SRC_PATH)/, $(SRC))

OBJS =  $(addprefix $(OBJ_PATH)/, $(OBJS_NAME))

$(OBJ_PATH):
			mkdir -p $(OBJ_PATH) 2> /dev/null

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
			$(CC) $(CFLAGS) -c $< -o $@

			
##s es para silenciar y C para que vaya al directorio
##	make -sC $(LIBFT_PATH)

##el | está para evitar que haga relink
##otra solución sería copiar la orden de $(LIBFT_NAME) para ejecutar antes de la compilación (dentro de $(NAME))
$(NAME): $(OBJS)
		make -C $(LIBFT_PATH)
		$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS) $(LDLIBS)
## $(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(addprefix $(LIBFT_PATH)/, $(LIBFT_NAME))

$(LIBFT_NAME):
			$(MAKE) all -sC $(LIBFT_PATH)

##RULES

$(MAKE): make

debug: CFLAGS += -fsanitize=address -g3
debug: $(NAME)

norminette:
	norminette $(SRCS) 

clean: 
	rm $(NAME) 
	rm -rf $(OBJ_PATH)
	make clean -sC $(LIBFT_PATH)

fclean: clean
		rm -rf $(NAME) 
		rm -rf $(OBJ_PATH)
		make fclean -sC $(LIBFT_PATH)

re: fclean all

PHONY.: all clean fclean re norminette
