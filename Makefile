OS	= $(shell uname | cat)

ifeq (${OS},Linux)
	NAME = Makefile_linux.mk
endif
ifeq (${OS},Darwin)
	NAME = Makefile_mac.mk
endif

all: ${NAME}
	${MAKE} -f ${NAME} all

${NAME}:

bonus:
	make -f ${NAME} bonus

clean:
	make -f ${NAME} clean

fclean:
	make -f ${NAME} fclean

re:
	make -f ${NAME} re

phony: all bonus clean fclean re
