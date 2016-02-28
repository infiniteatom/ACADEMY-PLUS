/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 19:03:04 by rbodnare          #+#    #+#             */
/*   Updated: 2015/10/31 19:03:05 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst1;
	const char	*src1;

	dst1 = dst;
	src1 = src;
	if (src1 < dst1 && dst1 < src1 + len)
	{
		src1 += len;
		dst1 += len;
		while (len--)
			*--dst1 = *--src1;
		return (dst);
	}
	return (ft_memcpy(dst, src, len));
}
