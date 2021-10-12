# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agautier <agautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 19:41:58 by agautier          #+#    #+#              #
#    Updated: 2021/10/13 01:50:19 by agautier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philosophers
SRC			=	$(wildcard $(addprefix src/, $(addsuffix .c, */*))) \
				$(wildcard $(addprefix src/, $(addsuffix .c, *)))
OBJ			=	$(SRC:.c=.o)
CC			=	gcc
HEADER		=	-Iheader
CFLAGS		=	-Wall -Wextra -Werror -g3 -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(HEADER) $(LIB) -o $@ $(OBJ) -pthread

%.o: %.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re

