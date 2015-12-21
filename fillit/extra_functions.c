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

void	print_matrix(char **square)
{
	int		i;
	int		j;

	i = 0;
	while (square[i])
	{
		j = 0;
		while (square[i][j])
		{
			write(1, &square[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
