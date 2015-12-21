/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 19:10:31 by rbodnare          #+#    #+#             */
/*   Updated: 2015/10/31 19:10:32 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	void	*a;

	a = (char*)malloc(size);
	if (a == NULL)
		return (NULL);
	ft_memset(a, '\0', size);
	return (a);
}
