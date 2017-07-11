/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_exist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 21:53:57 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/22 00:16:24 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

t_label			*label_exist(t_asm *env, char *label_name, size_t len)
{
	t_label		*labels;

	labels = env->label_start;
	while (labels)
	{
		if (ft_strnequ(labels->name, label_name, len))
			return (labels);
		labels = labels->next;
	}
	return (NULL);
}
