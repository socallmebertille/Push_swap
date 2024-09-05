NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror -g3
SRCS = push_swap.c push_split.c push_parsing.c free_init.c check_stack.c list_utils.c list_swap.c list_rotate.c list_reverse_rotate.c list_push.c three_node_sort.c push_algo.c push_algo_init.c
OBJS = ${SRCS:.c=.o}

GREEN = \033[1;32m
RED = \033[1;31m
YELLOW = \033[1;33m
ORANGE = \033[38;5;214m
PURPLE = \033[1;35m
BOLD := \033[1m
RESET = \033[0m 

SUCCESS = [ ✔ ]
ERROR = [ ✗ ]
CLEAN = [ ♻ ]
REMOVE = [ 🗑 ]
REDO = [ 🗘 ]

all: ${NAME}

${NAME}: ${OBJS}

.c.o:
	@${CC} ${FLAGS} -c $< -o $@ || (echo "\n${RED} ============ ${ERROR} Compilation failed ! ==================== ${NC}\n"; exit 1)
	@echo "${GREEN} ============ ${SUCCESS} Successful compilation ! ================ ${RESET}"

clean:
	@rm -rf ${OBJS}
	@echo "${YELLOW} ============ ${CLEAN} Successful binary cleaning ! ============ ${RESET}"

fclean: clean
	@rm -rf ${NAME}
	@echo "${BOLD}${ORANGE} ============ ${REMOVE} Deleted executable ! ==================== ${RESET}"

re: fclean all
	@echo "${PURPLE} ============ ${REDO} Redo completed ! ======================== ${RESET}"

.PHONY: all clean fclean re