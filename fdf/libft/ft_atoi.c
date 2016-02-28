/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 18:56:56 by rbodnare          #+#    #+#             */
/*   Updated: 2015/10/31 18:57:04 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int k;
	int neg;

	k = 0;
	neg = 0;
	while (ft_isspace((int)*str) == 1)
		str++;
	if (*str == '-')
	{
		neg = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		k = k * 10 + (*str) - '0';
		str++;
	}
	if (neg)
		k = -k;
	return (k);
}
