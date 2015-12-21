/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 13:02:56 by rbodnare          #+#    #+#             */
/*   Updated: 2015/12/19 13:02:58 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	***elem;
	int		box;
	//char	**matrix;
	if (argc != 2)
		return (print_error());
	if (!(elem = read_the_tetriminos(argv[1], 0, 0)))
		return (print_error());
	printf("\nread_the_tetriminos() works\n");
	if (!(box = min_box_size(elem)))
		return (print_error());
	printf("minumum size of the box = %d\n", box);
	//matrix = prepare(elem, box);
	//print_matrix(matrix);
	printf("\n");
	return (0);
}
