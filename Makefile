NAME = Power\ 4
FLAGS = -Wall -Wextra -Werror
SRC =	main.c \
		find_errors.c \
		width_of_array.c \
		height_of_array.c \
		can_play.c \
		unplay.c \
		play.c \
		check_input.c \
		is_map_over.c \
		is_map_won.c \
		create_map.c \
		is_winning_play.c \
		is_winning_play_ai.c \
		count_winning_plays.c \
		find_da_way.c \
		ai_plays.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft/ all
	gcc -g $(OBJ) -o $(NAME) ./libft/libftprintf.a

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

clean:
	make -C ./libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C ./libft/ fclean
	rm -f $(NAME)

re: fclean all
