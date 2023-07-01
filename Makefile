NAME	=	push_swap

SRCS	=	ft_atoi.c			\
			ft_check.c			\
			ft_fill_index.c		\
			ft_free.c			\
			ft_mediane.c		\
			ft_movements1.c		\
			ft_movements2.c		\
			ft_sort_4_5_6.c		\
			ft_sort_three.c		\
			ft_sort.c			\
			ft_stack.c			\
			ft_utils.c			\
			push_swap.c			\
			ft_sort_three_back.c

CC		=	clang

FLAGS	=	-Wall -Wextra -Werror

OBJS	=	$(SRCS:.c=.o)

$(NAME)	:	$(OBJS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

all		:	$(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
