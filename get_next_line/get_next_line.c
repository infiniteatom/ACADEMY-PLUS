/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 20:32:49 by rbodnare          #+#    #+#             */
/*   Updated: 2015/12/22 20:32:50 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	has_new_line(char *s)
{
	char *a;
	
	a = s;
	while (*a != 0)
	{
		if (*a == '\n')
			return (1);
		a++;
	}
	return (0);
}

static char	*create_line(char **buff)
{
	int		i;
	char	*l;
	
	i = 0;
	l = (char*)malloc(100000000);
	while (**buff != '\n' && **buff != 0)
	{
		l[i] = **buff;
		i++;
		*buff = *buff + 1;
	}
	return (l);
}

int			get_next_line(const int fd, char **s)
{
	static char	*buff;
	char		*line;
	int			rd;
	
	if (fd < 0 || s == NULL)
		return (-1);
	*s = (char*)malloc(100000000);
	if (!buff)
		buff = (char*)malloc(100000000);
	if (*buff == '\n')
		buff++;
	line = (char*)malloc(100000000);
	rd = read(fd, buff + ft_strlen(buff), BUFF_SIZE);
	if (rd < 0)
		return (-1);
	while (rd > 0 && !has_new_line(buff))
		rd = read(fd, buff + ft_strlen(buff), BUFF_SIZE);
	line = create_line(&buff);
	*s = ft_strcpy(*s, line);
	if (rd == 0 && line[0] == 0 && *buff == 0)
		return (0);
	return (1);
}
