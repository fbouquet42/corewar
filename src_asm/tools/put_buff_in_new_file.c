/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_buff_in_new_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:22:56 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/29 20:16:01 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <stdlib.h>

void		put_buff_in_new_file(t_asm *env)
{
	t_buff		*at_free;

	while (env->buff_start)
	{
		at_free = env->buff_start;
		ft_putnstr_fd(env->buff_start->str, env->buff_start->len, env->dot_cor);
		env->buff_start = env->buff_start->next;
		free(at_free->str);
		free(at_free);
	}
	env->buff_end = NULL;
}
