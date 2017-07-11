/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_live.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 23:38:11 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/31 12:34:55 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "ft_printf.h"

static t_champ	*player_valid(int player_nb, t_champ *champions)
{
	while (champions)
	{
		if (champions->player_nb == player_nb)
			return (champions);
		champions = champions->next;
	}
	return (NULL);
}

void			f_live(t_vm *env, t_process *p)
{
	int					live;
	t_champ				*champion;

	live = get_arg(p->pc + 1, 4);
	p->pc += 5;
	p->cmd = 0;
	p->nb_live++;
	env->nb_lives++;
	if ((champion = player_valid(live, env->champions)))
	{
		env->last_live = champion;
		champion->nb_lives++;
	}
}
