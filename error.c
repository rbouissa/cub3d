#include"cub3d.h"

void error_msg(char *msg)
{
	
	ft_putstr_fd("Error\n",2);
	ft_putstr_fd(msg,2);
	exit(1);
}