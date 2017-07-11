/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_zjmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 00:02:39 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/29 15:57:46 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		f_zjmp(t_vm *env, t_process *p)
{
	int				value;

	(void)env;
	if (p->carry)
	{
		value = get_arg(p->pc + 1, 2);
		value %= MEM_SIZE;
		p->pc += value;
	}
	else
		p->pc += 3;
	p->cmd = 0;
}
