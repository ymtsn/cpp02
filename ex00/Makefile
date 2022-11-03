CC		= g++

CFLAGS	= -Wall -Wextra -Werror -std=c++98

NAME	= a.out

SRCS	= main.cpp Fixed.cpp

OBJS	= $(SRCS:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS):$(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME)

re:
	fclean
	all

.PHONY:all clean fclean re
