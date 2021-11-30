# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/09/15 18:01:23 by xvoorvaa      #+#    #+#                  #
#    Updated: 2021/11/30 20:29:28 by xvoorvaa      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
CFLAGS			=	-Wall -Werror -Wextra
LEAKS			=	-g3 -fsanitize=address
OBJS			=	$(SRCS:.c)
SRCS			=	push_swap.c \
					linkedlist.c \
					stack_a/algorithm_sa.c \
					stack_a/algorithm_ra.c \
					stack_b/algorithm_sb.c \
					stack_b/algorithm_rb.c \
					tree_sort.c \
					algorithm_p.c \
					algorithm_sort.c \
					big_sort.c \
					libft/ft_atoi.c  \
					libft/ft_isdigit.c \
					libft/ft_calloc.c \
					libft/ft_bzero.c \

GREEN			=	\033[1;32m
BLUE			=	\033[1;36m
RED				=	\033[0;31m
NC				=	\033[0m # No Color

MESSAGE			= "$(BLUE)---\nCompiling done! Run ./push_swap\n---"
COMP_MESSAGE	= "$(GREEN)Building C object... $(NC)%-33.33s\r\n"
REM_MESSAGE		= "$(RED)Removing files..."

all:		$(NAME)

$(NAME):	$(OBJS)
	@gcc $(CFLAGS) $(SRCS) -o $(NAME)
	@printf $(COMP_MESSAGE) $(SRCS)
	@echo $(MESSAGE)

leaks:		$(NAME)
	@gcc $(CFLAGS) $(SRCS) $(LEAKS) -o $(NAME)
	@printf $(COMP_MESSAGE) $(SRCS)
	@echo $(MESSAGE)

clean:
	@rm -f $(OBJS)
	@printf $(REM_MESSAGE)
	@echo "\n"


fclean:		clean
	@rm -f push_swap

re:			fclean all

.PHONY:		all clean fclean re