CFILES = main.c check_input.c init_stack.c stack_utils.c swap.c rotate_rr.c rotate_r.c sort_three.c
OBJS = ${CFILES:.c=.o}
RM = rm -rf
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap
FTPRINTFA = ./ft_printf/libftprintf.a
FTPRINTFD = ./ft_printf

all: $(NAME)

$(NAME): $(OBJS) $(FTPRINTFA) 
	$(CC) $(CFLAGS) $(OBJS) $(FTPRINTFA) -o $(NAME)

$(FTPRINTFA): $(FTPRINTFD)
	make -C $(FTPRINTFD)

clean:
	$(RM) $(OBJS)
	make clean -C $(FTPRINTFD)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(FTPRINTFD)

re: fclean all