/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:12:36 by achauvea          #+#    #+#             */
/*   Updated: 2017/05/31 12:54:41 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"
#include <stdlib.h>

void		init_ncurses(t_vm *env)
{
	t_visual	*visual;

	if (!(visual = (t_visual*)ft_memalloc(sizeof(t_visual))))
		ft_putperror("corewar", 1);
	initscr();
	curs_set(0);
	noecho();
	nodelay(stdscr, TRUE);
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(10, COLOR_RED, COLOR_BLACK);
	init_pair(11, COLOR_GREEN, COLOR_BLACK);
	init_pair(12, COLOR_YELLOW, COLOR_BLACK);
	init_pair(13, COLOR_BLUE, COLOR_BLACK);
	init_pair(14, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(15, COLOR_CYAN, COLOR_BLACK);
	visual->pause = 1;
	visual->arena = subwin(stdscr, LINES, COLS / 4 * 3, 0, 0);
	visual->info = subwin(stdscr, LINES, COLS / 4, 0, COLS / 4 * 3);
	keypad(visual->arena, TRUE);
	env->visual = visual;
}

void		keypad_visual(t_vm *env)
{
	int		key;

	key = getch();
	while (env->visual->pause)
	{
		key = getch();
		if (key == ' ')
		{
			env->visual->pause = 0;
			key = 0;
		}
		else if (key == 's' || key == 'q')
			break ;
		print_info(env, env->visual->info, "** PAUSED **");
	}
	if (key == 'q')
	{
		close_ncurses(env);
		exit(0);
	}
	else if (key == ' ' || key == 's')
		env->visual->pause = 1;
}

void		print_cycle(t_vm *env)
{
	wattron(env->visual->arena, COLOR_PAIR(1));
	wattrset(env->visual->info, A_BOLD);
	keypad_visual(env);
	print_info(env, env->visual->info, "** RUNNING **");
	print_arena(env->visual->arena);
}

void		close_ncurses(t_vm *env)
{
	print_info(env, env->visual->info, "** FINISH **");
	while (1)
	{
		if (getch() != -1)
			break ;
	}
	delwin(env->visual->arena);
	delwin(env->visual->info);
	endwin();
	free(env->visual);
}
