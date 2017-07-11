/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_champs_and_arena.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 21:33:44 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/29 21:43:06 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdlib.h>

void		free_champs_and_arena(t_vm *env)
{
	void	*buff;

	while (env->champions)
	{
		buff = (void*)env->champions;
		free(env->champions->program);
		free(env->champions->name);
		free(env->champions->comment);
		env->champions = env->champions->next;
		free(buff);
	}
	while (env->list_p)
	{
		buff = (void*)env->list_p;
		env->list_p = env->list_p->next;
		free(buff);
	}
	env->last_live = NULL;
	free(env->arena);
	env->arena = NULL;
}
