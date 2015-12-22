/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 19:11:46 by rbodnare          #+#    #+#             */
/*   Updated: 2015/10/31 19:11:47 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*a;

	i = 0;
	if (s == NULL)
		return (NULL);
	a = (char*)malloc(sizeof(char) * (len + 1));
	if (a == NULL)
		return (NULL);
	while (len && s[start + i])
	{
		a[i] = s[start + i];
		len--;
		i++;
	}
	a[i] = '\0';
	return (a);
}
