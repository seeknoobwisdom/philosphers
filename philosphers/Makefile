# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsid-ele <zsid-ele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 07:00:24 by zsid-ele          #+#    #+#              #
#    Updated: 2025/04/23 09:15:13 by zsid-ele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror
#CFLAGS += -fsanitize=address

LIB = -lpthread

SRC = \
		./src/philosphers.c \
		./src/start_life.c \
		./src/time.c \
		./src/utils.c \
		./src/ft_atoi.c \
		./src/main.c \

OBJ = $(SRC:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) $< -o $@

$(NAME): $(LIBFT) $(SRC)
		$(CC) $(SRC) $(CFLAGS) $(LIB) -o $(NAME)

all: $(NAME)

clean:
		@rm -rf $(OBJ)

fclean: clean
		@rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re