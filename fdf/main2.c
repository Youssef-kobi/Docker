#include "mlx.h"
#include "fdf.h"

int main(int argc, char **argv)
{
	void *mlx_ptr;
	void *win_ptr;
	int **data;

	data = read_file(argv[1]);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "frst draft");
	while (x++ < 500 && y-- > 0)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0255000000);
	}
	mlx_loop(mlx_ptr);
}
