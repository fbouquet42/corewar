/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 11:01:18 by jmichaud          #+#    #+#             */
/*   Updated: 2017/05/29 13:55:57 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

/*
** First load all the parameters into memory:
** - champs (header and core)
** - options (-d, -n)
**
** Then create list process and fill the arena
**
** Finaly run the process until death !
*/

int				main(int argc, char **argv)
{
	t_vm		env;

	if (argc < 2)
		vm_usage();
	ft_bzero((void*)&env, sizeof(t_vm));
	load_game(&env, argc, argv);
	fight(&env);
	return (0);
}
