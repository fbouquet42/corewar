# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 12:34:56 by jmichaud          #+#    #+#              #
#    Updated: 2017/05/31 12:59:57 by achauvea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##  I_ include | L_ lib | O_ object | R_ repository | S_ source

## V A R I A B L E S
#####################
ASM_EXE			=	asm
VM_EXE			=	corewar

I_PATH			=	./inc/
O_PATH			=	./obj/

S_PATH_ASM		=	./src_asm/
S_PATH_HEADER	=	./src_asm/build_header/
S_PATH_CMD		=	./src_asm/build_cmd/
S_PATH_LABEL	=	./src_asm/build_label/
S_PATH_TOOLS	=	./src_asm/tools/

S_PATH_VM		=	./src_corewar/
S_PATH_LOAD		=	./src_corewar/load_game/
S_PATH_FIGHT	=	./src_corewar/fight/
S_PATH_T_F		=	./src_corewar/type_function/

S_ASM			=	asm.c \
					build_dot_cor.c

S_HEADER		=	build_header.c \
					grep_comment.c grep_name.c write_exec_magic.c

S_CMD			=	build_core.c \
					handle_direct.c handle_register.c register_cmd.c \
					handle_cmd.c handle_index.c nb_in_mem.c

S_LABEL			=	grep_label.c \
					find_label.c label_exist.c new_label.c write_label.c \
					new_call.c potential_label.c

S_TOOLS			=	ft_token.c new_buff.c put_buff_in_new_file.c skip_spaces.c \
					exit_error.c

S_VM			=	corewar.c \
					circ_mem.c vm_usage.c

S_LOAD			=	load_game.c \
					load_player.c load_options.c read_header.c \
					read_core.c player_nb.c sort_champs.c create_champs_process.c \
					load_arena.c

S_FIGHT			=	fight.c \
					put_arena.c check_living_processes.c exec_cycles.c \
					do_command.c get_arg.c set_value.c parse_args.c \
					check_args.c put_ram.c free_champs_and_arena.c \
					visual_core.c  visual_arena.c visual_info.c 

S_T_F			=	f_aff.c f_and.c f_fork.c f_ind_store.c f_ind_load.c \
					f_live.c f_load.c f_or.c f_store.c f_sub.c f_xor.c \
					f_zjmp.c f_add.c

## L I B _ V A R I A B L E S
#############################
L_PATH			=	./libft/
L_I_PATH		=	$(L_PATH)/inc/

L_R_NAME		=	\
					ft_count/		\
					ft_is/			\
					ft_lst/			\
					ft_maths		\
					ft_mem/			\
					ft_ntos/		\
					ft_printf/		\
					ft_put/			\
					ft_ston/		\
					ft_str/			\
					get_next_line/	\
					inc/

## C O M P I L E R
###################
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
CPPFLAGS		=	-I$(I_PATH) -I$(L_I_PATH)

LDFLAGS			=	-L$(L_PATH)
LDLIBS			=	-lft

LNCURSE			=	-lncurses

## A U T O M A T I C
#####################

ASM_OBJ			=	$(addprefix $(O_PATH), $(S_ASM:.c=.o)) \
	$(addprefix $(O_PATH), $(S_HEADER:.c=.o)) \
	$(addprefix $(O_PATH), $(S_CMD:.c=.o)) \
	$(addprefix $(O_PATH), $(S_LABEL:.c=.o)) \
	$(addprefix $(O_PATH), $(S_TOOLS:.c=.o))

VM_OBJ			=	$(addprefix $(O_PATH), $(S_VM:.c=.o)) \
	$(addprefix $(O_PATH), $(S_T_F:.c=.o)) \
	$(addprefix $(O_PATH), $(S_LOAD:.c=.o)) \
	$(addprefix $(O_PATH), $(S_FIGHT:.c=.o))

L_R_PATH		=	$(addprefix $(L_PATH), $(L_R_NAME))

## R U L E S
#############
.PHONY			:	all clean fclean re				\
	lib cleanlib fcleanlib relib

all				:	$(ASM_EXE) $(VM_EXE)

$(ASM_EXE)		:	libft/libft.a $(ASM_OBJ)
	@echo "$(GREEN)# COMPILE $(call up_name, $@)$(NC)"
	@$(CC) $(ASM_OBJ) -o $@ $(LDFLAGS) $(LDLIBS)

$(VM_EXE)		:	libft/libft.a $(VM_OBJ)
	@echo "$(GREEN)# COMPILE $(call up_name, $@)$(NC)"
	@$(CC) $(VM_OBJ) -o $@ $(LDFLAGS) $(LDLIBS) $(LNCURSE)

