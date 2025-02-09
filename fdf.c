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

void draw_line(t_image *img, int x1, int y1, int x2, int y2, int color)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1; // Direzione x
	int sy = (y1 < y2) ? 1 : -1; // Direzione y
	int err = dx - dy;

	while (1)
	{
		// Disegna il punto
		my_mlx_pixel_put(img, x1, y1, color);

		// Se siamo arrivati al punto di destinazione, usciamo
		if (x1 == x2 && y1 == y2)
			break;

		int e2 = err * 2;
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

void iso_projection(int *x, int *y, int z)
{
	int prev_x = *x;
	int prev_y = *y;

	// Applica la proiezione isometrica
	*x = (prev_x - prev_y) * cos(0.523599);  // 0.523599 radianti = 30 gradi
	*y = ((prev_x + prev_y) * sin(0.523599)) - z;
}

void create_imagine(t_mat *mat, t_image img)
{
	int i = 0;
	int j;

	while (mat->mat[i])
	{
		j = 0;
		while (j < mat->x)
		{
			int x = j * 30; // La scala del punto
			int y = i * 30; // La scala del punto
			int z = mat->mat[i][j]; // Altitudine o valore del punto 3D

			// Applica la prospettiva isometrica
			iso_projection(&x, &y, z);

			// Centra i punti nella finestra
			x += 300;
			y += 300;

			// Disegna il punto
			my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);

			// Collega con il punto a destra
			if (j + 1 < mat->x)
			{
				int x2 = (j + 1) * 30;
				int y2 = i * 30;
				int z2 = mat->mat[i][j + 1];

				iso_projection(&x2, &y2, z2);
				x2 += 300;
				y2 += 300;

				// Disegna la linea tra i punti adiacenti orizzontalmente
				draw_line(&img, x, y, x2, y2, 0x00FFFFFF);
			}

			// Collega con il punto in basso
			if (mat->mat[i + 1])
			{
				int x3 = j * 30;
				int y3 = (i + 1) * 30;
				int z3 = mat->mat[i + 1][j];

				iso_projection(&x3, &y3, z3);
				x3 += 300;
				y3 += 300;

				// Disegna la linea tra i punti adiacenti verticalmente
				draw_line(&img, x, y, x3, y3, 0x00FFFFFF);
			}

			j++;
		}
		i++;
	}
}

int	main(void)
{
	void		*mlx;
	void		*win;
	t_image		img;
	t_mat		mat;


	parsing(&mat);
	print_mat(mat);
	// Inizializza MiniLibX
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "FDF");

	// Crea un'immagine vuota
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// Usa create_imagine per disegnare sulla finestra
	create_imagine(&mat, img);

	// Mostra l'immagine sulla finestra
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);

	// Loop principale di MiniLibX
	mlx_loop(mlx);

	return 0;
}

