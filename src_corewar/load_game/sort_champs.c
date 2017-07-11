/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:36:10 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/27 14:55:20 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		move_champ_before(t_vm *env, t_champ *champion)
{
	t_champ		*bigger;
	t_champ		*previous_bigger;
	t_champ		*smaller;

	previous_bigger = NULL;
	bigger = env->champions;
	smaller = champion->next;
	champion->next = smaller->next;
	while (bigger->player_nb < smaller->player_nb && (previous_bigger = bigger))
		bigger = bigger->next;
	if (!previous_bigger)
		env->champions = smaller;
	else
		previous_bigger->next = smaller;
	smaller->next = bigger;
}

void			sort_champs(t_vm *env)
{
	t_champ		*champions;

	champions = env->champions;
	while (champions)
	{
		while (champions->next && \
				champions->next->player_nb < champions->player_nb)
			move_champ_before(env, champions);
		champions = champions->next;
	}
}
