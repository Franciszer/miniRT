# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/24 18:23:30 by franciszer        #+#    #+#              #
#    Updated: 2020/02/22 19:35:56 by frthierr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	Sources/Error/print_error.c\
		Sources/Parse/get_file_rt.c\
		Sources/Parse/check_line_rt.c\
		Sources/Parse/parse_rt.c\
		Sources/Parse/exit_parse_rt.c\
		Sources/Parse/get_vals_rt.c\
		Sources/Parse/Get_obj/get_obj0.c\
		Sources/Parse/Get_obj/get_obj1.c\
		Sources/Parse/Get_obj/get_square.c\
		Sources/Parse/checkfull_rt/checkfull_rt.c\
		Sources/Parse/checkfull_rt/ckeckfull_obj.c\
		Sources/Utils_vec3/dot.c\
		Sources/Utils_vec3/get_vec3.c\
		Sources/Utils_vec3/norm_vec3.c\
		Sources/Utils_vec3/op_vec3.c\
		Sources/Utils_vec3/opf_vec3.c\
		Sources/Utils_vec3/normalize.c\
		Sources/Utils_vec3/cross_vec3.c\
		Sources/Utils_vec3/rot_vec3.c\
		Sources/Utils_vec3/get_axis.c\
		Sources/Canvas/get_canvas.c\
		Sources/Intersections/inter_utils.c\
		Sources/Intersections/inter_rt.c\
		Sources/Intersections/get_inter_obj.c\
		Sources/Intersections/sphere_inter.c\
		Sources/Intersections/plane_inter.c\
		Sources/Intersections/tri_inter.c\
		Sources/Intersections/cyl_inter.c\
		Sources/MLX/get_img_rt.c\
		Sources/MLX/which_inter.c\
		Sources/Canvas/inter_to_char.c\
		Sources/Canvas/write_bmp.c\
		Sources/Intersections/Light/get_pixel_light.c
		
LIB = libft/libft.a

OBJ = ${SRC:.c=.o}

INC = .

FLAGS= -Wall -Wextra -Werror

NAME = miniRT.a

XNAME = miniRT

.c.o:
	@cc ${FLAGS} -I ${INC} -c $< -o ${<:.c=.o}

all: ${XNAME}

${XNAME}: ${OBJ}
			@make -C libft
			@cc ${FLAGS} -I ./libft -I . -I /usr/local/include -L /usr/local/lib -lmlx  -framework OpenGL -framework Appkit ${OBJ} Sources/main.c ${LIB} -o ${XNAME}
			@echo "MiniRT Done Yeah"
clean:
	@rm -rf ${OBJ}
	@make -C libft/ clean
	@echo "miniRT clean"

fclean:	clean
		@rm -rf ${XNAME}
		@rm -rf ${LIB}

re: fclean all