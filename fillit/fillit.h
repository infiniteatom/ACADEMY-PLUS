/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 12:01:16 by rbodnare          #+#    #+#             */
/*   Updated: 2015/12/19 12:01:19 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define SIZE ((26 * 5 * 4) + 25)
# define SIZE_PIECES (22 * 4 * 4)
# define PIECES "pieces.txt"

/*
** Extra functions
*/

int		print_error(void);
void	*ft_memset(void *b, int c, size_t len);
void	print_matrix(char **square);

/*
** Functions for memory allocation
*/

void	free_two_d(char **data, char x);
void	free_three_d(char ***data, char x, char y);
char	**alloc_two_d(char x, char y);
char	***alloc_three_d(char x, char y, char z);

/*
** Functions to fill it
*/

int		can_be_placed(char **square, char **elem, int x, int y);
char	**fillit(char **matrix, char ***elem, int box);
char	**prepare(char ***elem, int min);
int		min_box_size(char ***elem);

/*
** Functions for validating
*/

int		compare_tetrimino(char *buf, char **piece, int n);
int		extra_a(char *buf, int *i, int *j, int *n);
int		validate_boxes(char *buf, int i, int k, int n);

/*
** Functions for reading
*/

char	***extract_pieces(int i, int x, int y, int z);
char	**check_type_tetrimino(char *buf, int i);
char	***extract_tetriminos(char *buf, int boxes);
char	***read_the_tetriminos(char *file, int i, int j);

#endif
