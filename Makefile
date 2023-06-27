# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 10:15:26 by jakgonza          #+#    #+#              #
#    Updated: 2023/06/27 09:09:18 by jakgonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a
CFLAGS = -g -Wall -Werror -Wextra
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)


%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

clean:
	rm -f $(OBJS)
	@echo "Object files removed"

fclean: clean
	rm -f $(NAME)
	@echo "Library removed"

re: fclean all

.PHONY: all clean fclean re