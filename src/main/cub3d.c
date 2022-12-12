#include "../../include/cub3d.h"

int main()
{
    t_cub3d *cub3d;

    cub3d = (t_cub3d *)malloc(sizeof(t_cub3d));
    cub3d->mlx = mlx_init();
    cub3d->win = mlx_new_window(cub3d->mlx, 1920, 1080, "cub3d");
    mlx_loop(cub3d->mlx);
    // printf("Hello World! \n");
}
