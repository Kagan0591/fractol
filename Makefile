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
	${MAKE} -f ${NAME} bonus

clean:
	${MAKE} -f ${NAME} clean

fclean:
	${MAKE} -f ${NAME} fclean

re:
	${MAKE} -f ${NAME} re

phony: all bonus clean fclean re
