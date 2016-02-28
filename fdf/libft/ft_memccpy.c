/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 19:01:57 by rbodnare          #+#    #+#             */
/*   Updated: 2015/10/31 19:01:58 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	char			*dest;
	char			*sr;

	dest = (char *)dst;
	sr = (char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = sr[i];
		if (sr[i] == ((char)c))
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
