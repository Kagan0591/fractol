###*_*_*_*_*_*_*_*_*_*_*_*_*_*_Makefile_fractol_*_*_*_*_*_*_*_*_*_*_*_*_*_*###
##	 Pour compiler les bonus, si il y a en a, décommenter les lignes## 		##
##	 B_SRCS_FILES, B_SRCS_DIR, B_SRCS et dans les instructions de la ligne 	##
##	 OBJS_FILES, décommenter $(B_SRCS_FILES:.c=.o)						 	##

###-----------------------------# VARIABLES ##-----------------------------###
## Colors code
END			= \033[0m
BOLD		= \033[1m
ITALIC		= \033[3m
URL			= \033[4m
SELECTED	= \033[7m

BLACK		= \033[30m
RED			= \033[31m
GREEN		= \033[32m
YELLOW		= \033[33m
BLUE		= \033[34m
VIOLET		= \033[35m
BEIGE		= \033[36m
WHITE		= \033[37m

NAME			= pipex

SRCS_FILES		= main.c \

# B_SRCS_FILES	=

## Name the objects files
OBJS_FILES		= $(SRCS_FILES:.c=.o)
# B_OBJS_FILES	= $(B_SRCS_FILES:.c=.o)

## Directory setup
SRCS_DIR		= srcs/
B_SRCS_DIR		= bonus_srcs/
OBJS_DIR		= objs/
B_OBJS_DIR		= bonus_objs/
INC_DIR			= inc/
B_INC_DIR		= bonus_inc/
LIBFT_DIR		= 42Qc_libft/
MLX_LINUX_DIR	= mlx_linux/
# MLX_MAC_DIR		= mlx_mac/
VPATH			= $(SRCS_DIR) $(B_SRCS_DIR)

## Assembling sources and objects
SRCS	= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
B_SRCS	= $(addprefix $(B_SRCS_DIR), $(B_SRCS_FILES))
OBJS	= $(addprefix $(OBJS_DIR), $(OBJS_FILES))
B_OBJS	= $(addprefix $(B_OBJS_DIR), $(B_OBJS_FILES))

## Test and debug var setup

## Compilation var setup
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g
LIBFT		= $(MAKE) --silent -C $(LIBFT_DIR)
MLX_CONFIG	= $(MAKE) --silent -C ${MLX_LINUX_DIR}

## Misc var setup
RM	= rm -rf

###------------------------------## REGLES ##------------------------------###
all: obj $(NAME)
	${LIBFT}
	${MLX_CONFIG}

${NAME}: $(OBJS)
	@${CC} ${OBJS} -L${LIBFT_DIR} -l${LIBFT_DIR} -L${MLX_LINUX_DIR} -l${MLX_LINUX_DIR} -I${MLX_LINUX_DIR} -L/usr/lib -lXext -lX11 -lft -lm -lz -o ${NAME}
	@echo "\n${BLUE}${BOLD}An executable '${GREEN} fractol ${END}${BLUE}${BOLD}' have been created successfully!${END}"
	@sleep 1

$(OBJS_DIR)%.o:%.c
	@${CC} ${CFLAGS} -I${LIBFT_DIR} -I${MLX_LINUX_DIR} -I/usr/include -I${INC_DIR} -I. -O3 -o $@ -c $<

# $(B_OBJS_DIR)%.o:%.c
# 	@${CC} ${CFLAGS} -I${LIBFT_DIR} -I${MLX_DIR} -I${B_INC_DIR} -I. -o $@ -c $<

bonus:
	echo "Bonus"

obj:
	mkdir -p ${OBJS_DIR}

# bonus_obj:
# 	mkdir -p ${OBJS_DIR}

clean:
	${LIBFT} clean
	${MLX_CONFIG} clean
	echo "clean"

fclean:
	echo "fclean"

re: clean all
	echo "re"

phony: all bonus clean fclean re
