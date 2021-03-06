/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:40:03 by jmichaud          #+#    #+#             */
/*   Updated: 2016/11/09 11:20:33 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstadd(t_list **alst, t_list *lnew)
{
	if (lnew)
		lnew->next = *alst;
	*alst = lnew;
}
