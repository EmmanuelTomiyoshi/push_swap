NAME 			= push_swap

LIBFT        	= libft/libft.a
LIBFTDIR     	= libft/

SRCDIR  		= src/
OBJDIR  		= obj/
INCDIR  		= include/

BIN				= bin/push_swap

LIBFLAGS 		= -lft
CFLAGS			= -Wall -Werror -Wextra
CFLAGS 			+= -g -I ${LIBFTDIR} -I ${INCDIR}
LIBFLAGS 		= -lft
CC 				= cc

FILES   		=	data_handling/free_memory.c						\
					data_handling/init_data.c						\
					error_handling/check_args.c						\
					error_handling/error_message.c					\
					error_handling/utils_error_handling.c			\
					node_operations/ft_clearnode.c					\
					node_operations/ft_lastnode.c					\
					node_operations/ft_newnode.c					\
					node_operations/ft_nodeadd_back.c				\
					node_operations/ft_nodeadd_front.c				\
					push_operations/operations.c					\
					push_operations/run.c							\
					sort_algorithm/bubble_sort.c					\
					sort_algorithm/check_is_sorted.c				\
					sort_algorithm/normalise_values.c				\
					sort_algorithm/sort_less_than_six_elements.c	\
					sort_algorithm/radix.c							\
					sort_algorithm/utils_sort_algorithm.c			\
					main.c

SRC 			= ${addprefix ${SRCDIR}, ${FILES}}
OBJ 			= ${addprefix ${OBJDIR}, ${FILES:.c=.o}}

REQUIRED_DIRS	= ${sort ${dir ${OBJ}}} bin/

all: ${NAME}

print:
	echo ${REQUIRED_DIRS}

${REQUIRED_DIRS}:
	@mkdir -p $@

${OBJDIR}%.o: ${SRCDIR}%.c
	@echo "$(COLOR_GREEN)Compiling $(COLOR_WHITE)$(<:.c=)"
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${LIBFT} ${REQUIRED_DIRS} ${OBJ}
	@${CC} ${CFLAGS} ${OBJ} -L ${LIBFTDIR} ${LIBFLAGS} -o ${BIN}
	@cp ${BIN} ${NAME}
	@echo "$(COLOR_GREEN)Compiled Successfully$(COLOR_WHITE)"

${LIBFT}:
	make -C ${LIBFTDIR}
	make bonus -C ${LIBFTDIR}

clean:
	@echo "$(COLOR_RED)Removing $(COLOR_WHITE)all objects"
	@rm -rf ${OBJDIR}
	cd $(LIBFTDIR) && make clean

fclean: clean
	@echo "$(COLOR_RED)Removing $(COLOR_WHITE)$(NAME)"
	rm -rf ${NAME}
	rm -rf ${BIN}
	rm -rf ${LIBFT}

re: fclean all

norm:
	@clear
	@norminette ${SRC} ${INCDIR}* | grep Error || true

.PHONY: re fclean clean all norm

COLOR_WHITE		= \e[00m
COLOR_GREEN		= \e[32m
COLOR_RED		= \e[91m
COLOR_BLUE		= \e[34m