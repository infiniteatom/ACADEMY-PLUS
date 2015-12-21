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
** Check is the Tetrimino can be placed in [x,y] position
** May not work
*/

int		can_be_placed(char **square, char **elem, int x, int y)
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
	while (elem[i])
	{
		j = 0;
		while (elem[i][j])
			if (elem[i][j++] == '#' && square[y][x++] == '#')
				return (0);
		i++;
		y++;
		x = k;
	}
	return (1);
}

/*
** Allocates memory for a matrix and put dots inside
*/

char	**alloc_matrix(char **matrix, int box)
{
	int		i;

	if (!(matrix = (char **)malloc(box * sizeof(char *))))
		return (NULL);
	i = 0;
	while (i < box)
	{
		if (!(matrix[i] = ft_memset((void *)matrix, '.', (size_t)box)))
			return (NULL);
		i++;
	}
	return (matrix);
}

/*
** Fill it!!!
*/

char	**fillit(char matrix[][], char ***elem, int y, int x)
{
	char	**matrix_out;

	if (matrix[y][x])
	{
		if (can_be_placed(matrix, *elem, x, y))
		{
			place_it(matrix, *elem, x, y);
			fillit(matrix, elem, x, y);
		}
		else
			fillit(matrix, elem, y, x++);
	}
	else
		fillit(matrix, elem, y, x);
	matrix_out = alloc_matrix(matrix_out, box);
	return (matrix_out);
}

/*
** Alocates memory to fill it. Get it?
*/

char	**prepare(char ***elem, int min)
{
	char	**matrix;
	char	a[min][min];

	matrix = NULL;
	if (!(matrix = fillit(a, elem, 0, 0)))
		prepare(elem, min + 1);
	return (matrix);
}

/*
** Calculate the minimum size of the box that can be
*/

int		min_box_size(char ***elem)
{
	int		n;
	int		i;

	i = 0;
	n = 0;
	while (elem[n])
		n++;
	n *= 4;
	while ((i * i) < n)
		i++;
	return (i);
}
