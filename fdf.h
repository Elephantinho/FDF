#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include <unistd.h>
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include <math.h>


#define COS_30 0.866
#define SIN_30 0.5
// Struttura per la gestione delle informazioni della finestra
typedef struct s_display
{
    int width;           // Larghezza della finestra
    int height;          // Altezza della finestra
    int pixel_size;      // Dimensione di ogni pixel
    int projection_type; // Tipo di proiezione (ad esempio, 1 per isometrica)
    int offset_x; // Aggiungi questo campo per l'offset orizzontale
    int offset_y; // Aggiungi questo campo per l'offset verticale
}               t_display;

// Struttura per gestire i dati dell'immagine
typedef struct s_image
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_image;

// Struttura per la matrice della mappa
typedef struct s_mat
{
    int        **mat;      // La matrice dei punti della mappa
    int        x;          // Numero di colonne
    int        y;          // Numero di righe
    t_display  display;    // Dettagli per la visualizzazione
}               t_mat;

void    parsing(t_mat *mat);
void    print_mat(t_mat mat);
//void    iso_projection(int *x, int *y, int z, t_display *display);
void    create_image(t_mat *mat, t_image *img);
void    my_mlx_pixel_put(t_image *data, int x, int y, int color);
//void    draw_line(t_image *img, int x1, int y1, int x2, int y2, int color);
#endif

