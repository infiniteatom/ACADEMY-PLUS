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

typedef struct	t_fillit
{
	char	***elem;
	char	**matrix;
	char	*str;
	int		found;
	int		l;
	int		r;
}				s_fillit;

/*
** Extra functions
*/

int		print_error(void);
void	*ft_memset(void *b, int c, size_t len);
void	swap(char *a, char *b);
void	swap_2d_ext(char **a, char **b);
void	swap_2d(char **a, char **b);
void	print_matrix(char **square, int size);

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

char	**alloc_matrix(char **matrix, int box);
void	placeit(s_fillit obj, int y, int x);
int		can_be_placed(char **square, char **elem, int x, int y);
int		place(s_fillit obj);
void	delete_last(s_fillit obj);
void	fillit(s_fillit obj, char **matrix);
char	**prepare(char ***elem, int min);

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
