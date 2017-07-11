/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_champs_process.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:58:05 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/30 17:07:26 by fbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

static t_process	*ascending_creation_of_process(t_champ *champion)
{
	t_process	*new;

	if (!champion)
		return (NULL);
	if (!(new = (t_process*)ft_memalloc(sizeof(t_process))))
		ft_putperror("corewar", 1);
	new->reg[0] = champion->player_nb;
	new->next = ascending_creation_of_process(champion->next);
	return (new);
}

static void			parse_process(t_vm *env, t_process *list_of_p)
{
	int		i;

	i = 0;
	env->nb_processes = env->nb_champions;
	while (list_of_p)
	{
		list_of_p->pc = (MEM_SIZE / env->nb_champions) * i;
		list_of_p->player_color = 10 + i;
		list_of_p = list_of_p->next;
		++i;
	}
}

void				create_champs_process(t_vm *env)
{
	env->list_p = ascending_creation_of_process(env->champions);
	parse_process(env, env->list_p);
}
