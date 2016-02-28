/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 18:59:31 by rbodnare          #+#    #+#             */
/*   Updated: 2015/10/31 18:59:32 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*extension(unsigned int weight, char *str, int n, int i)
{
	while (weight >= 1)
	{
		str[i++] = (n / weight % 10) + 48;
		weight /= 10;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	int				len;
	int				i;
	unsigned int	weight;
	char			*str;

	len = 0;
	i = 0;
	weight = 1;
	if (n < 0)
	{
		len = 1;
		n = -n;
		i = 1;
	}
	while (n / weight > 9)
	{
		weight *= 10;
		len++;
	}
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (i > 0)
		str[0] = '-';
	return (extension(weight, str, n, i));
}
