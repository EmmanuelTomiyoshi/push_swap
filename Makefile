NAME 			= push_swap

LIBFT        	= libft/libft.a
LIBFTDIR     	= libft/

SRCDIR  		= src/
OBJDIR  		= obj/
INCDIR  		= include/

BIN				= bin/push_swap

LIBFLAGS 		= -lft
# CFLAGS 		= -Wall -Werror -Wextra
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
					node_operations/ft_nodelete.c					\
					node_operations/ft_count_node_elements.c		\
					print/print_stacks.c							\
					push_operations/operations.c					\
					push_operations/run.c							\
					sort_algorithm/bubble_sort.c					\
					sort_algorithm/check_is_sorted.c				\
					sort_algorithm/short_nb_elem/sort_stack_a.c		\
					sort_algorithm/short_nb_elem/sort_stack_b.c		\
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
# @mkdir -p $(dir $@)
	@${CC} ${CFLAGS} -c $< -o $@

# ${OBJDIR_B}%.o: ${SRCDIR_B}%.c
# 	@echo "$(COLOR_GREEN)Compiling $(COLOR_WHITE)$(<:.c=)"
# 	@${CC} ${CFLAGS} -c $< -o $@

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
# @rm -rf ${OBJDIR_B}
	cd $(LIBFTDIR) && make clean

fclean: clean
	@echo "$(COLOR_RED)Removing $(COLOR_WHITE)$(NAME)"
	rm -rf ${NAME}
	rm -rf ${BIN}
# rm -rf ${BIN_B}
	rm -rf ${LIBFT}

re: fclean all

norm:
	@clear
	@norminette ${SRC} ${INCDIR}* | grep Error || true

test:
	@clear
	@make
	valgrind --leak-check=full --show-leak-kinds=all -s ./push_swap 3 12 10 14 9 1 6 13
.PHONY: re fclean clean all norm

COLOR_WHITE		= \e[00m
COLOR_GREEN		= \e[32m
COLOR_RED		= \e[91m
COLOR_BLUE		= \e[34m