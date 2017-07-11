/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_ind_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 23:47:58 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/27 15:20:55 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		f_ind_load(t_vm *env, t_process *p)
{
	t_arg_value			args;
	int					value1;
	int					value2;

	args = check_args(env, p);
	if (args.valid)
	{
		set_value(&value1, &value2, &args, p);
		p->reg[args.arg3 - 1] = get_arg(p->pc + value1 + value2, 4);
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
