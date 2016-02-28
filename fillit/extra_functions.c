/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 12:29:33 by rbodnare          #+#    #+#             */
/*   Updated: 2015/12/19 12:29:36 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Extra functions
*/

int		print_error(void)
{
	printf("error\n");
	return (0);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	w;

	p = (unsigned char *)b;
	w = (unsigned char)c;
	while (len > 0)
	{
		*p = w;
		p++;
		len--;
	}
	return (b);
}

void 	swap(char *a, char *b)
{
	int		t;

	t = *a;
	*a = *b;
	*b = t;
}

void	swap_2d_ext(char **a, char **b)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			a[i][j] = b[i][j];
			j++;
		}
		a[i][j] = '\0';
		i++;
	}
}

void	swap_2d(char **a, char **b)
{
	char	**c;

	c = alloc_two_d(4, 4);
	swap_2d_ext(c, a);
	swap_2d_ext(a, b);
	swap_2d_ext(b, c);
	free_two_d(c, 4);
}


void	print_matrix(char **square, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			write(1, &square[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
