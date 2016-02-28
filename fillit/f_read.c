/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_read.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 12:42:42 by rbodnare          #+#    #+#             */
/*   Updated: 2015/12/19 12:42:43 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Extract the pieces from a file
*/

char	***extract_pieces(int i, int x, int y, int z)
{
	char	buf[SIZE_PIECES];
	char	***pieces;
	int		fd;

	if (!(pieces = alloc_three_d(19, 4, 4)))
		return (NULL);
	if (!(fd = open(PIECES, O_RDONLY)))
		return (NULL);
	if (!(read(fd, buf, SIZE_PIECES)))
		return (NULL);
	while (buf[i])
	{
		y = 0;
		while (buf[i] != '\n' && buf[i])
		{
			pieces[z][x][y] = buf[i];
			y++;
			i++;
		}
		i++;
		pieces[z][x][y] = '\0';
		x++;
		if (buf[i] == '\n')
		{
			x = 0;
			z++;
			i++;
		}
	}
	return (pieces);
}

/*
** Returns a Tetrimino compresed (without extra slots)
*/

char	**check_type_tetrimino(char *buf, int i)
{
	static char	***pieces = NULL;
	int			z;

	z = 0;
	if (!pieces)
		if (!(pieces = extract_pieces(0, 0, 0, 0)))
			return (NULL);
	while (pieces[z])
	{
		if (compare_tetrimino(buf, pieces[z], i))
			return (pieces[z]);
		z++;
	}
	return (NULL);
}

/*
** Returns the tetriminos
*/

char	***extract_tetriminos(char *buf, int boxes)
{
	char	***tet;
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (!(tet = (char ***)malloc(boxes)))
		return (NULL);
	while (boxes)
	{
		i = j;
		while (buf[i] != '#')
			i++;
		if (!(tet[k] = check_type_tetrimino(buf, i)))
			return (0);
		k++;
		j += 21;
		boxes--;
	}
	while (tet[k])
		tet[k++] = NULL;
	return (tet);
}

/*
** Reads the file and returns the Tetriminos
*/

char	***read_the_tetriminos(char *file, int i, int j)
{
	char	***elem;
	char	buf[SIZE];
	int		boxes;
	int		fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	if (!read(fd, buf, SIZE))
		return (NULL);
	if (!(boxes = validate_boxes(buf, 0, 0, 0)))
		return (NULL);
	if (!(elem = extract_tetriminos(buf, boxes)))
		return (0);
	if (close(fd) < 0)
		return (NULL);
	return (elem);
}
