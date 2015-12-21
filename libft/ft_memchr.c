/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 19:02:10 by rbodnare          #+#    #+#             */
/*   Updated: 2015/10/31 19:02:12 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*src;
	char		d;

	src = (const char *)s;
	d = c;
	while (n)
	{
		if (*src == d)
			return ((void *)src);
		src++;
		n--;
	}
	return (0);
}
