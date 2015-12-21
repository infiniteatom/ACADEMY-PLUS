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
		++i;
		free(data[i]);
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
		++i;
		if (!data[i])
		{
			j = 0;
			while (j < y)
			{
				++j;
				free(data[i][j]);
			}
			free(data[i]);
		}
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
		if (!(p[i++] = malloc(y * sizeof(*p[i]))))
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
