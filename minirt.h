/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frthierr <frthierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 09:58:48 by frthierr          #+#    #+#             */
/*   Updated: 2020/02/22 18:59:53 by frthierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H

# define MINIRT_H

# include "libft/libft.h"
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <stdarg.h>
# include <errno.h>
# include "mlx.h"
# include "Sources/Error/minirt_error.h"
# include "Sources/Parse/parse_rt.h"
# define EPS 0.001

# ifndef M_PI
#  define M_PI 3.14159265359
# endif

# define LIGHT_MULTIPLIER 10000
# define MAXX 2560
# define MAXY 1440
# define BMPPATH "/Users/frthierr/studlife/miniRT/Images/"
# define SCENES "Scenes/"
# define IMG_DIR "Images/"
# define INIT_D -1

/*
**	OBJ_STRUCTURES
*/

typedef	struct		s_vec3
{
	double		x;
	double		y;
	double		z;
}					t_vec3;

typedef	struct		s_res
{
	int			x;
	int			y;
}					t_res;

typedef	struct		s_alight
{
	double			brightness;
	unsigned char	rgb[3];
}					t_alight;

typedef	struct		s_light
{
	t_vec3			o;
	double			brightness;
	unsigned char	rgb[3];
}					t_light;

typedef	struct		s_cam
{
	t_vec3			o;
	t_vec3			d;
	double			fov;
}					t_cam;

typedef	struct		s_sphere
{
	t_vec3			c;
	double			diameter;
	unsigned char	rgb[3];
}					t_sphere;

typedef	struct		s_plane
{
	t_vec3			o;
	t_vec3			d;
	unsigned char	rgb[3];
}					t_plane;

typedef	struct		s_square
{
	t_vec3			o;
	t_vec3			n;
	unsigned char	rgb[3];
	double			side;
}					t_square;

typedef	struct		s_cyl
{
	t_vec3			o;
	t_vec3			d;
	double			r;
	double			h;
	unsigned char	rgb[3];
}					t_cyl;

typedef	struct		s_tri
{
	t_vec3			a;
	t_vec3			b;
	t_vec3			c;
	unsigned char	rgb[3];
}					t_tri;

typedef struct		s_obj
{
	t_res		*res;
	t_list		*cam_list;
	t_list		*alight_list;
	t_list		*light_list;
	t_list		*sphere_list;
	t_list		*plane_list;
	t_list		*cyl_list;
	t_list		*tri_list;
	t_list		*inter_list;
}					t_obj;

typedef struct		s_canvas
{
	t_vec3	o;
	t_vec3	**screen;
}					t_canvas;

typedef struct		s_inter
{
	t_vec3			point;
	t_vec3			o;
	double			d_to_o;
	t_vec3			normal;
	unsigned char	rgb[3];
}					t_inter;

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	t_obj			*obj;
	t_inter			**inter;
	int				*inter_n;
	unsigned char	*cols;
}					t_data;

/*
**	PARSING
*/

char				**get_file_rt(char *filename);
int					check_line_rt(char **line, int n_line);
t_obj				*parse_rt(char *filename);
void				*free_return(void **p);
void				*free_obj_rt(t_obj *obj);
void				*free_strtab(char **file);
t_vec3				**free_canvas(t_vec3 **canvas, int h_max);
void				*exit_parse_rt(char *msg, t_obj *obj, char **file);
int					get_vals_rt(char **file, int i, int id, t_obj *obj);
int					get_res(double *vals, t_obj *obj);
int					get_cam(double *vals, t_obj *obj);
int					get_res(double *vals, t_obj *obj);
int					get_cam(double *vals, t_obj *obj);
int					get_alight(double *vals, t_obj *obj);
int					get_light(double *vals, t_obj *obj);
int					get_sphere(double *vals, t_obj *obj);
int					get_plane(double *vals, t_obj *obj);
int					get_cyl(double *vals, t_obj *obj);
int					get_triangle(double *vals, t_obj *obj);
int					get_square(double *vals, t_obj *obj);
int					checkfull_rt(t_obj *obj);
int					check_alight(t_list *list);
int					check_cam(t_list *list);
int					check_light(t_list *list);
int					check_plane(t_list *list);
int					check_cyl(t_list *list);
int					is_rtfile(char *filename);

