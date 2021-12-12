# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/09/15 18:01:23 by xvoorvaa      #+#    #+#                  #
#    Updated: 2021/12/12 18:58:47 by xvoorvaa      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
CFLAGS			=	-Wall -Werror -Wextra
LEAKS			=	-g3 -fsanitize=address
OBJS			=	$(SRCS:.c)
SRCS			=	push_swap.c \
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

GREEN			=	\033[1;32m
BLUE			=	\033[1;36m
RED				=	\033[0;31m
NC				=	\033[0m # No Color

START			= "$(BLUE)---\nStarting...!\n---$(NC)"
MESSAGE			= "$(BLUE)---\nCompiling done! Run ./push_swap\n---$(NC)"
COMP_MESSAGE	= "$(GREEN)Building C object... $(NC)%-33.33s\r\n"
REM_MESSAGE		= "$(RED)Removing files...$(NC)"

all:		$(NAME)

$(NAME): decoy
	@gcc $(CFLAGS) $(SRCS) -o $(NAME)
	@printf $(COMP_MESSAGE) $(SRCS)
	@echo $(MESSAGE)

decoy:
	@echo $(START)

leaks:
	@gcc $(CFLAGS) $(SRCS) $(LEAKS) -o $(NAME)
	@printf $(COMP_MESSAGE) $(SRCS)
	@echo $(MESSAGE)

clean:
	@echo "\n"
	@rm -f $(OBJS)
	@printf $(REM_MESSAGE)
	@echo "\n"


fclean:		clean
	@rm -f push_swap
	@rm -rf push_swap.dSYM

re:			fclean all

.PHONY:		all leaks clean fclean re