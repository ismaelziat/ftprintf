NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCS = ft_printf_aux.c \
	ft_printf.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) ${OBJS_BONUS}


fclean: clean
	rm -f $(NAME)


re: fclean all


.PHONY: all clean fclean re
