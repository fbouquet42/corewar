/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 12:54:19 by achauvea          #+#    #+#             */
/*   Updated: 2017/05/31 13:12:25 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	print_other_info(t_vm *env, WINDOW *info, int i)
{
	mvwprintw(info, 10 + i * 4, 5, "CYCLE_TO_DIE: %i/%i",
				env->last_check, env->ctd);
	mvwprintw(info, 12 + i * 4, 5, "CYCLE_DELTA: %i", CYCLE_DELTA);
	mvwprintw(info, 14 + i * 4, 5, "NBR_LIVE: %i/%i",
				env->nb_lives, NBR_LIVE);
	mvwprintw(info, 16 + i * 4, 5, "MAX_CHECKS: %i/%i",
				env->checks, MAX_CHECKS);
	if (!env->list_p)
		mvwprintw(env->visual->info, 18 + i * 4, 5, "Player %d(%s) has, won !",
			env->last_live->player_nb, env->last_live->name);
	wrefresh(info);
}

void	print_info(t_vm *env, WINDOW *info, char *statut)
{
	int		i;
	t_champ	*champions;

	werase(info);
	box(info, ACS_VLINE, ACS_HLINE);
	mvwprintw(info, 1, (COLS / 4 - 4) / 2, "Game info");
	mvwprintw(info, 3, 5, statut);
	mvwprintw(info, 5, 5, "Cycles: %i", env->visual->cycles_counter);
	mvwprintw(info, 7, 5, "Processes: %i", env->nb_processes);
	i = 0;
	champions = env->champions;
	while (champions)
	{
		wattron(info, COLOR_PAIR(10 + i));
		mvwprintw(info, 9 + i * 4, 5, "Player %i: %s",
			champions->player_nb, champions->name);
		wattron(info, COLOR_PAIR(1));
		mvwprintw(info, 11 + i++ * 4, 5, "\tNumber of lives: %i",
			champions->nb_lives);
		champions = champions->next;
	}
	print_other_info(env, info, i);
}
