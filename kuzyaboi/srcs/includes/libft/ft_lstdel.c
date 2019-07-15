/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:01:41 by tstripeb          #+#    #+#             */
/*   Updated: 2019/04/18 15:02:26 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *tmp;

	if (*alst && del)
	{
		list = *alst;
		while (list)
		{
			tmp = list;
			del(list->content, list->content_size);
			free(list);
			list = tmp->next;
		}
		*alst = NULL;
	}
}
