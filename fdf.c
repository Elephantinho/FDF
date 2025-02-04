#include "fdf.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	if (x < 0 || x >= 1000 || y < 0 || y >= 1000) // Evita accessi fuori dai limiti
		return;

	char	*dst;
	int		byte_per_pixel;
	int		vertical_offset;
	int		horizontal_offset;

	byte_per_pixel = data->bits_per_pixel / 8;
	vertical_offset = y * data->line_length;
	horizontal_offset = x * byte_per_pixel;
	dst = data->addr + (vertical_offset + horizontal_offset);
	*(unsigned int*)dst = color;
}

float calculate_scale(t_mat *mat, int width, int height)
{
    float map_width = mat->x * mat->display.pixel_size * cos(0.523599) +
                      mat->y * mat->display.pixel_size * cos(0.523599);
    float map_height = mat->x * mat->display.pixel_size * sin(0.523599) +
                       mat->y * mat->display.pixel_size * sin(0.523599);

    float scale_x = width / map_width;
    float scale_y = height / map_height;

    return fmin(scale_x, scale_y); // Usa il valore più piccolo per adattare tutto
}



void scale_and_center(int *x, int *y, t_mat *mat, float scale, int width, int height)
{
    *x *= scale;
    *y *= scale;

    int map_width = (mat->x * mat->display.pixel_size * cos(0.523599) +
                     mat->y * mat->display.pixel_size * cos(0.523599)) * scale;
    int map_height = (mat->x * mat->display.pixel_size * sin(0.523599) +
                      mat->y * mat->display.pixel_size * sin(0.523599)) * scale;

    int offset_x = (width - map_width) / 2;
    int offset_y = (height - map_height) / 2;

    *x += offset_x;
    *y += offset_y;
}




void iso_projection(int *x, int *y, int z)
{
    int prev_x = *x;
    int prev_y = *y;

    // Applica la proiezione isometrica
    *x = (prev_x - prev_y) * cos(0.523599);  // 0.523599 radianti = 30 gradi
    *y = ((prev_x + prev_y) * sin(0.523599)) - z;
}

void	draw_line(t_image *img, int x1, int y1, int x2, int y2, int color)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy;

	while (x1 != x2 || y1 != y2)
	{
		my_mlx_pixel_put(img, x1, y1, color);
		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void create_image(t_mat *mat, t_image *img)
{
    float scale = calculate_scale(mat, mat->display.width, mat->display.height);

    int i = 0;
    while (mat->mat[i])
    {
        int j = 0;
        while (j < mat->x)
        {
            int x = j * mat->display.pixel_size;
            int y = i * mat->display.pixel_size;
            int z = mat->mat[i][j];

            // Scala e centra le coordinate
            scale_and_center(&x, &y, mat, scale, mat->display.width, mat->display.height);

            // Applica la proiezione isometrica
            iso_projection(&x, &y, z);

            // Disegna il punto
            my_mlx_pixel_put(img, x, y, 0x00FFFFFF);

            // Collega con il punto a destra
            if (j + 1 < mat->x)
            {
                int x2 = (j + 1) * mat->display.pixel_size;
                int y2 = i * mat->display.pixel_size;
                int z2 = mat->mat[i][j + 1];

                scale_and_center(&x2, &y2, mat, scale, mat->display.width, mat->display.height);
                iso_projection(&x2, &y2, z2);

                draw_line(img, x, y, x2, y2, 0x00FFFFFF);
            }

            // Collega con il punto in basso
            if (mat->mat[i + 1])
            {
                int x3 = j * mat->display.pixel_size;
                int y3 = (i + 1) * mat->display.pixel_size;
                int z3 = mat->mat[i + 1][j];

                scale_and_center(&x3, &y3, mat, scale, mat->display.width, mat->display.height);
                iso_projection(&x3, &y3, z3);

                draw_line(img, x, y, x3, y3, 0x00FFFFFF);
            }
            j++;
        }
        i++;
    }
}










int main(void)
{
    void *mlx;
    void *mlx_win;
    t_image img;
    t_mat mat;

    // Parsing della matrice (carica i dati della mappa da un file o altra fonte)
    parsing(&mat);
    print_mat(mat);

    // Inizializzazione di mlx
    mlx = mlx_init();

    // Impostazioni per la finestra e la visualizzazione
    mat.display.width = 1920;          // Larghezza della finestra
    mat.display.height = 1080;         // Altezza della finestra
    mat.display.pixel_size = 30;       // Dimensione di ogni pixel (può essere modificata a piacere)
    mat.display.projection_type = 1;   // Tipo di proiezione (ad esempio, 1 per isometrica)

    // Creazione della finestra
    mlx_win = mlx_new_window(mlx, mat.display.width, mat.display.height, "FDF - 3D Map");

    // Creazione dell'immagine
    img.img = mlx_new_image(mlx, mat.display.width, mat.display.height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    // Creazione e disegno della mappa
    create_image(&mat, &img);

    // Mostra l'immagine nella finestra
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

    // Avvia il ciclo di eventi
    mlx_loop(mlx);

    return (0);
}

