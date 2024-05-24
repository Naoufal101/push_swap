FILES = add_back.c big_sort.c check_input.c commands.c fill_list.c ft_fix.c \
		ft_push_a.c ft_push_b.c ft_quick_sort.c moves_calculation.c perfect_move.c push_swap.c

BFILES = bonus/add_back_bonus.c bonus/check_input_bonus.c bonus/checker_bonus.c bonus/commands2_bonus.c bonus/commands_bonus.c \
		bonus/fill_list_bonus.c get_next_line/get_next_line_utils.c get_next_line/get_next_line.c

NAME = push_swap
INC = libft/
LIBRARY = libft.a
HEADER = push_swap.h
BTARGET = checker

CFLAGS = -Wall -Werror -Wextra
OFILES = $(FILES:.c=.o)
BOFILES = $(BFILES:.c=.o)

all: $(NAME)
bonus: $(BTARGET)

$(LIBRARY):
	@make -C $(INC) all clean

$(NAME): $(LIBRARY) $(OFILES) $(HEADER)
	$(CC) $(OFILES) $(LIBRARY) -o $(NAME)

$(BTARGET): $(LIBRARY) $(BOFILES) 
	$(CC) $(BOFILES) $(LIBRARY) -o $(BTARGET)

clean:
	$(RM) $(OFILES) $(BOFILES)

fclean: clean
	$(RM) $(NAME) $(BTARGET) $(LIBRARY)

re: fclean all