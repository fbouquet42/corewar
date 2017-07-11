/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_arena.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 00:24:30 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/27 17:50:01 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "corewar.h"

void		put_arena(t_vm *env, int cycles_counter)
{
	int			i;

	i = 0;
	ft_printf("The state of the memory after " \
			"\033[36m%d\033[0m cycles\n", cycles_counter);
	while (i != MEM_SIZE)
	{
		if (i && !(i % 64))
			ft_printf("\n");
		if (*(env->arena + i))
			ft_printf("\033[36m%02hhx \033[0m", *(env->arena + i));
		else
			ft_printf("%02hhx ", *(env->arena + i));
		++i;
	}
	ft_printf("\n");
}
