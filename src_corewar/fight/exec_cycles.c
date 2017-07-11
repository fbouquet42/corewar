/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cycles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 16:12:27 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/31 12:47:31 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		mem_modulo(t_process *p)
{
	while (p->pc < 0)
		p->pc += MEM_SIZE;
	if (p->pc >= MEM_SIZE)
		p->pc %= MEM_SIZE;
}

void			exec_cycles(t_vm *env)
{
	t_process			*list_p;

	list_p = env->list_p;
	while (list_p)
	{
		if (env->visual_option && *circ_mem(NULL, list_p->pc))
			process_arena(env->visual->arena, list_p->pc,
					list_p->player_color, 0);
		else if (env->visual_option)
			process_arena(env->visual->arena, list_p->pc, 1, 0);
		if (list_p->time)
			list_p->time--;
		else if ((env->cur_cmd = *circ_mem(NULL, list_p->pc)) > 0 \
				&& env->cur_cmd < 17)
			do_command(env, list_p);
		else
			list_p->pc++;
		mem_modulo(list_p);
		if (env->visual_option)
			process_arena(env->visual->arena, list_p->pc, \
					list_p->player_color, 1);
		list_p = list_p->next;
	}
}
