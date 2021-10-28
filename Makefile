# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agautier <agautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 19:41:58 by agautier          #+#    #+#              #
#    Updated: 2021/10/28 16:07:57 by agautier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

S			=	src/
O			=	obj/
I			=	header/
D			=	dep/

SRC			=	$(wildcard $(addprefix $S, $(addsuffix .c, */*))) \
				$(wildcard $(addprefix $S, $(addsuffix .c, *)))

OBJ			=	$(SRC:$S%.c=$O%.o)
DEP			=	$(SRC:$S%.c=$D%.d)

CC			=	gcc

CFLAGS		+=	-I$I
CFLAGS		+=	-Wall -Wextra -Werror
CFLAGS		+=	-g3 -fsanitize=thread
CFLAGS		+=	-pthread

LDFLAGS		+=	-g3 -fsanitize=thread

RM			=	/bin/rm -f
RMDIR		=	/bin/rm -Rf

.PHONY:	all clean fclean re

all: $(NAME)

$O:
	@mkdir -p $@

$(OBJ): | $O

$(OBJ): $O%.o: $S%.c
	$(CC) $(CFLAGS) -c $< -o $@

$D:
	@mkdir -p $@

$(DEP): | $D

$(DEP): $D%.d: $S%.c
	$(CC) $(CFLAGS) -MM -MF $@ -MT "$O$*.o $@" $<

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	$(RM) $(wildcard $(OBJ))
	$(RMDIR) $O
	$(RM) $(wildcard $(DEP))
	$(RMDIR) $D

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEP)
