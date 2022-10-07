NAME		= so_long

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= main.c display/display_init_imgs.c map/map_validation.c map/map_init_tiles.c \
				map/map_read.c utils/error.c utils/input.c utils/render.c utils/free.c
SRCS_P		= $(addprefix source/, ${SRCS})
OBJS		= ${SRCS_P:.c=.o}

LIBFT_DIR	= libft/
LIBFT_LIB	= libft.a
LIBFT		= $(addprefix ${LIBFT_DIR}, ${LIBFT_LIB})

INCLUDES	= -lmlx -framework OpenGL -framework AppKit

all: ${NAME}

${NAME}: ${OBJS}
	@echo -e "${YELLOW}Making libft...${DEFAULT}"
	@make bonus -C ${LIBFT_DIR}
	@echo -e "${YELLOW}COMPILING SO LONG...${DEFAULT}"
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${INCLUDES} -o ${NAME}
	@echo -e "${GREEN}COMPLETED!${DEFAULT}"

clean:
	@echo -e "${YELLOW}CLEANING FILES...${DEFAULT}"
	@make clean -C ${LIBFT_DIR}
	@rm -rf ${OBJS}
	@rm -rf
	@echo -e "${GREEN}CLEANING DONE...${DEFAULT}"

fclean: clean
	@echo -e "${YELLOW}CLEANING FILES...${DEFAULT}"
	@make fclean -C ${LIBFT_DIR}
	@rm -rf ${NAME}
	@echo -e "${GREEN}CLEANING DONE!${DEFAULT}"

re: fclean all

.PHONY: all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
