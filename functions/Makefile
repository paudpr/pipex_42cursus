# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdel-pin <pdel-pin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/15 17:17:08 by pdel-pin          #+#    #+#              #
#    Updated: 2022/04/12 14:59:56 by pdel-pin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fun.a

SRCS	=	ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_strlcpy.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_split.c \
		ft_substr.c \
		ft_calloc.c \
		ft_strchr.c \
		get_next_line.c \


OBJS	=	$(SRCS:.c=.o)

BONUS_OBJS	=	$(BONUS:.c=.o)

CFLAGS	= -Wall -Werror -Wextra

CC	=	gcc

RM	= rm -f

.c.o:	$(cc) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(BONUS_OBJS)
		ar rc $(NAME) $(OBJS) $(BONUS_OBJS)

bonus: $(BONUS_OBJS)
		ar rc $(NAME) $(BONUS_OBJS)

all: $(NAME)

clean: 
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

PHONY.: all clean fclean re