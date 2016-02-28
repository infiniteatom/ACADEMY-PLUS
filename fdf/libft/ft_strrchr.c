/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 19:11:01 by rbodnare          #+#    #+#             */
/*   Updated: 2015/10/31 19:11:02 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		ch;
	const char	*found;

	ch = (char)c;
	found = 0;
	if (!ch)
		return (char *)s + ft_strlen(s);
	while ((s = ft_strchr(s, c)))
		found = s++;
	return ((char *)found);
}
