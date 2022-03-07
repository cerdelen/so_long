# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 17:13:17 by Cerdelen          #+#    #+#              #
#    Updated: 2022/03/04 15:38:53 by Cerdelen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wextra -Wall -Werror

AR = ar rcs

NAME = get_next_line.a

SRCS = 	get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)


$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJS): 
	$(CC) $(CFLAGS) -D BUFFER_SIZE=42 -c $(SRCS)

all: $(NAME)

bonus: fclean $(OBJS_B) $(OBJS)
	$(AR) $(NAME) $(OBJS_B) $(OBJS)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME) 

re: fclean all
