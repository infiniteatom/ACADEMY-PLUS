/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 19:07:38 by rbodnare          #+#    #+#             */
/*   Updated: 2015/10/31 19:07:39 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;

	new = (char *)malloc(ft_strlen(s1) + 1);
	if (new == NULL)
		return (NULL);
	ft_strcpy(new, s1);
	return (new);
}
