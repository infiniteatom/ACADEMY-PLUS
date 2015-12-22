/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpyn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 20:23:08 by rbodnare          #+#    #+#             */
/*   Updated: 2015/11/06 20:23:12 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the string starting from 'i'
*/

char	*ft_strcpyn(const char *dest, int i)
{
	char	*a;
	int		j;

	j = 0;
	a = (char *)malloc(ft_strlen(dest) - i);
	while (dest[i])
		a[j++] = dest[i++];
	a[j] = '\0';
	return (a);
}
