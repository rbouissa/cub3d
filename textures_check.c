#include"cub3d.h"

int check_NO(char *v)
{
	int i =0;
	while(v[i] &&(v[i]==' '||v[i]=='	'))
		i++;
	if(v[i]!=' '&& v[i]!='	')
	{
		if(v[i]=='N'&&v[i+1]=='O'&& v[i+2]==' ')
			return(i+3);
	}
	return(0);
}
int check_SO(char *v)
{
	int i =0;
	while(v[i] &&(v[i]==' '||v[i]=='	'))
		i++;
	if(v[i]!=' '&& v[i]!='	')
		if(v[i]=='S'&&v[i+1]=='O'&& v[i+2]==' ')
			return(i+3);
	return(0);
}
int check_WE(char *v)
{
	int i =0;
	while(v[i] &&(v[i]==' '||v[i]=='	'))
		i++;
	if(v[i]!=' '&& v[i]!='	')
		if(v[i]=='W'&&v[i+1]=='E'&& v[i+2]==' ')
			return(i+3);
	return(0);
}
int check_EA(char *v)
{
	int i =0;
	while(v[i] &&(v[i]==' '||v[i]=='	'))
		i++;
	if(v[i]!=' '&& v[i]!='	')
		if(v[i]=='E'&&v[i+1]=='A'&& v[i+2]==' ')
			return(i+3);
	return(0);
}
int check_F(char *v)
{
	int i =0;
	while(v[i] &&(v[i]==' '||v[i]=='	'))
		i++;
	if(v[i]!=' '&& v[i]!='	')
		if(v[i]=='F'&&v[i+1]==' ')
			return(i+2);
	return(0);
}
int check_C(char *v)
{
	int i =0;
	while(v[i] &&(v[i]==' '||v[i]=='	'))
		i++;
	if(v[i]!=' '&& v[i]!='	')
		if(v[i]=='C'&&v[i+1]==' ')
			return(i+2);
	return(0);
}
