/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 19:11:14 by rbodnare          #+#    #+#             */
/*   Updated: 2015/12/21 18:51:02 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strwordb(const char *s, char c, int start)
{
	int		i;

	i = 0;
	while (s[start] && s[start] != c)
	{
		start++;
		i++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**dest;
	int		words;
	int		index;
	int		i;
	int		next;

	i = 0;
	index = 0;
	if (!s)
		return (NULL);
	words = ft_strword(s, (const char)c);
	if (!(dest = (char **)malloc(sizeof(*dest) * (words + 1))))
		return (NULL);
	while (words--)
	{
		while (s[i] == c)
			i++;
		next = strwordb(s, c, i);
		if (!(dest[index] = ft_strsub(s, i, next)))
			return (NULL);
		i += next;
		index++;
	}
	dest[index] = NULL;
	return (dest);
}
