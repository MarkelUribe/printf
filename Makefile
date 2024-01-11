# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 16:04:16 by muribe-l          #+#    #+#              #
#    Updated: 2024/01/11 16:32:23 by muribe-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f

NAME = libftprintf.a
.SILENT:
SOURCES = ft_printf.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDE)
	$(LIB) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus