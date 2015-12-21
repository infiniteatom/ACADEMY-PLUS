/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 19:09:06 by rbodnare          #+#    #+#             */
/*   Updated: 2015/12/21 18:44:18 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*map;

	i = 0;
	if (!s && !f)
		return (NULL);
	map = (char*)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (map == NULL)
		return (NULL);
	while (s[i])
	{
		map[i] = f(s[i]);
		i++;
	}
	map[i] = '\0';
	return (map);
}
