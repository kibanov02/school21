SRCS	= create_mtx.c free_mtx.c get_m.c get_n.c no_file.c print_error.c fill_map_and_mtx.c main.c print_map.c

OBJS 	= ${SRCS:.c=.o}

NAME	= bsq

CC		= gcc

RM 		= rm -f

CFLAGS	= -Wall -Wextra -Werror
	
${NAME}: ${OBJS}
		${CC} ${CFLAGS} -I ft.h ${SRCS} -o ${NAME}

all:	${NAME}
clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}