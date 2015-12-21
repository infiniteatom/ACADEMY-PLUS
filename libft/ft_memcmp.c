/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 19:02:21 by rbodnare          #+#    #+#             */
/*   Updated: 2015/10/31 19:02:22 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*dst;
	const unsigned char	*src;

	dst = (const unsigned char *)s1;
	src = (const unsigned char *)s2;
	if (!n)
		return (0);
	while (--n && *dst == *src)
	{
		++dst;
		++src;
	}
	return (*dst - *src);
}
