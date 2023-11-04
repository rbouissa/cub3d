#include "cub3d.h"

void rays(t_cub *pos)
{
    int x;
    int y;
    x=pos->player.x;
    y=pos->player.y;
    int i =0;
    while(i <5)
    {
        my_mlx_pixel_put(pos, x, y, 0x00FF00AA);
        x += cos(pos->orientation);
        y += sin(pos->orientation);
        i++;
    }
}