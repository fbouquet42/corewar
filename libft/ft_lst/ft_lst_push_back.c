/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:54:57 by jmichaud          #+#    #+#             */
/*   Updated: 2016/12/08 18:55:22 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lst_push_back(t_list **alst, t_list *lnew)
{
	t_list		*tmp;

	tmp = *alst;
	if (!tmp)
		*alst = lnew;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = lnew;
	}
}
