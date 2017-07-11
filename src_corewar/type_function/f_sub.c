/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sub.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 17:36:23 by jmichaud          #+#    #+#             */
/*   Updated: 2017/05/27 14:47:42 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** sub : opcode 5. OCP and take 3 T_REG.
** sub T_REG 1 - 2 and stock the result at T_REG 3
** sub can change the carry if result = 0.
*/

void		f_sub(t_vm *env, t_process *p)
{
	t_arg_value			args;

	args = check_args(env, p);
	if (args.valid)
	{
		p->reg[args.arg3 - 1] = p->reg[args.arg1 - 1] - p->reg[args.arg2 - 1];
		if (!p->reg[args.arg3 - 1])
			p->carry = 1;
		else
			p->carry = 0;
		p->pc += args.len + 2;
	}
	else
		p->pc++;
	p->cmd = 0;
}
