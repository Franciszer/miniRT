CCFLAGS = gcc -Wall -Wextra -Werror

NAME = ../libft.a

SRC = read/ft_get_param.c\
	read/ft_is_arg.c\
	read/ft_is_flag.c\
	read/ft_is_specifier.c\
	read/ft_paramlen.c\
	read/ft_check_param.c\
	read/ft_init_param.c\
	read/ft_get_flags.c\
	write/ft_print.c\
	write/ft_print_lwidprec.c\
	write/ft_print_param.c\
	write/ft_print_str.c\
	write/ft_print_widprec.c\
	write/ft_write_hex.c\
	write/ft_write_int.c\
	write/ft_write_memory.c\
	write/ft_write_param.c\
	write/ft_write_str.c\
	write/ft_write_uint.c\
	write/ft_pstrlen.c\
	write/ft_print_memory.c\
	write/ft_print_char.c\
	write/ft_only_widprec.c\
	write/ft_write_percentage.c\
	write/ft_print_hex.c\
	ft_printf.c

HEADER = .

OBJ = ${SRC:.c=.o}

all: ${NAME}

.c.o:
	@${CCFLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	@ar rcs ${NAME} ${OBJ}

clean:
	@rm -rf ${OBJ}

fclean:	
	@rm -rf ${OBJ}
	@rm -rf ${NAME}

re:	fclean all

.PHONY:	all libft clean fclean re
