/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 11:49:45 by jmichaud          #+#    #+#             */
/*   Updated: 2017/05/31 12:56:14 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <string.h>
# include <ncurses.h>
# include "op.h"

# define ARENA_LENGTH 50

# define OPT_N		"-n"
# define OPT_D		"-d"
# define OPT_DUMP	"--dump"
# define OPT_V		"-v"

# define PLAYER_NB 1

/*
** structures
*/

typedef struct	s_champ
{
	unsigned char	*program;
	char			*name;
	char			*comment;
	int				program_len;
	int				player_nb;
	int				nb_lives;
	unsigned int	player_nb_defined : 1;
	struct s_champ	*next;
}				t_champ;

typedef struct	s_process
{
	int					nb_live;
	unsigned char		cmd;
	int					time;
	int					player_color;
	unsigned int		carry : 1;
	int					pc;
	int					reg[REG_NUMBER];
	struct s_process	*next;
}				t_process;

typedef struct	s_visual
{
	WINDOW			*arena;
	WINDOW			*info;
	int				pause;
	int				cycles_counter;
}				t_visual;

typedef struct	s_vm
{
	t_champ			*last_live;
	int				nb_lives;
	int				nb_processes;
	int				checks;
	unsigned char	cur_cmd;
	int				ctd;
	int				last_check;
	int				dump;
	int				visual_option;
	int				options;
	int				opt_player_nb;
	unsigned char	*arena;
	t_process		*list_p;
	t_champ			*champions;
	t_visual		*visual;
	int				nb_champions;
}				t_vm;

typedef struct	s_arg_value
{
	int				arg1;
	int				arg2;
	int				arg3;
	unsigned char	type1;
	unsigned char	type2;
	unsigned char	type3;
	unsigned char	len;
	int				pc;
	unsigned int	valid : 1;
}				t_arg_value;

typedef char	t_arg_type;
typedef void	(*t_function)(t_vm*, t_process*);

typedef struct	s_op
{
	char			*cmd;
	unsigned int	nb_args : 2;
	t_arg_type		args[3];
	unsigned char	op_code;
	int				exec_time;
	unsigned int	restriction : 1;
	unsigned int	idx_mod : 1;
	t_function		f_cmd;
}				t_op;

/*
** .
*/

void			vm_usage(void);
unsigned char	*circ_mem(unsigned char *param, int index);

/*
** load_game
*/

void			load_game(t_vm *env, int argc, char **argv);

int				load_player(t_vm *env, char *arg);
int				load_options(t_vm *env, int argc, char **argv, int *i);

void			read_header(t_vm *env, int fd);
void			read_core(t_vm *env, int fd);
void			create_champs_process(t_vm *env);
void			sort_champs(t_vm *env);
void			load_arena(t_vm *env);
void			player_nb(t_vm *env, t_champ *new);

/*
** fight
*/

void			fight(t_vm *env);
t_op			g_tab[16];

void			check_living_processes(t_vm *env);
void			exec_cycles(t_vm *env);
void			put_arena(t_vm *env, int cycles_counter);
void			free_champs_and_arena(t_vm *env);

void			do_command(t_vm *env, t_process *p);

int				get_arg(int indexi, int len);
void			put_ram(int index, int to_put);
t_arg_value		check_args(t_vm *env, t_process *p);
int				parse_args(t_vm *env, t_arg_value *ret, \
		unsigned char coding_byte, t_process *p);
void			set_value(int *value1, int *value2, t_arg_value *args, \
		t_process *p);

/*
** type_function
*/

void			f_live(t_vm *env, t_process *p);
void			f_load(t_vm *env, t_process *p);
void			f_store(t_vm *env, t_process *p);
void			f_add(t_vm *env, t_process *p);
void			f_sub(t_vm *env, t_process *p);
void			f_and(t_vm *env, t_process *p);
void			f_or(t_vm *env, t_process *p);
void			f_xor(t_vm *env, t_process *p);
void			f_zjmp(t_vm *env, t_process *p);
void			f_ind_load(t_vm *env, t_process *p);
void			f_ind_store(t_vm *env, t_process *p);
void			f_fork(t_vm *env, t_process *p);
void			f_aff(t_vm *env, t_process *p);

/*
** visual
*/

void			init_ncurses(t_vm *env);
void			print_cycle(t_vm *env);
void			close_ncurses(t_vm *env);
void			init_arena(WINDOW *arena);
void			modif_arena(WINDOW *arena, int octet,
		unsigned char *new, int new_len);
void			pre_modif_arena(t_vm *env, int octet, int color);
void			process_arena(WINDOW *arena, int octet, int color, int reverse);
void			print_arena(WINDOW *arena);
void			print_info(t_vm *env, WINDOW *info, char *statut);

#endif
