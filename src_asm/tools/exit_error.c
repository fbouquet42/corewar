/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 21:10:03 by jmichaud          #+#    #+#             */
/*   Updated: 2017/05/29 21:47:42 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include <stdlib.h>

/*
** In case of error, free all the malloc stuff
*/

static void		free_everything(t_asm *env)
{
	t_buff		*tmp;
	t_label		*ltmp;

	free(env->dest);
	while (env->buff_start)
	{
		tmp = env->buff_start;
		env->buff_start = tmp->next;
		free(tmp->str);
		free(tmp);
	}
	while (env->label_start)
	{
		ltmp = env->label_start;
		env->label_start = ltmp->next;
		free(ltmp->name);
		free(ltmp);
	}
}

void			exit_error(t_asm *env, char *str)
{
	free_everything(env);
	ft_puterror(str);
}

void			exit_perror(t_asm *env, char *str, int i)
{
	free_everything(env);
	ft_putperror(str, i);
}
