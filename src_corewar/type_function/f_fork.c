/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_fork.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 00:08:35 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/30 17:07:46 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void			f_fork(t_vm *env, t_process *p)
{
	int				value;
	t_process		*new;

	p->cmd = 0;
	env->nb_processes++;
	value = get_arg(p->pc + 1, 2);
	if (!(new = ft_memalloc(sizeof(t_process))))
		ft_putperror("corewar", 1);
	ft_memcpy((void*)new, (const void*)p, sizeof(t_process));
	new->next = env->list_p;
	env->list_p = new;
	value %= MEM_SIZE;
	new->pc = p->pc + value;
	p->pc += 3;
}
