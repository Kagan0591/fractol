###*_*_*_*_*_*_*_*_*_*_*_*_*_*_Makefile_fractol_*_*_*_*_*_*_*_*_*_*_*_*_*_*###
##	 Pour compiler les bonus, si il y a en a, décommenter les lignes## 		##
##	 B_SRCS_FILES, B_SRCS_DIR, B_SRCS et dans les instructions de la ligne 	##
##	 OBJS_FILES, décommenter $(B_SRCS_FILES:.c=.o)						 	##

###-----------------------------# VARIABLES ##-----------------------------###
### Colors code
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


NAME			= fractol
MAKEFILE_OPTION	= $(firstword $(MAKECMDGOALS))

SRCS_FILES		= main.c
#B_SRCS_FILES	=

OBJS_FILES		= $(SRCS_FILES:.c=.o)
# B_OBJS_FILES	=

### Directory setup
SRCS_DIR	= srcs/
#B_SRCS_DIR	= bonus_srcs/
OBJS_DIR	= objs/
#B_OBJS_DIR	= bonus_objs/
INC_DIR		= inc/
#B_INC_DIR	= bonus_inc/
LIBFT_DIR 	= 42Qc_libft/
MLX_DIR		= minilibx-linux/
VPATH 		= $(SRCS_DIR) $(B_SRCS_DIR)


### Assembling sources and objects
SRCS 	= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
B_SRCS	= $(addprefix $(B_SRCS_DIR), $(B_SRCS_FILES))
OBJS	= $(addprefix $(OBJS_DIR), $(OBJS_FILES))
B_OBJS	= $(addprefix $(B_OBJS_DIR), $(B_OBJS_FILES))

### Compilation var setup
CC 				= gcc
CFLAGS			= -Wall -Werror -Wextra -o ${NAME}
LIBFT			= $(MAKE) --silent -C $(LIBFT_DIR)
UNAME			= $(shell uname | cat)
ifeq (${UNAME},Linux)
	MLX_COMPIL	= (cd minilibx-linux ; ${MAKE} -f Makefile.gen all)
endif
ifeq (${UNAME},Darwin)
endif

### Test and debug var setup
ifeq (${MAKEFILE_OPTION},test)
REPONSE_USER	:= $(shell read -p "Did you want to check the norm ? : " \
				NORM_CHECK; echo $${NORM_CHECK})
endif
ifeq (${REPONSE_USER},yes)
	NORMINETTE	= norminette
else
	NORMINETTE	=
endif

### Misc var setup
RM	= rm -rf

###------------------------------## REGLES ##------------------------------###
all: obj $(NAME)

$(NAME): $(OBJS)
	@${MLX_COMPIL}
	@${LIBFT}
	@${CC} ${OBJS} -L${LIBFT_DIR} -L${MLX_DIR} -lft -o ${NAME} -lm
	@echo "\n${BLUE}${BOLD}An executable '${GREEN} fractol ${END}${BLUE}${BOLD}' have been created successfully!${END}"
	@sleep 1

$(OBJS)%.o:%.c
	@${CC} ${CFLAGS} -I ${LIBFT_DIR} -I ${MLX_DIR} -I ${INC_DIR} -I. -o $@ -c $<

#$(B_BONUS)%.o:%.c

test:
	${NORMINETTE}

norm:
	norminette

obj:
	mkdir -p ${OBJS_DIR}

# bonus_obj:
# 	mkdir -p ${OBJS_DIR}

clean:
	(cd minilibx-linux ; ${MAKE} -f Makefile.gen clean)

fclean: clean
	rm -f ${NAME} ${NAME}.dSYM

re: fclean all

phony: all test norm clean fclean re
