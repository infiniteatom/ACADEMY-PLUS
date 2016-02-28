/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_fill_it.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 12:35:00 by rbodnare          #+#    #+#             */
/*   Updated: 2015/12/19 12:35:03 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Allocates memory for a matrix and put dots inside
** Works
*/

char	**alloc_matrix(char **matrix, int box)
{
	int		i;
	int		j;

	if (!(matrix = alloc_two_d(box, box)))
		return (NULL);
	i = 0;
	while (i < box)
	{
		j = 0;
		while (j < box)
		{
			matrix[i][j] = '.';
			j++;
		}
		matrix[i][j] = '\0';
		i++;
	}
	return (matrix);
}

/*
** Place the tretriminos in the [x,y] position
** May work
*/

void	placeit(s_fillit obj, int y, int x)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (obj.elem[obj.l][0][j++] != '#')
		x--;
	k = x;
	while (i < 4)
	{
		j = 0;
		//printf("here    2\n");
		//print_matrix(obj.elem[obj.l], 4);
		while (j < 4)
		{
			//print_matrix(obj.matrix, 4);
			//printf("\n");
			if (obj.elem[obj.l][i][j] == '#')
				obj.matrix[y][x] = obj.str[obj.l];
			j++;
			x++;
		}
		i++;
		y++;
		x = k;
	}
}

/*
** Check is the Tetrimino can be placed in [x,y] position
** May work
*/

int		can_be_placed(char **square, char **elem, int y, int x)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (elem[0][j++] != '#')
		x--;
	if (x < 0)
		return (0);
	k = x;
	while (i < 4)
	{
		printf("here    4\n");
		j = 0;
		while (j < 4)
		{
			if (elem[i][j] == '#' && square[y][x] != '.')
				return (0);
			j++;
			x++;
		}
		i++;
		y++;
		x = k;
	}
	printf("\nhere    5\n");
	return (1);
}

/*
** Place the elem where it can
** If the elem was put, returns 1 else returns 0
** May work
*/

int		place(s_fillit obj)
{
	int		x;
	int		y;

	y = 0;
	while (obj.matrix[y])
	{
		printf("here    2\n");
		x = 0;
		while (obj.matrix[y][x])
		{
			if (obj.matrix[y][x] == '.')
			{
				printf("here    3\n");
				if (can_be_placed(obj.matrix, obj.elem[obj.l], y, x))
				{
					placeit(obj, y, x);
					return (1);
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

/*
** Delete the last piece inserted in matrix
*/

void	delete_last(s_fillit obj)
{
	int		x;
	int		y;

	y = 0;
	while (obj.matrix[y])
	{
		x = 0;
		while (obj.matrix[y][x])
		{
			if (obj.matrix[y][x] == obj.str[obj.l - 1])
				obj.matrix[y][x] = '.';
			x++;
		}
		y++;
	}
}

/*
** Fill it!!!
** May work
*/

void	fillit(s_fillit obj, char **matrix)
{
	int		i;

	printf("l = %d\nr = %d\n", obj.l, obj.r);
	printf("str = %s\n", obj.str);
	i = obj.l;
	if (obj.l == obj.r)
	{
		obj.found = 1;
		matrix = obj.matrix;
	}
	else
	{
		while (i < obj.r || !obj.found)
		{
			swap((obj.str + obj.l), (obj.str + i));
			swap_2d((obj.elem[obj.l]), (obj.elem[i]));
			if (place(obj))
			{
				printf("here    1\n");
				obj.l += 1;
				fillit(obj, matrix);
			}
			if (!obj.found)
				delete_last(obj);
			swap((obj.str + obj.l), (obj.str + i));
			swap_2d((obj.elem[obj.l]), (obj.elem[i]));
		}
	}
}

/*
** Alocates memory to fill it. Get it?
** May work
*/

char	**prepare(char ***elem, int min)
{
	s_fillit	obj;
	char		**matrix;
	int			i;

	i = 0;
	while (elem[i])
		i++;
	if (!(obj.str = (char *)malloc(i)))
		return (NULL);
	i = 0;
	while (elem[i])
	{
		obj.str[i] = 'A' + i;
		i++;
	}
	obj.str[i] = '\0';
	obj.l = 0;
	obj.r = i;
	obj.found = 0;
	obj.elem = elem;
	if (!(obj.matrix = alloc_matrix(obj.matrix, min)))
		return (NULL);
	matrix = NULL;
	printf("\n\n");
	fillit(obj, matrix);
	if (matrix)
		return (matrix);
	return (prepare(elem, min + 1));
}
