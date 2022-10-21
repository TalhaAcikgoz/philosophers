NAME = philo

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g -pthread

CC = gcc

RM = rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o philo

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean re fclean all
