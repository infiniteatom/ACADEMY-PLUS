/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 19:03:12 by rbodnare          #+#    #+#             */
/*   Updated: 2015/10/31 19:03:14 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
