/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   potential_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:16:27 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/29 21:25:59 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

void			potential_label(t_asm *env, char *line, size_t len, size_t mem)
{
	t_label		*new;

	if (!(new = (t_label*)ft_memalloc(sizeof(t_label))))
		exit_perror(env, "asm", 1);
	if (!env->label_start)
		env->label_start = new;
	if (env->label_end)
		env->label_end->next = new;
	env->label_end = new;
	if (!(new->name = ft_strndup(line, len, len + 1)))
		exit_perror(env, "asm", 1);
	new->value = ERROR;
	new_call(env, new, mem);
}
