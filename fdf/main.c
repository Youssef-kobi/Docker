#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>


int		*draw_coor(int x, int y, int xf, int yf)
{
	float coef;
	int *xy;

	xy = (int *)malloc(2 * sizeof(int));
	/*if (xf == x)
	{
		xy[0] = x;
		xy[1] = y + 1;
		return(xy);
	}*/
	coef = (yf - y) / (xf - x);
	coef = fabsf(coef);
	if (coef < 0.5)
	{
		xy[0] = x + 1;
		xy[1] = y + 1;
	}
	else
	{
		xy[0] = x + 1;
		xy[1] = y;
	}
   return(xy);
}   


int main()
{
	void *mlx_ptr;
	void *win_ptr;
	int **data;
	int *xy;
	int *xyf;

	xy = (int *)malloc(2 * sizeof(int));
	xyf = (int *)malloc(2 * sizeof(int));
	xyf[0] = 499;
	xyf[1] = 499;
	xy[0] = 42;
	xy[1] = 120;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "frst draft");
	while (xy[0] != xyf[0] && xy[1] != xyf[1])
	{
		xy = draw_coor(xy[0],xy[1], xyf[0], xyf[1]);
		mlx_pixel_put(mlx_ptr, win_ptr, xy[0], xy[1], 0255000000);
	}
	mlx_loop(mlx_ptr);
}
