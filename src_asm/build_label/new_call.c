/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_call.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:04:42 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/29 21:27:11 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <string.h>

void			new_call(t_asm *env, t_label *called, size_t mem)
{
	t_call				*new;
	unsigned char		*str;

	if (!(new = (t_call*)ft_memalloc(sizeof(t_call))))
		exit_perror(env, "asm", 1);
	if (!(str = (unsigned char*)ft_memalloc(sizeof(mem))))
		exit_perror(env, "asm", 1);
	new->next = called->label_calls;
	called->label_calls = new;
	new_buff(env, str, mem);
	new->called = env->buff_end;
	new->value = env->addr;
	new->value -= env->arg;
}
