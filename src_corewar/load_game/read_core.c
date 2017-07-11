/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 20:25:10 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/27 14:54:11 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"
#include <unistd.h>

void		read_core(t_vm *env, int fd)
{
	int					rd;

	if (!(env->champions->program = \
				ft_memalloc(env->champions->program_len + 1)))
		ft_putperror("corewar", 1);
	if ((rd = read(fd, env->champions->program, \
					(env->champions->program_len + 1))) < 0)
		ft_putperror("corewar", 1);
	if (rd < (int)env->champions->program_len || \
			rd > (int)env->champions->program_len)
		ft_puterror("corewar: the size of the champion " \
				"is different than the size announced\n");
}
