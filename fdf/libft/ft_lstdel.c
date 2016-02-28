/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 19:00:26 by rbodnare          #+#    #+#             */
/*   Updated: 2015/10/31 19:00:28 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lstnext;
	t_list	*lst;

	lst = *alst;
	while (lst)
	{
		lstnext = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = lstnext;
	}
	*alst = NULL;
}
