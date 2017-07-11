/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 21:50:23 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/27 14:41:01 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "ft_printf.h"

void		do_command(t_vm *env, t_process *process)
{
	--env->cur_cmd;
	if (!process->cmd)
	{
		process->time = g_tab[env->cur_cmd].exec_time - 1;
		process->cmd = g_tab[env->cur_cmd].op_code;
	}
	else if (process->cmd != g_tab[env->cur_cmd].op_code)
	{
		process->pc++;
		process->cmd = 0;
	}
	else
		g_tab[env->cur_cmd].f_cmd(env, process);
}
