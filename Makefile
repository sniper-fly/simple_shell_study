NAME = lsh

CC = gcc
CFLAGS = -I./incl -Wall -Wextra -Werror -fsanitize=address -g

SRCS = ${shell find ./src -type f -name "*.c"}
OBJS = $(addprefix objects/, $(notdir $(SRCS:.c=.o)))
# OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

objects/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

.PHONY: all clean fclean
