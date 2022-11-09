NAME 			= push_swap

LIBFT        	= libft/libft.a
LIBFTDIR     	= libft/
LIBPRINTFDIR 	= ft_printf/
FT_PRINTF    	= ft_printf/libftprintf.a
FT_PRINTFDIR 	= ft_printf/include

SRCDIR  		= src/
OBJDIR  		= obj/
# SRCDIR_B  	= src_bonus/
# OBJDIR_B		= obj_bonus/
INCDIR  		= include/

BIN				= bin/push_swap
# BIN_B			= bin/push_swap_bonus


LIBFLAGS 		= -lft
# CFLAGS 		= -Wall -Werror -Wextra
CFLAGS 			+= -g -I ${FT_PRINTFDIR} -I ${LIBFTDIR} -I ${INCDIR}
LIBFLAGS 		= -lft -lftprintf
CC 				= cc

FILES   		=	data_handling/free_memory.c					\
					data_handling/init_data.c					\
					error_handling/check_args.c					\
					error_handling/error_message.c				\
					error_handling/utils_error_handling.c		\
					node_operations/ft_clearnode.c				\
					node_operations/ft_lastnode.c				\
					node_operations/ft_newnode.c				\
					node_operations/ft_nodeadd_back.c			\
					node_operations/ft_nodeadd_front.c			\
					node_operations/ft_nodel.c					\
					print/print_stacks.c						\
					push_operations/operations.c				\
					push_operations/run.c						\
					sort_algorithm/check_is_sorted.c			\
					sort_algorithm/less_than_six.c				\
					sort_algorithm/utils_sort_algorithm.c		\
					main.c
# FILES_B		=	

SRC 			= ${addprefix ${SRCDIR}, ${FILES}}
OBJ 			= ${addprefix ${OBJDIR}, ${FILES:.c=.o}}
# SRC_B 			= ${addprefix ${SRCDIR_B}, ${FILES_B}}
# OBJ_B 			= ${addprefix ${OBJDIR_B}, ${FILES_B:.c=.o}}

REQUIRED_DIRS	= ${sort ${dir ${OBJ}}} bin/
# REQUIRED_DIRS	= ${OBJDIR} bin/
# REQUIRED_DIRS	= ${OBJDIR} ${OBJDIR_B} bin/

all: ${NAME}

print:
	echo ${REQUIRED_DIRS}
# bonus: ${BIN_B}

${REQUIRED_DIRS}:
	@mkdir -p $@

${OBJDIR}%.o: ${SRCDIR}%.c
	@echo "$(COLOR_GREEN)Compiling $(COLOR_WHITE)$(<:.c=)"
# @mkdir -p $(dir $@)
	@${CC} ${CFLAGS} -c $< -o $@

# ${OBJDIR_B}%.o: ${SRCDIR_B}%.c
# 	@echo "$(COLOR_GREEN)Compiling $(COLOR_WHITE)$(<:.c=)"
# 	@${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${FT_PRINTF} ${LIBFT} ${REQUIRED_DIRS} ${OBJ}
	@${CC} ${CFLAGS} ${OBJ} -L ${LIBFTDIR} \
	-L ${LIBPRINTFDIR} -lftprintf ${LIBFLAGS} -o ${BIN}
	@cp ${BIN} ${NAME}
	@echo "$(COLOR_GREEN)Compiled Successfully$(COLOR_WHITE)"

# ${BIN_B}: ${FT_PRINTF} ${LIBFT} ${REQUIRED_DIRS} ${OBJ_B}
# 	@${CC} ${CFLAGS} ${OBJ_B} -L ${LIBFTDIR} \
# 	-L ${LIBPRINTFDIR} -lftprintf ${LIBFLAGS} -o ${BIN_B}
# 	@cp ${BIN_B} ${NAME}
# 	@echo "$(COLOR_GREEN)Compiled Successfully$(COLOR_WHITE)"

${LIBFT}:
	make -C ${LIBFTDIR}
	make bonus -C ${LIBFTDIR}

${FT_PRINTF}:
	make -C ${LIBPRINTFDIR}

clean:
	@echo "$(COLOR_RED)Removing $(COLOR_WHITE)all objects"
	@rm -rf ${OBJDIR}
# @rm -rf ${OBJDIR_B}
	cd $(LIBPRINTFDIR) && make clean
	cd $(LIBFTDIR) && make clean

fclean: clean
	@echo "$(COLOR_RED)Removing $(COLOR_WHITE)$(NAME)"
	rm -rf ${NAME}
	rm -rf ${BIN}
# rm -rf ${BIN_B}
	rm -rf ${FT_PRINTF}
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