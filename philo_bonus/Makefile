NAME = philo_bonus
HEADER = philo_bonus.h
SRC = philo_bonus libft utils_01 utils_00 action_bonus
OBJ = $(addsuffix .o, $(SRC))
CFLAGS = -Werror -Wextra -Wall
GCC = cc

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(GCC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c $(HEADER)
	$(GCC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re