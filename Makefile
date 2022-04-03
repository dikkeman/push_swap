# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/09/15 18:01:23 by xvoorvaa      #+#    #+#                  #
#    Updated: 2022/04/03 22:21:32 by xander        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
CFLAGS			=	-Wall -Werror -Wextra
OBJ_DIR			=	OBJ
SRC_DIR			=	SRC
INC_DIR			=	INC
SRCS			=	SRC/push_swap.c \
					SRC/stack_a/algorithm_sa.c \
					SRC/stack_a/algorithm_ra.c \
					SRC/stack_b/algorithm_rb.c \
					SRC/algorithm_p.c \
					SRC/tree_sort.c \
					SRC/algorithm_sort.c \
					SRC/big_sort.c \
					SRC/linkedlist.c \
					SRC/libft/ft_atoi.c  \
					SRC/libft/ft_atol.c  \
					SRC/libft/ft_isdigit.c \
					SRC/libft/ft_calloc.c \
					SRC/libft/ft_bzero.c \
					SRC/errno.c

SHELL		:= /bin/bash
SOURCES		:= $(shell find $(SRC_DIR) -type f -name "*.c")
HEADERS		:= INC/push_swap.h
OBJS		:= $(SRCS:.c=.o)
OBJECTS		:= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(OBJS))

PINK = \x1b[35;01m
BLUE = \x1b[34;01m
YELLOW = \x1b[33;01m
GREEN = \x1b[32;01m
RED = \x1b[31;01m
WHITE = \x1b[31;37m
RESET = \x1b[0m

START			=	"$(BLUE)---\nStarting...!\n---\n$(RESET)"
MESSAGE			=	"$(BLUE)---\nCompiling done!\n---\n$(RESET)"
COMP_MESSAGE	=	"$(GREEN)Building C object... $(RESET)%-33.33s\r\n"
REM_MESSAGE		=	"$(RED)Removing files...$(RESET)"

ifdef DEBUG
  FLAGS += -g -fsanitize=address
else
  FLAGS += -Ofast
endif

all:	$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)

$(OBJ_DIR):
	@mkdir $@

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@printf $(START)
	@printf $(COMP_MESSAGE) $(SOURCES)
	@printf $(MESSAGE)

clean:
	@printf "\n"
	@rm -rf $(OBJ_DIR)
	@printf $(REM_MESSAGE)
	@printf "\n"


fclean:		clean
	@rm -f push_swap
	@rm -rf push_swap.dSYM

re:			fclean all

.PHONY:		all leaks clean fclean re
