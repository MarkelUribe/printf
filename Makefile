# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 16:04:16 by muribe-l          #+#    #+#              #
#    Updated: 2024/01/12 13:24:31 by muribe-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = ft_printf.c functions.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = ar rcs
RM = rm -rf
LIBFTNAME = libft.a
LIBFTDIR = ./libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFTDIR)/$(LIBFTNAME):
	make -C $(LIBFTDIR)

$(NAME): $(OBJECTS) $(LIBFTDIR)/$(LIBFTNAME)
	$(LIB) $(NAME) $(OBJECTS)
	$(LIB) $(NAME) $(LIBFTDIR)/*.o

all: $(NAME)

clean:
	$(RM) $(OBJECTS)
	make clean -C $(LIBFTDIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY:	all clean fclean re