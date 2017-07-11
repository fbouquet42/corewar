/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 19:46:49 by fbouquet          #+#    #+#             */
/*   Updated: 2017/05/29 21:26:24 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

static void			edit_label(t_asm *env, t_label *new)
{
	new->value = env->addr;
}

void				new_label(t_asm *env, char *line, size_t len)
{
	t_label		*new;

	if ((new = label_exist(env, line, len)) && new->value != ERROR)
		return ;
	else if (new)
		return (edit_label(env, new));
	if (!(new = (t_label*)ft_memalloc(sizeof(t_label))))
		exit_perror(env, "asm", 1);
	if (!env->label_start)
		env->label_start = new;
	if (env->label_end)
		env->label_end->next = new;
	env->label_end = new;
	if (!(new->name = ft_strndup(line, len, len + 1)))
		exit_perror(env, "asm", 1);
	new->value = env->addr;
}
