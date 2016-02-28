/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_memory_allocation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 12:32:35 by rbodnare          #+#    #+#             */
/*   Updated: 2015/12/19 12:32:36 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Elibarates the 2D data
*/

void	free_two_d(char **data, char x)
{
	int		i;

	i = 0;
	while (i < x)
	{
		free(data[i]);
		i++;
	}
	free(data);
}

/*
** Elibarates the 3D data
*/

void	free_three_d(char ***data, char x, char y)
{
	int		i;
	int		j;

	i = 0;
	while (i < x)
	{
		if (!data[i])
		{
			j = 0;
			while (j < y)
			{
				free(data[i][j]);
				i++;
			}
			free(data[i]);
		}
		i++;
	}
	free(data);
}

/*
** Allocates 2D memory
*/

char	**alloc_two_d(char x, char y)
{
	char	**p;
	int		i;

	if (!(p = malloc(x * sizeof(*p))))
		return (NULL);
	i = 0;
	while (i < x)
		p[i++] = NULL;
	i = 0;
	while (i < x)
		if (!(p[i++] = malloc(sizeof(*p[i]) * (y + 1))))
		{
			free_two_d(p, x);
			return (NULL);
		}
	return (p);
}

/*
** Allocates 3D memory
*/

char	***alloc_three_d(char x, char y, char z)
{
	char	***p;
	int		i;

	if (!(p = malloc(x * sizeof(*p))))
		return (NULL);
	i = 0;
	while (i < x)
		p[i++] = NULL;
	i = 0;
	while (i < x)
		if (!(p[i++] = alloc_two_d(y, z)))
		{
			free_three_d(p, x, y);
			return (NULL);
		}
	return (p);
}
