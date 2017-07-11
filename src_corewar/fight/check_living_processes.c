/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_living_processes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 16:46:24 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/31 12:42:02 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdlib.h>

static void		kill_process(t_vm *env, t_process **head, t_process *previous)
{
	t_process		*at_kill;

	if (env->visual_option)
		process_arena(env->visual->arena, (*head)->pc, 1, 0);
	env->nb_processes--;
	at_kill = *head;
	(*head) = (*head)->next;
	if (!previous)
		env->list_p = (*head);
	else
		previous->next = (*head);
	free(at_kill);
}

static void		re_init(t_vm *env)
{
	t_champ		*champions;

	env->nb_lives = 0;
	env->last_check = 0;
	champions = env->champions;
	while (champions)
	{
		champions->nb_lives = 0;
		champions = champions->next;
	}
}

void			check_living_processes(t_vm *env)
{
	t_process	*list_p;
	t_process	*previous;

	list_p = env->list_p;
	previous = NULL;
	while (list_p)
	{
		if (!list_p->nb_live)
			kill_process(env, &list_p, previous);
		else
		{
			list_p->nb_live = 0;
			previous = list_p;
			list_p = list_p->next;
		}
	}
	if (env->nb_lives >= NBR_LIVE || env->checks == MAX_CHECKS)
	{
		env->ctd = CYCLE_DELTA >= env->ctd ? 1 : env->ctd - CYCLE_DELTA;
		env->checks = 0;
	}
	else
		env->checks++;
	re_init(env);
}
