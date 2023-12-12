CFILES = push_swap.c check_input.c
OBJS = ${CFILES:.c=.o}
RM = rm -rf
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap.a
FTPRINTFA = ./ft_printf/libftprintf.a
FTPRINTFD = ./ft_printf

all: $(NAME)

$(OBJS): $(CFILES)
	$(CC) $(CFLAGS) -c $(CFILES)

$(NAME): $(OBJS) $(FTPRINTFA) 
	cp $(FTPRINTFA) $(NAME)
	ar vrcs $(NAME) $(OBJS)

$(FTPRINTFA): $(FTPRINTFD)
	make -C $(FTPRINTFD)

clean:
	$(RM) $(OBJS)
	make clean -C $(FTPRINTFD)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(FTPRINTFD)

re: fclean all