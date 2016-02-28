/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 19:01:14 by rbodnare          #+#    #+#             */
/*   Updated: 2015/10/31 19:01:16 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*last;

	last = f(lst);
	new = last;
	if (new == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		last->next = f(lst);
		if (last->next == NULL)
			return (NULL);
		last = last->next;
	}
	return (new);
}
