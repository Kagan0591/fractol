###_*_*_*_*_*_*_*_*_*_*_*_*_*_*_Makefile_fractol_*_*_*_*_*_*_*_*_*_*_*_*_*_*_###
##	 Pour compiler les bonus, si il y a en a, décommenter les lignes## 		##
##	 B_SRCS_FILES, B_SRCS_DIR, B_SRCS et dans les instructions de la ligne 	##
##	 OBJS_FILES, décommenter $(B_SRCS_FILES:.c=.o)						 	##

###-----------------------------# VARIABLES ##-----------------------------###

NAME				= fractol

SRCS				= main.c
#B_SRCS				=

# OBJS				=
# B_OBJS				=

# Directory settings
SRCS_DIR			= srcs/
OBJS_DIR			= objs/
INC_DIR				= inc/


UNAME	= $(shell uname)
ifeq ($(uname),Linux)
	CC = gcc
	MINILIBX_LINUX_DIR 	= minilibx-linux/
	MINILIBX			= $(MAKE) -C $(MINILIBX_LINUX_DIR)
endif
ifeq ($(uname),Darwin)
	CC = gcc
endif

# MLX settings
CLEAN_MLX =


all: obj ${NAME}

${NAME}:
	${MINILIBX}

${OBJS}: %.o:%.c

${B_BONUS}


norm: re
	norminette

obj:
	mkdir -p ${OBJS_DIR}

clean:
	ifeq (${UNAME},Linux)

		echo "Linux"
		${MAKE} -C ${MINILIBX_LINUX_DIR} -f Makefile.gen clean
		${MAKE} -C ${MINILIBX_LINUX_DIR}test/ -f Makefile.gen --no-print-directory clean
	endif
	# ifneq ($(uname),Darwin)
	# 	echo "Darwin"
	# endif

fclean: clean
	rm -f ${NAME} ${NAME}.dSYM

re: fclean all

phony: all clean fclean re