$(O_PATH)%.o	:	$(S_PATH_ASM)%.c $(I_PATH) $(L_I_PATH) Makefile
	@echo "$(BLUE)# make object\t$<$(NC)"
	@mkdir $(O_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(O_PATH)%.o	:	$(S_PATH_HEADER)%.c $(I_PATH) $(L_I_PATH) Makefile
	@echo "$(BLUE)# make object\t$<$(NC)"
	@mkdir $(O_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(O_PATH)%.o	:	$(S_PATH_CMD)%.c $(I_PATH) $(L_I_PATH) Makefile
	@echo "$(BLUE)# make object\t$<$(NC)"
	@mkdir $(O_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(O_PATH)%.o	:	$(S_PATH_LABEL)%.c $(I_PATH) $(L_I_PATH) Makefile
	@echo "$(BLUE)# make object\t$<$(NC)"
	@mkdir $(O_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(O_PATH)%.o	:	$(S_PATH_TOOLS)%.c $(I_PATH) $(L_I_PATH) Makefile
	@echo "$(BLUE)# make object\t$<$(NC)"
	@mkdir $(O_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(O_PATH)%.o	:	$(S_PATH_VM)%.c $(I_PATH) $(L_I_PATH) Makefile
	@echo "$(BLUE)# make object\t$<$(NC)"
	@mkdir $(O_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(O_PATH)%.o	:	$(S_PATH_LOAD)%.c $(I_PATH) $(L_I_PATH) Makefile
	@echo "$(BLUE)# make object\t$<$(NC)"
	@mkdir $(O_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(O_PATH)%.o	:	$(S_PATH_FIGHT)%.c $(I_PATH) $(L_I_PATH) Makefile
	@echo "$(BLUE)# make object\t$<$(NC)"
	@mkdir $(O_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(O_PATH)%.o	:	$(S_PATH_T_F)%.c $(I_PATH) $(L_I_PATH) Makefile
	@echo "$(BLUE)# make object\t$<$(NC)"
	@mkdir $(O_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@


clean			:	cleanlib
	@echo -n clean project
	@rm -f $(ASM_OBJ)
	@rm -f $(VM_OBJ)
	@echo "\t...$(YELLOW)done$(NC)"
	@rmdir $(O_PATH) 2> /dev/null || true
	@echo "----- clean done ------"

fclean			:	clean fcleanlib
	@echo -n fclean project
	@rm -f $(ASM_EXE)
	@rm -f $(VM_EXE)
	@echo "\t...$(RED)done$(NC)"
	@echo "----- fclean done -----"

re				:	fclean
	@make

## L I B R U L E S
###################
define make_lib
@echo "----- make libft ------"
@make -C $(L_PATH)
@echo "-------- done ---------"
endef

libft/libft.a	:	$(L_R_PATH) $(L_PATH)/Makefile
	$(call make_lib)

lib				:	$(L_R_PATH)
	$(call make_lib)

cleanlib		:
	@make -C $(L_PATH) clean

fcleanlib		:
	@make -C $(L_PATH) fclean

relib			:	fcleanlib
	@make lib

## E D I T I O N
#################
define up_name
$(shell echo $(1) | tr '[:lower:]' '[:upper:]')
endef

## C O L O R S
###############
NC				=	\033[0m
BOLD			=	\033[1m
UNDERLINE		=	\033[4m
BLINK			=	\033[5m
REVERSE			=	\033[7m

BLACK			=	\033[30m
RED				=	\033[31m
GREEN			=	\033[32m
YELLOW			=	\033[33m
BLUE			=	\033[34m
PURPLE			=	\033[35m
CYAN			=	\033[36m
WHITE			=	\033[37m

## B A C K G R O U N D
#######################
ON_BLACK		=	\033[40m
ON_RED			=	\033[41m
ON_GREEN		=	\033[42m
ON_YELLOW		=	\033[43m
ON_BLUE			=	\033[44m
ON_PURPLE		=	\033[45m
ON_CYAN			=	\033[46m
ON_WHITE		=	\033[47m

## L I N K S
#############
# http://gl.developpez.com/tutoriel/outil/makefile/
# https://forum.intra.42.fr/topics/85/messages

## T I P S
###########
# $@ : name of the target
# $< : name of the first dependencie
# $^ : list of the dependencies
# $? : list of the dependencies newest than the target
# $* : name of the file whitout suffix
