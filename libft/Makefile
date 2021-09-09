CC=gcc
FLAGS=-Wall -Wextra -Werror
NAME= libft.a
SRCS= ft_atoi.c\
ft_atof.c\
ft_bzero.c\
ft_calloc.c\
ft_isalnum.c\
ft_isalpha.c\
ft_is_stralpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isdouble.c\
ft_isprint.c\
ft_itoa.c\
ft_memccpy.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memmove.c\
ft_memset.c\
ft_putchar_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_putstr_fd.c\
ft_putstr.c\
ft_split.c\
ft_split_charset.c\
ft_strchr.c\
ft_strdup.c\
ft_strjoin.c\
ft_strjoin_free.c\
ft_strlcat.c\
ft_strlcpy.c\
ft_strlen.c\
ft_strmapi.c\
ft_strncmp.c\
ft_strnstr.c\
ft_strrchr.c\
ft_strtrim.c\
ft_substr.c\
ft_tolower.c\
ft_toupper.c\
gnl/get_next_line_utils.c\
gnl/get_next_line.c\
ft_lstadd_back.c\
ft_lstadd_front.c\
ft_lstclear.c\
ft_lstdelone.c\
ft_lstiter.c\
ft_lstlast.c\
ft_lstmap.c\
ft_lstnew.c\
ft_lstsize.c\
ft_lstlen.c\
gnl/get_next_line_utils.c\
gnl/get_next_line.c\
ft_fabs.c


HDS = .
OBJECTS = ${SRCS:.c=.o}

all: $(NAME)

.c.o:
	@${CC} ${FLAGS} -I ${HDS} -I write_bmp/includes -c $< -o ${<:.c=.o}

$(NAME) : ${OBJECTS}
			@make -C ft_printf/
			@ar rcs ${NAME} ${OBJECTS}
			@echo "LIB DONE"

clean:
		@make clean -C ft_printf/
		@rm -rf ${OBJECTS}
		@echo "LIB CLEAN"

fclean: clean
		@rm -rf $(NAME)


re: fclean all