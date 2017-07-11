/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_buff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 18:01:55 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/29 21:25:24 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

/*
** Create a new t_buff elem
** add it at the end of the t_buff chain list
*/

void		new_buff(t_asm *env, unsigned char *str, unsigned int len)
{
	t_buff			*new;

	if (!str)
		exit_error(env, "asm: str is null in new_buff\n");
	if (!(new = (t_buff*)ft_memalloc(sizeof(t_buff))))
		exit_perror(env, "asm", 1);
	new->str = str;
	new->len = len;
	if (env->buff_end)
		env->buff_end->next = new;
	env->buff_end = new;
	if (!env->buff_start)
		env->buff_start = new;
	env->addr += len;
}
