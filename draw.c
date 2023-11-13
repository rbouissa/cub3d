#include"cub3d.h"

void            my_mlx_pixel_put(t_cub *data, int x, int y, int color)
{
  char    *dst;

  dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
  *(unsigned int*)dst = color;
}

void draw_line_orientation(t_cub *cub,int x,int y)
{
    int i =0;
    int j =0;

    while(i<40)
    {
        j=0;
        while(j<2)
        {
            my_mlx_pixel_put(cub,(x*SIZE) + i,j + (y *SIZE),0x00000);
            j++;
        }
        i++;
    }
}

int rendring_minimap(t_cub *cub)
{
    double k;
    mlx_clear_window(cub->mlx, cub->window);
    //draw_map(cub);
    draw_player_position(cub,cub->player.x,cub->player.y);
    rays(cub);
    //k=calcul_distance(cub);

    //printf("------->%f\n",k);
    mlx_put_image_to_window(cub->mlx, cub->window, cub->img, 0, 0);
    return(0);
}

void draw_wall(t_cub *cub,int x,int y)
{
    int i =0;
    int j =0;

    while(i<40)
    {
        j=0;
        while(j<40)
        {
            my_mlx_pixel_put(cub,(x*SIZE) + i,j + (y *SIZE),0xFC3939);
            j++;
        }
        i++;
    }
}

void draw_colone(t_cub *cub,int x,int y)
{
    int i =0;
    int j =0;

    while(i<2)
    {
        j=0;
        while(j<40)
        {
            my_mlx_pixel_put(cub,(x*SIZE) + i,j + (y *SIZE),0X0000);
            j++;
        }
        i++;
    }
}

void draw_line(t_cub *cub,int x,int y)
{
    int i =0;
    int j =0;

    while(i<40)
    {
        j=0;
        while(j<2)
        {
            my_mlx_pixel_put(cub,(x*SIZE) + i,j + (y *SIZE),0X0000);
            j++;
        }
        i++;
    }
}

void draw_empty(t_cub *cub,int x,int y)
{
    int i =0;
    int j =0;

    while(i<40)
    {
        j=0;
        while(j<40)
        {
            my_mlx_pixel_put(cub,(x*SIZE) + i,j + (y *SIZE),0x007DA8);
            j++;
        }
        i++;
    }
}

void draw_player_position(t_cub *cub,int x,int y)
{
    int i =0;
    int j =0;
  //  ("x = %d\n",cub->x);
  //  printf("y = %d\n",cub->y);

//   printf("x = %f\n",cub->player.x);
//     printf("y = %f\n",cub->player.y);
   // exit(0);
    while(i< 10)
    {
        j= 0 ;
        while(j< 10)
        {
            my_mlx_pixel_put(cub,cub->player.x +i,j + cub->player.y,0XFBFF00);
            j++;
        }
        
        i++;
    }
}

void draw_map(t_cub *cub)
{
    int i = 0;
    int j = 0;

    while(cub->map[i])
    {
        j = 0;
        while(cub->map[i][j])
        {
            if(cub->map[i][j]=='1')
            {
                draw_wall(cub,j,i);
                draw_colone(cub,j,i);
                draw_line(cub,j,i);
            }
            if(cub->map[i][j] == '0')
            {
                draw_empty(cub,j,i);
                draw_colone(cub,j,i);
                draw_line(cub,j,i);
            }
            if(cub->map[i][j]=='N' || cub->map[i][j]=='S' || cub->map[i][j]=='W' || cub->map[i][j]=='E')
            {
                draw_empty(cub,j,i);
                draw_colone(cub,j,i);
                draw_line(cub,j,i);
            }
            j++;
        }
        i++;
    }
}

//void fill_ort_move()
// void draw_angle(t_cub *cub)
// {
    
// }
// void draw_line1(void *mlx_ptr, void *win_ptr, int x1, int y1, int x2, int y2, int color) {
//     int dx = abs(x2 - x1);
//     int dy = abs(y2 - y1);
//     int sx = (x1 < x2) ? 1 : -1;
//     int sy = (y1 < y2) ? 1 : -1;
//     int err = dx - dy;

//     while (1) {
//         mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, color);

//         if (x1 == x2 && y1 == y2)
//             break;

//         int e2 = 2 * err;
//         if (e2 > -dy) {
//             err -= dy;
//             x1 += sx;
//         }
//         if (e2 < dx) {
//             err += dx;
//             y1 += sy;
//         }
//     }
// }
