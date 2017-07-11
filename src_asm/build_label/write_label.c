/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 19:16:48 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/29 15:40:37 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdlib.h>
#include "ft_printf.h"

static void		write_called(t_label *lab)
{
	t_call		*buff;

	while (lab->label_calls)
	{
		buff = lab->label_calls;
		nb_in_mem(buff->called->str, \
				(int)(lab->value - buff->value), buff->called->len);
		lab->label_calls = lab->label_calls->next;
		free(buff);
	}
}

void			write_label(t_asm *env)
{
	t_label		*buff;

	while (env->label_start)
	{
		buff = env->label_start;
		if (buff->value == ERROR)
		{
			ft_printf("asm: %{FD}label %s doesn't exist\n", 2, buff->name);
			exit(0);
		}
		write_called(buff);
		env->label_start = env->label_start->next;
		free(buff->name);
		free(buff);
	}
	env->label_end = NULL;
}
