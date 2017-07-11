/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 20:27:18 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/30 16:42:08 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void		load_arena(t_vm *env)
{
	t_champ		*champions;
	int			i;

	if (!(env->arena = (unsigned char*)ft_memalloc(MEM_SIZE)))
		ft_putperror("corewar", 1);
	circ_mem(env->arena, 0);
	i = 0;
	if (env->visual_option)
		init_arena(env->visual->arena);
	champions = env->champions;
	while (champions)
	{
		ft_memcpy((void*)&env->arena[(MEM_SIZE / env->nb_champions) * i], \
				(const void*)champions->program, champions->program_len);
		if (env->visual_option)
		{
			wattron(env->visual->arena, COLOR_PAIR(10 + i));
			modif_arena(env->visual->arena, (MEM_SIZE / env->nb_champions) * i,
				champions->program, champions->program_len);
		}
		++i;
		champions = champions->next;
	}
}
