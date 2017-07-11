/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:39:07 by jmichaud          #+#    #+#             */
/*   Updated: 2017/05/30 18:03:01 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

t_op	g_tab[16] =
{
	{"live", 1, {T_DIR, 0, 0}, 1, 10, 0, 0, &f_live},
	{"ld", 2, {T_DIR | T_IND, T_REG, 0}, 2, 5, 0, 1, &f_load},
	{"st", 2, {T_REG, T_IND | T_REG, 0}, 3, 5, 0, 1, &f_store},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, 0, 0, &f_add},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, 0, 0, &f_sub},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, \
		6, 6, 0, 1, &f_and},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, \
		7, 6, 0, 1, &f_or},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, \
		8, 6, 0, 1, &f_xor},
	{"zjmp", 1, {T_DIR, 0, 0}, 9, 20, 1, 0, &f_zjmp},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, \
		10, 25, 1, 1, &f_ind_load},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, \
		11, 25, 1, 1, &f_ind_store},
	{"fork", 1, {T_DIR, 0, 0}, 12, 800, 1, 1, &f_fork},
	{"lld", 2, {T_DIR | T_IND, T_REG, 0}, 13, 10, 0, 0, &f_load},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, \
		14, 50, 1, 0, &f_ind_load},
	{"lfork", 1, {T_DIR, 0, 0}, 15, 1000, 1, 0, &f_fork},
	{"aff", 1, {T_REG, 0, 0}, 16, 2, 0, 0, &f_aff},
};

void			fight(t_vm *env)
{
	int		cycles_counter;

	env->last_live = env->champions;
	env->ctd = CYCLE_TO_DIE;
	cycles_counter = 0;
	while (env->list_p && cycles_counter != env->dump)
	{
		if (env->last_check == env->ctd)
			check_living_processes(env);
		exec_cycles(env);
		++cycles_counter;
		if (env->visual_option)
		{
			print_cycle(env);
			env->visual->cycles_counter = cycles_counter;
		}
		env->last_check++;
	}
	if (env->visual_option)
		close_ncurses(env);
	(env->dump != -1) ? put_arena(env, cycles_counter) : 0;
	if (!env->list_p)
		ft_printf("Player %d(%s) has, won !\n",
			env->last_live->player_nb, env->last_live->name);
	free_champs_and_arena(env);
}
