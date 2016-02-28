/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 19:07:05 by rbodnare          #+#    #+#             */
/*   Updated: 2015/10/31 19:07:06 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned const char *str1;
	unsigned const char *str2;

	str1 = (unsigned const char *)s1;
	str2 = (unsigned const char *)s2;
	while (*str1 && *str1 == *str2)
	{
		++str1;
		++str2;
	}
	return (*str1 - *str2);
}
