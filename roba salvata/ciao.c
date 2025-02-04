void create_image(t_mat *mat, t_image *img)
{
    int i = 0;
    while (mat->mat[i])
    {
        int j = 0;
        while (j < mat->x)
        {
            int x = j * mat->display.pixel_size;
            int y = i * mat->display.pixel_size;
            int z = mat->mat[i][j];

            iso_projection(&x, &y, z, mat->display.width, mat->display.height);

            // Disegna il punto
            my_mlx_pixel_put(img, x, y, 0x00FFFFFF);

            // Collega con il punto a destra
            if (j + 1 < mat->x)
            {
                int x2 = (j + 1) * mat->display.pixel_size;
                int y2 = i * mat->display.pixel_size;
                int z2 = mat->mat[i][j + 1];
                iso_projection(&x2, &y2, z2, mat->display.width, mat->display.height);
                draw_line(img, x, y, x2, y2, 0x00FFFFFF);
            }

            // Collega con il punto in basso
            if (mat->mat[i + 1])
            {
                int x3 = j * mat->display.pixel_size;
                int y3 = (i + 1) * mat->display.pixel_size;
                int z3 = mat->mat[i + 1][j];
                iso_projection(&x3, &y3, z3, mat->display.width, mat->display.height);
                draw_line(img, x, y, x3, y3, 0x00FFFFFF);
            }
            j++;
        }
        i++;
    }
}