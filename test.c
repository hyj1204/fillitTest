#include "fillit.h"
#include <stdio.h>
int	ft_check_point(char **tet, int *ycnt, int *xcnt)
{
	int x;
	int y;

	y = -1;
	while (tet[++y] != NULL)
	{
		x = -1;
		while (tet[y][++x] != '\0')
		{
			if (tet[y][x] != '.')
			{
				if (*ycnt > y)
					*ycnt = y;
			}
		}
	}
	if (*ycnt == 4)
		return (-1);
	else
	{
		x = -1;
		while (tet[*ycnt][++x])
		{
			if (tet[*ycnt][x] != '.')
				if (*xcnt > x)
					*xcnt = x;
		}
	}
	return (1);
}

void	ft_get_xy(char **p, int *x, int *y)
{
	int	co_x;
	int	co_y;
	int loop_x;
	int	loop_y;
	int	index;

	co_x = 4;
	co_y = 4;
    ft_check_point(p, &co_x, &co_y);
    loop_x = co_x;
    index = 0;
    ft_get_xy_helper(p, x, y, co_x, co_y);
	
	x[index] = co_x;
	y[index] = co_y;
}

void	ft_get_xy_helper(char **p, int *x, int *y, int	co_x, int co_y)
{
	int	loop_x;
	int	loop_y;
	int	index;
	
	loop_x =co_x;
	loop_y = 0;
	index = 0;
	while (p[loop_x] && index < 4)
	{
		loop_y = -1;
		while (p[loop_x][++loop_y] && index < 4)
		{
			if (p[loop_x][loop_y] == '#')
			{
				x[index] = loop_x - co_x;
				y[index] = loop_y - co_y;
				index++;
			}
		}
		loop_x++;
	}
	x[index] = co_x;
	y[index] = co_y;
}

// void	ft_get_xy(char **p, int *x, int *y)
// {
// 	int	co_x;
// 	int	co_y;
// 	int loop_x;
// 	int	loop_y;
// 	int	index;

// 	co_x = 4;
// 	co_y = 4;
//     ft_check_point(p, &co_x, &co_y);
//     loop_x = co_x;
//     index = 0;
// 	while (p[loop_x] && index < 4)
// 	{
// 		loop_y = 0;
// 		while (p[loop_x][loop_y] && index < 4)
// 		{
// 			if (p[loop_x][loop_y] == '#')
// 			{
// 				x[index] = loop_x - co_x;
// 				y[index] = loop_y - co_y;
// 				index++;
// 			}
// 			loop_y++;
// 		}
// 		loop_x++;
// 	}
// 	x[index] = co_x;
// 	y[index] = co_y;
// }

/*void	ft_get_xy(char **p, int *x, int *y)
{
	int	val[5];

	val[0] = 4;
	val[1] = 4;
	ft_check_point(p, &val[0], &val[1]);
	val[2] = val[0];
	val[4] = 0;
	while (p[val[2]] && val[4] < 4)
	{
		val[3] = 0;
		while (p[val[2]][val[3]] && val[4] < 4)
		{
			if (p[val[2]][val[3]] == '#')
			{
				x[val[4]] = val[2] - val[0];
				x[val[4]] = val[3] - val[1];
				val[4]++;
			}
			val[3]++;
		}
		val[2]++;
	}
	x[val[4]] = val[0];
	y[val[4]] = val[1];
}*/

int	main()
{
	char	**tet = ft_create_board(4);
	int	x[4];
	int y[4];

	tet[0][1] = '#';
	tet[0][2] = '#';
	tet[0][0] = '#';
	tet[0][3] = '#';
	ft_get_xy(tet, x, y);
	printf("x3 = %d, y3 = %d\n", x[3], y[3]);
	return (0);
}
