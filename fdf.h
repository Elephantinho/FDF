/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:12:16 by mshahein          #+#    #+#             */
/*   Updated: 2025/03/01 12:17:04 by mshahein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"
# include <unistd.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <math.h>
# include <X11/keysymdef.h>
# include <X11/keysym.h>

# define WIN_X 1500
# define WIN_Y 1500

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

// Struttura per gestire l'immagine
typedef struct s_image
{
	void	*img; // L'immagine
	char	*addr; // L'indirizzo dell'immagine
	int		bits_per_pixel; // Bit per pixel
	int		line_length; // Lunghezza della linea
	int		endian; // Endian
}			t_image;

// Struttura per gestire la matrice
typedef struct s_mat
{
	int	**mat;	//	La matrice dei punti della mappa
	int	x;	//	Numero di colonne
	int	y;	//	Numero di righe
}		t_mat;

// Struttura per gestire la finestra
typedef struct s_window
{
	void		*mlx;
	void		*win;
	t_image		img;
	t_mat		mat;
	double		angle_x;
	double		angle_y;
	int			zoom;
	int			offset_x;
	int			offset_y;
	int			win_x;
	int			win_y;
}				t_window;

// Struttura per gestire i dati dell'immagine
typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}		t_point;

typedef struct s_point_3
{
	t_point	p1;
	t_point	p2;
	t_point	p3;
}	t_point_3;

typedef struct s_iter
{
	int	i;
	int	j;
}	t_iter;

typedef struct s_drawing_context
{
	t_mat		*mat;// La matrice dei punti della mappa
	t_image		*img;// L'immagine in cui disegnare
	t_window	*qwe;// La finestra e le sue impostazioni
	int			scale;// Lo zoom (scala)
}	t_drawing_context;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_bresenham;

// Funzione per mettere un pixel nell'immagine
void	my_mlx_pixel_put(t_image *img, int x, int y, int color);

// Funzioni per la proiezione isometrica
void	iso_projection(int *x, int *y, int z, t_window *qwe);

// Funzioni per la gestione dei punti
int		scale(t_window *qwe);
void	ft_set(t_point *p, int offset_x, int offset_y);
void	ft_start_point(t_point *p, int x, int y, int z);
void	ft_start_point4(t_point *p, t_iter iter, int s, int mat);
void	ft_start_point2(t_point *p, t_iter iter, int s, int mat);
void	ft_start_point3(t_point *p, t_iter iter, int s, int mat);

// Funzioni per disegnare i punti
void	draw_current_point(t_drawing_context *ctx, t_point_3 *p1, t_iter iter);
void	draw_horizont_line(t_drawing_context *ctx, t_point_3 *p1, t_iter iter);
void	draw_vertical_line(t_drawing_context *ctx, t_point_3 *p1, t_iter iter);

// Funzione principale per creare l'immagine
void	create_imagine(t_mat *mat, t_image img, t_window *qwe);

// Algortimo di Bresenham
void	calculate_dx_dy(t_point p1, t_point p2, t_bresenham *bresenham);
void	calculate_step(t_point p1, t_point p2, t_bresenham *bresenham);
void	calculate_error(t_bresenham *bresenham);
void	draw_point(t_image *img, t_point p, int color);
void	draw_line(t_image *img, t_point p1, t_point p2, int color);

// Funzioni per il parsing
void	check_name(char *filename);
void	ft_check_line_columns(int fd, int first_line);
void	ft_check_nbr_col(char *filename);
int		mat_len(char **tmp);
void	free_int_matrix(int **mat);
int		*char_int(char **tmp, int size);
void	*ft_realloc(void *ptr, size_t size_old, size_t size_new);
void	parsing(t_mat *mat, char *filename);

// Funzioni per la chiusura del programma
int		close_window(void *param);
int		key_press(int keycode, t_window *qwe);
int		handle_input(t_window *qwe);

#endif
