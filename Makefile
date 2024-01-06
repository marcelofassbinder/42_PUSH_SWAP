CFILES = check_functions.c init_stack.c stack_utils.c swap.c rotate_rr.c rotate_r.c push.c algorithm.c \
update_nodes.c set_functions.c find_functions.c
OBJS = ${CFILES:.c=.o}
RM = rm -rf
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap
FTPRINTFA = ./ft_printf/libftprintf.a
FTPRINTFD = ./ft_printf

BONUS = ./bonus/checker.c ./bonus/checker_utils.c ./bonus/get_next_line/get_next_line.c ./bonus/get_next_line/get_next_line_utils.c 
OBJSB = ${BONUS:.c=.o}
CHECKER = checker

all: $(NAME)

$(NAME): $(OBJS) $(FTPRINTFA) 
	$(CC) $(CFLAGS) main.c $(OBJS) $(FTPRINTFA) -o $(NAME)

$(FTPRINTFA): $(FTPRINTFD)
	make -C $(FTPRINTFD) 

bonus: $(NAME) $(OBJSB)
	$(CC) $(CFLAGS) $(OBJS) $(OBJSB) $(FTPRINTFA) -o $(CHECKER)

clean:
	$(RM) $(OBJS) $(OBJSB) main.o
	make clean -C $(FTPRINTFD) 

fclean: clean
	$(RM) $(NAME) $(CHECKER)
	make fclean -C $(FTPRINTFD) 

re: fclean all