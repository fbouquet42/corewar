/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:48:43 by jtoty             #+#    #+#             */
/*   Updated: 2017/05/30 18:29:46 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				remove_elem(t_list_fd **begin, t_list_fd *elem)
{
	t_list_fd *current;

	free(elem->s);
	current = *begin;
	if (current == elem)
	{
		*begin = current->next;
		free(current);
		current = NULL;
	}
	else
	{
		while (current->next != elem)
			current = current->next;
		current->next = elem->next;
		current = elem;
		free(current);
		current = NULL;
	}
	return (0);
}

t_list_fd		*search_fd(const int fd, t_list_fd **begin)
{
	t_list_fd		*elem;

	elem = *begin;
	while (elem && elem->fd != fd)
		elem = elem->next;
	if (!elem)
	{
		if ((elem = (t_list_fd *)malloc(sizeof(t_list_fd))))
		{
			if (!(elem->s = ft_strnew(0)))
				return (NULL);
			elem->fd = fd;
			elem->next = *begin;
			*begin = elem;
		}
	}
	return (elem);
}

int				read_in_buff(const int fd, t_list_fd *elem)
{
	int			len_r;
	char		*tmp;
	char		buffer[BUFF_GNL + 1];

	while (ft_strchr(elem->s, CHAR) == NULL)
	{
		if ((len_r = read(fd, buffer, BUFF_GNL)) == -1)
			return (-1);
		if (len_r == 0)
			return (0);
		buffer[len_r] = '\0';
		tmp = elem->s;
		if (!(elem->s = ft_strjoin(tmp, buffer)))
			return (-1);
		free(tmp);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list_fd	*begin = NULL;
	t_list_fd			*el;

	if (!(el = search_fd(fd, &begin)))
		return (-1);
	if ((el->ret = read_in_buff(fd, el)) == -1)
		return (-1);
	else if (el->ret == 1)
	{
		if (!(*line = ft_strsub(el->s, 0, ft_strchr(el->s, CHAR) - el->s)))
			return (-1);
		if (!(el->tmp = ft_strdup(ft_strchr(el->s, CHAR) + 1)))
			return (-1);
		free(el->s);
		el->s = el->tmp;
		return (1);
	}
	if (el->s[0] == '\0')
		return (remove_elem(&begin, el));
	if (!(*line = ft_strdup(el->s)))
		return (-1);
	el->s[0] = '\0';
	return (1);
}
