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
