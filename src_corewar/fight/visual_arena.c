/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_arena.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 15:56:38 by achauvea          #+#    #+#             */
/*   Updated: 2017/05/30 18:09:14 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <unistd.h>

void	init_arena(WINDOW *arena)
{
	int		i;
	int		lines;
	int		cols;

	i = 0;
	lines = 3;
	cols = ((COLS / 4 * 3) - 3 * ARENA_LENGTH) / 2;
	while (i != MEM_SIZE)
	{
		if (i && !(i % ARENA_LENGTH))
		{
			lines++;
			cols = ((COLS / 4 * 3) - 3 * ARENA_LENGTH) / 2;
		}
		mvwprintw(arena, lines, cols, "%02hhx ", 0);
		cols += 3;
		++i;
	}
	wattrset(arena, A_BOLD);
	box(arena, ACS_VLINE, ACS_HLINE);
	mvwprintw(arena, 1, (COLS / 4 * 3 - 6) / 2, "Corewar arena");
	wattrset(arena, A_BLINK);
}

void	modif_arena(WINDOW *arena, int octet, unsigned char *new, int new_len)
{
	int		i;
	int		y;
	int		lines;
	int		cols;

	i = 0;
	y = octet % ARENA_LENGTH;
	lines = octet / ARENA_LENGTH + 3;
	cols = ((COLS / 4 * 3) - 3 * ARENA_LENGTH) / 2 + (y * 3);
	while (i < new_len)
	{
		if (y && !(y % ARENA_LENGTH))
		{
			lines++;
			cols = ((COLS / 4 * 3) - 3 * ARENA_LENGTH) / 2;
		}
		mvwprintw(arena, lines, cols, "%02hhx ", *(new + i));
		cols += 3;
		++i;
		++y;
	}
	wattron(arena, COLOR_PAIR(1));
}

void	pre_modif_arena(t_vm *env, int octet, int color)
{
	while (octet < 0)
		octet += MEM_SIZE;
	if (octet >= MEM_SIZE)
		octet %= MEM_SIZE;
	wattron(env->visual->arena, COLOR_PAIR(color));
	modif_arena(env->visual->arena, octet, &env->arena[octet], 4);
}

void	process_arena(WINDOW *arena, int octet, int color, int reverse)
{
	int		y;
	int		lines;
	int		cols;

	while (octet < 0)
		octet += MEM_SIZE;
	if (octet >= MEM_SIZE)
		octet %= MEM_SIZE;
	y = octet % ARENA_LENGTH;
	lines = octet / ARENA_LENGTH + 3;
	cols = ((COLS / 4 * 3) - 3 * ARENA_LENGTH) / 2 + (y * 3);
	if (reverse)
		mvwchgat(arena, lines, cols, 2, A_REVERSE, color, NULL);
	else
		mvwchgat(arena, lines, cols, 2, A_BLINK, color, NULL);
}

void	print_arena(WINDOW *arena)
{
	wrefresh(arena);
	usleep(5000);
}
