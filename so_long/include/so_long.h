/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judenis <judenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:53:35 by judenis           #+#    #+#             */
/*   Updated: 2024/03/19 15:30:04 by judenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define SIZE 100

# include "../minilibx/mlx.h"
# include <X11/X.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_len
{
}			t_len;

typedef struct s_vars
{
	int		lenline;
	int		lastline;
	int		compteur;
	char	*filename;

	int		mvmt;
	char	*nb;

	void	*mlx;
	void	*win;

	void	*img_char;
	void	*img_wall;
	void	*img_ground;
	void	*img_coin;
	void	*img_exit;
	void	*img_char_exit;

	int		x1;
	int		y1;

	int		win_xsize;
	int		win_ysize;

	int		width;
	int		height;

	int		max_coin;
	int		coin;

	int		c_verif_interior;
	int		e_verif_interior;

	char	**map;

}			t_vars;

char		*get_next_line(int fd);

//* ft_printf utils
int			ft_printf(const char *format, ...);
int			cas_par_cas(const char *format, int i, va_list field);
void		ft_putstr(const char *str);
size_t		ft_strlen(const char *str);
void		ft_putchar(char c);
int			ft_hex_len(unsigned int num);

int			ft_character(char c);
int			ft_string(char *str);
int			ft_pointer(unsigned long long ptr);
int			ft_decimal(int nb);
int			ft_unsigned_decimal(unsigned int nb);
int			ft_tolower_hexadecimal(unsigned int nb);
int			ft_toupper_hexadecimal(unsigned int nb);

//* gnl utils
char		*ft_strdup(const char *src);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *str);

//* so_long utils
void		len_init(char *filename, t_vars *vars);
void		vars_init(t_vars *vars);

int			ft_check(t_vars *vars);
int			key_release(int jsp, t_vars *vars);
int			ft_verif(t_vars *vars);
int			ft_verif_img(t_vars *vars);
int			verif_filename(char *filename);

int			ft_strchr_x_base(char **map, char obj_cherche);
int			ft_strchr_y_base(char **map, char obj_cherche);
int			ft_strrchr_verif(t_vars *vars, char searched_obj);

char		*ft_itoa(int n);

//* so_long len
int			ft_lastline(char *filename);
int			ft_lenline(char *filename);

//* so_long convert
char		**convert(t_vars *vars);

//* so_long mvmt
int			key_hook(int keycode, t_vars *vars);
int			move_up(t_vars *vars);
int			move_left(t_vars *vars);
int			move_down(t_vars *vars);
int			move_right(t_vars *vars);

int			check_line(char *line, int compteur, t_vars *vars);

int			launch_prog(t_vars *vars);
void		put_walls(t_vars *vars);

//* so_long exit
int			ft_free_map(t_vars *vars, char **map);
int			ft_exit(t_vars *vars);
int			ft_exit_img(t_vars *vars);
int			ft_free_map_int(t_vars *vars, int **map);

int	ft_strchr_x(t_vars *vars, char searched_obj);
int	ft_strchr_y(t_vars *vars, char searched_obj);

void		ft_verif_interior_map(t_vars *vars);

#endif