/*
**	VECTOR_3 UTILS
*/

double				dot(t_vec3 v, t_vec3 w);
t_vec3				get_vec3(double x, double y, double z);
double				norm(t_vec3 v);
double				norm2(t_vec3 v);
t_vec3				normalize(t_vec3 v);
t_vec3				op_vec3(t_vec3 v, char op, t_vec3 w);
t_vec3				opf_vec3(t_vec3 v, char op, double f);
t_vec3				cross_vec3(t_vec3 v, t_vec3 w);
t_vec3				rot_vec3(t_vec3 o, t_vec3 dir, t_vec3 rot);
t_vec3				get_axis(t_vec3 u, t_vec3 normal);

/*
**	3D INTERSECTIONS
*/

t_vec3				**get_canvas_rt(t_cam *cam, t_obj *obj);
t_inter				get_inter(t_vec3 point, t_vec3 o, int id, void *obj_inter);
void				get_inter_sphere(t_inter *inter, void *obj_inter, t_vec3 o);
void				get_inter_plane(t_inter *inter, void *obj_inter, t_vec3 o);
void				get_inter_tri(t_inter *inter, void *obj_inter, t_vec3 o);
void				get_norm_cyl(t_inter *inter, t_cyl *cyl, t_vec3 o);
void				get_inter_cyl(t_inter *inter, void *obj_inter, t_vec3 o);
t_inter				**get_inter_screen(int w, int h);
t_inter				sphere_iter(t_list *sphere_list, t_vec3\
					cam_o, t_vec3 d, t_inter inter_min);
t_inter				sphere_inter(t_sphere *s, t_vec3 cam_o, t_vec3 d);
t_inter				tri_iter(t_list *tri_list, t_vec3 cam_o,\
					t_vec3 d, t_inter inter_min);
t_inter				tri_inter(t_tri *tri, t_vec3 o,\
					t_vec3 d);
t_inter				plane_iter(t_list *plane_list, t_vec3 cam_o,\
					t_vec3 d, t_inter inter_min);
t_inter				plane_inter(t_plane *plane, t_vec3 cam_o, t_vec3 d);
t_inter				cyl_iter(t_list *cyl_list, t_vec3 cam_o,\
					t_vec3 d, t_inter inter_min);
t_inter				cyl_inter(t_cyl *cyl, t_vec3 cam_o, t_vec3 d);
t_inter				**inter_rt(t_obj *obj, t_cam *cam, t_canvas canvas);
int					rgb_to_int(unsigned char rgb0,\
					unsigned char rgb1, unsigned char rgb2);
t_inter				**free_inter(t_inter **inter, int h_max);
void				free_inter_list(t_list *list, t_obj *obj);

/*
**	LIGHT
*/

void				get_canvas_light(t_obj *obj, int w, int h, t_inter **inter);
void				light_pixel(t_obj *obj, t_inter *inter);
int					is_clearpath(t_obj *obj, t_vec3 o, t_light *light);
t_inter				plane_iter_light(t_list *plane_list,\
t_vec3				cam_o, t_vec3 d, t_inter inter_min);
t_inter				plane_inter_light(t_plane *plane, t_vec3 cam_o, t_vec3 d);

/*
**	IMAGE
*/

t_inter				**get_colors_rt(t_obj *obj);
int					get_inters_rt(t_obj *obj);
t_inter				**which_inter(t_list *inter_list, int *n);
int					display_rt(t_obj *obj);
void				get_img_rt(unsigned char *colors, t_obj *obj,\
						t_inter **inter, t_data *data);
int					manage_key(int key, void *param);
int					write_bmp(t_obj *obj);
int					writebmp(int w, int h, char *img_data);
unsigned char		*inter_to_char(t_obj *obj, t_inter **inter);
int					save_image_rt(t_obj *obj);

#endif
