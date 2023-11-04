#include"cub3d.h"

void arg_check(char *v,int c)
{
    char *s = ".cub";
    int i =0;
    int j =0;
    if(c!=2)
    {
        printf("INVALID NUMBER OF ARGUMENT!\n");
        exit(1);
    }
    i = ft_strlen(v) -4;
    while(s[j] && v[i])
    {
        if(s[j]!=v[i])
           (printf("INVALID MAP NAME\n"),exit(1));
        j++;
        i++;
    }
}

void empty_file(char *v)
{
	int i =0;
	
    if(v==NULL)
        (printf("Error\nOops!Empty File!\n"),exit(1));
	while(v[i])
	{
		if(v[i]!=' '&& v[i]!='	' && v[i]!='\n')
			return;
		i++;
	}
	(printf("Error\nOops!Empty File!\n"),exit(1));
}
void	empty_line(char v)
{
	if (v == '\n')
	{
		printf("Error\n---MAP HAVE EMPTY LINE IN THE LAST LINE---\n");
		exit(1);
	}
}
int check_empty_space(char *v)
{
	int i=0;
	
	while(v[i] && (v[i]==' '||v[i]=='	'||v[i]=='\n'))
		i++;
	if(i==ft_strlen(v))
		return(1);
	
	return(0);
}
int skip_space(char *v)
{
	int i=0;
	
	while(v[i] && (v[i]==' '||v[i]=='	'))
		i++;
	return(i);
}
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		i++;
	}
	write(fd, s, i);
}


void check_RGB(char *rgb,t_cub *cub)
{
	int i = 0;
	int count = 0;
	int j = 0;
	int k = 0;
	int nb = 0;
	i = skip_space(rgb);	
	while(rgb[i])
	{
		if(rgb[i]==',')
			count++;
		i++;
	}
	if(count!=2)
		error_msg("Oops!Invalid RGB!\n");
	i = skip_space(rgb);
	char **n = ft_split(rgb + i,',');
	//printf
	i =0;
	while(n[i])
		i++;
	if(i!=3)
		error_msg("Oops!Invalid RGB!\n");
	i = 0;
	while(n[i])
	{
		j = 0;
		while(n[i][j])
		{
			if(n[i][j]<'0' || n[i][j]>'9')
			{
				
				if(i==2 && j==ft_strlen(n[i])-1)
				{
					if(n[i][j]=='\n')
						break;
				}
				error_msg("Oops!Invalid RGB!\n");
			}
			j++;
		}
		i++;
	}
	i =-1;
	while(n[++i])
		check_nb_rgb(n[i]);
	i = 0;
	cub->f_rgb =(ft_atoi(n[0]) << 16) | (ft_atoi(n[1]) << 8) | ft_atoi(n[2]);
}
void check_nb_rgb(char *s)
{
	int nb = 0;

	nb = ft_atoi(s);
	if(nb<0 || nb>255)
		error_msg("---Oops!Invalid RGB!---\n");
}

void check_around_zero(char **map,int i,int j,int k)
{
	if(map[i][j+1]==' ' || map[i][j-1]==' ' || map[i+1][j]==' ' || map[i-1][j]==' ')
	{
		//printf("--->>%d\n",j);
		//printf("-----%c\n",map[i][j]);
		error_msg("====Oops!Map Has An Error!\n");
	}
	
}
void map_checking(char **map)
{
	int i = 0;
	int j = 0;
	int count = 0;
	int count2 = 0;
	int k =0;
	while(map[count2])
		count2++;
	j = skip_space(map[i]);
	//printf("*****%s\n",map[i]);
	while(map[i][j])
	{
		if(map[i][j]!='1' && map[i][j]!=' ')
			error_msg("@@@@Oops!Map Should surrounded by wall!\n");
		j++;
	}
	j = 0;
	i = 0;
	while(map[i])
	{
		j = skip_space(map[i]);
		k = j;
		//printf("++%s\n",map[i]);
		while(map[i][j])
		{
			if(map[i][k] != '1' || map[i][ft_strlen(map[i])-1]!='1')
			{
				//printf("-----%c\n",map[i][j]);
				error_msg("------Oops!Map Should surrounded by wall!\n");
			}
			if(map[i][j]=='S' || map[i][j]=='N' || map[i][j]=='W' || map[i][j]=='E')
				count++;
			if(map[i][j] != '1' && map[i][j]!='0' && map[i][j] !=' ' && map[i][j]!='S' && map[i][j]!='N' && map[i][j]!='W' && map[i][j]!='E')
				error_msg("Oops!Invalid Character in Map!\n");
			if(map[i][j]=='0')
			{
				//printf("-----%c\n",map[i][j-4]);
				//printf("dddddd\n");
				check_around_zero(map,i,j,k);
			}
			j++;
		}
		if(map[i][j]=='\0')
		{
			printf("[%d]\n",j-1);
			if(map[i+1] && ft_strlen(map[i+1])>j-1)
			{
				if(map[i+1] && map[i+1][j-1]!='\0' && map[i+1][j-1]!='1')
				{
					if(map[i+1][j]!='1')
						error_msg("=##===Oops!Map Has error!\n");
				}
			}
		}
		if(i==count2-1)
		{	
			j = 0;
			while(map[i][j])
			{
				if(map[i][j]!='1' && map[i][j]!=' ')
					error_msg("==---==Oops!Map Should surrounded by wall!\n");
				j++;
			}
		}
		i++;
	}
	if(count!=1)
			error_msg("***Oops!Invalid Character in Map!\n");
}