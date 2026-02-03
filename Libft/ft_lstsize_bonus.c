/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlytvync <dlytvync@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:33:59 by dlytvync          #+#    #+#             */
/*   Updated: 2025/04/21 11:40:25 by dlytvync         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		res;
	t_list	*list;

	if (lst == NULL)
		return (0);
	res = 0;
	list = lst;
	while (list != 0)
	{
		res++;
		list = list->next;
	}
	return (res);
}
