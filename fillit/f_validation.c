/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_validation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 12:40:38 by rbodnare          #+#    #+#             */
/*   Updated: 2015/12/19 12:40:41 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Compares two tetriminos and returns 0 or 1
*/

int		compare_tetrimino(char *buf, char **piece, int n)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	j = 0;
	x = 0;
	while (piece[j][i] != '#')
		i++;
	n -= i;
	while (x < 4)
	{
		y = 0;
		while (piece[x][y])
			if (piece[x][y++] != buf[n++])
				return (0);
		n += 5 - y;
		x++;
	}
	return (1);
}

/*
** Validates and returns the nr of Tetriminos
*/

int		extra_a(char *buf, int *i, int *j, int *n)
{
	*j = 0;
	while (*j < 4)
	{
		if (buf[*i + *j] != '.' && buf[*i + *j] != '#')
			return (0);
		if (buf[*i + *j] == '#')
			*n += 1;
		*j += 1;
	}
	*i += *j;
	return (1);
}

int		validate_boxes(char *buf, int i, int k, int n)
{
	int		j;

	j = 0;
	while (buf[i])
	{
		if (!(extra_a(buf, &i, &j, &n)))
			return (0);
		if (++k % 4 == 0)
		{
			if (buf[i] != '\n' || n != 4)
				return (0);
			if (!buf[++i])
				return (k / 4);
			n = 0;
		}
		if (buf[i++] != '\n')
			return (0);
	}
	return (0);
}
