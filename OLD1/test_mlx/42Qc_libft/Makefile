# ->-Variables-->
LIB_NAME		= libft.a

SRCS_FILES		= ft_gnl.c \
			ft_atoi.c\
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_numlen.c \
			ft_hexa_numlen.c \
			ft_unsigned_numlen.c \
			ft_hexa_long_numlen.c \
			ft_printf.c \
			ft_putmem.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putnbr_hexa.c \
			ft_putnbr_hexa_up.c \
			ft_putnbr_long_hexa.c \
			ft_putnbr_unsigned.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_putstr_nl.c \
			ft_split.c \
			ft_strchr_gnlvers.c \
			ft_strchr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strjoin_free_s1.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strofstrlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \

B_SRCS_FILES	=	ft_lstnew.c \
			ft_lstsize.c \
			ft_lstadd_front.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \

### Name the objects files ###
OBJS 			= $(SRCS_FILES:.c=.o)
BONUS_OBJS 		= $(B_SRCS_FILES:.c=.o)

### Compile and archive ###
CC 				= gcc
FLAGS 			= -Wall -Werror -Wextra
ARCHIVE 		= ar -crs

### Others functions ###
RM 			= rm -rf

### Colour variables ###
END				= \033[0m
BOLD			= \033[1m
ITALIC			= \033[3m
URL				= \033[4m
BLINK			= \033[5m
BLINK2			= \033[6m
SELECTED		= \033[7m

BLACK			= \033[30m
RED				= \033[31m
GREEN			= \033[32m
YELLOW			= \033[33m
BLUE			= \033[34m
VIOLET			= \033[35m
BEIGE			= \033[36m
WHITE			= \033[37m
BUFFER_SIZE		=
# ->-Rules-->
all: ${LIB_NAME}

${LIB_NAME}: ${GNL_OBJS} ${OBJS}
	@echo "\n${GREEN}${BOLD}Compiling and adding objects files to the libft.a archive.${END}"
	@${ARCHIVE} ${LIB_NAME} ${OBJS} ${GNL_OBJS}
	@sleep 0.5

bonus: ${LIB_NAME} ${BONUS_OBJS}
	@echo "\n${GREEN}${BOLD}Compiling and adding objects files and bonus objects files to the libft.a archive.${END}"
	@${ARCHIVE} ${LIB_NAME} ${BONUS_OBJS}
	@sleep 0.5

.c.o:
	$(CC) ${FLAGS} -o $@ -c $<

clean:
	@$(RM) ${OBJS} ${BONUS_OBJS}
	@echo "\n${GREEN}${BOLD}The libft Objects files have been ${RED}deleted ${GREEN}correcly.${END}"
	@sleep 0.5

fclean: clean
	@${RM} ${LIB_NAME}
	@echo "\n${GREEN}${BOLD}The libft.a Library have been ${RED}deleted ${GREEN}too.${END}"
	@sleep 0.5

re: fclean all
	@echo "\n${GREEN}${BOLD}The libft.a have been remaked correcly.${END}"
	@sleep 0.5

.PHONY: clean fclean all re bonus
