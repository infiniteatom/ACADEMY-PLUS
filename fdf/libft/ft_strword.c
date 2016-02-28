/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 22:16:43 by rbodnare          #+#    #+#             */
/*   Updated: 2015/11/06 22:16:44 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Reads the number of words splited by a variable
*/

int		ft_strword(const char *s, const char c)
{
	int		count;
	int		arr;

	arr = 0;
	count = 0;
	while (*s != '\0')
	{
		if (arr == 1 && *s == c)
			arr = 0;
		if (arr == 0 && *s != c)
		{
			arr = 1;
			count++;
		}
		s++;
	}
	return (count);
}
