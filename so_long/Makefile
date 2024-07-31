CC = 			cc
CFLAGS = 		-Wall -Wextra -Werror -L./minilibx/ -lmlx -lXext -lX11 -g

RM = 			rm -f

NAME = 			so_long

SO_LONG_SRC = 	srcs/convert_map.c srcs/movement.c srcs/ft_check.c srcs/so_long_utils.c srcs/so_long_mvmt.c srcs/so_long_len_utils.c srcs/so_long_check_utils.c srcs/so_long.c srcs/exit.c\
				srcs/verif_interior.c srcs/ft_printf/ft_printf.c srcs/ft_printf/ft_printf_utils.c srcs/ft_printf/includes/ft_character.c srcs/ft_printf/includes/ft_decimal.c srcs/ft_printf/includes/ft_pointer.c \
				srcs/ft_printf/includes/ft_string.c srcs/ft_printf/includes/ft_tolower_hexadecimal.c srcs/ft_printf/includes/ft_toupper_hexadecimal.c srcs/ft_printf/includes/ft_unsigned_decimal.c \
				srcs/get_next_line/get_next_line.c srcs/get_next_line/get_next_line_utils.c


all :		$(NAME)

mlx :
				@cd minilibx && ./configure

$(NAME) :
				@echo -e '\033[33;32mCreating so_long... 🕗\n'
				@${CC} ${SO_LONG_SRC} ${CFLAGS} -o ${NAME}
				@echo -e '\033[33;32mSo_long created ! 🎉'

re : 			
				@$(RM) $(NAME)
				@echo -e '\033[0;31mSo_long deleted ! 🛑\n'
				@echo -e '\033[33;32mCreating so_long... 🕗\n'
				@${CC} ${SO_LONG_SRC} ${CFLAGS} -o ${NAME}
				@echo -e '\033[33;32mSo_long created ! 🎉'

clean:
				@$(RM) $(NAME)
				@echo -e '\033[0;31mSo_long deleted ! 🛑'

fclean:
				$(RM) $(NAME)
				@echo -e '\033[0;31mSo_long deleted ! 🛑'

.PHONY: 	fclean clean re all

# cc -Wall -Wextra -Werror convert_map.c get_next_line.c get_next_line_utils.c movements.c 
# ft_check.c so_long_utils.c so_long_mvmt.c so_long_len_utils.c so_long_check_utils.c so_long.c 
# -L/home/judenis/sgoinfre/judenis/42projects/so_long/minilibx/ -lmlx -lXext -lX11 -o a.out