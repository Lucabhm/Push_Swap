NAME = push_swap
NAMEB = checker
CFLAGS = -Wall -Werror -Wextra -fsanitize=address
SRCS = src/push_swap.c \
		src/checkerparsing.c \
		src/parsing.c \
		src/operations.c \
		src/operations2.c \
		src/operations3.c \
		src/helper.c \
		src/free.c \
		src/check.c \
		src/best_rotate.c
SRCSB = src_bonus/checker_bonus.c \
		src_bonus/free_bonus.c \
		src/parsing.c \
		src/checkerparsing.c \
		src/free.c \
		src/operations.c \
		src/operations2.c \
		src/operations3.c \
		src/helper.c \
		src/best_rotate.c \
		src/check.c
OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)
PATHLIBFT = lib/libft
PATHPRINT = lib/printf
PATHGETNEXT = lib/get_next_line
INLIBFT = -L $(PATHLIBFT) -lft
INPRINT = -L $(PATHPRINT) -lftprintf
INGETNEXT = -L $(PATHGETNEXT) -lftget_next_line
INPUSH = -I include/push_swap.h
INCHECK = -I include_bonus/checker_bonus.h

RED = '\033[1;31m'
BLUE = '\033[0;94m'
DEF_COLOR = '\033[0;39m'

$(NAME):		$(OBJS)
				@echo $(BLUE)"Compiling libft..."$(DEF_COLOR)
				@cd $(PATHLIBFT) && $(MAKE)
				@echo $(BLUE)"Compiling libft bonus..."$(DEF_COLOR)
				@cd $(PATHLIBFT) && $(MAKE) bonus
				@echo $(BLUE)"Compiling printf..."$(DEF_COLOR)
				@cd $(PATHPRINT) && $(MAKE)
				@echo $(BLUE)"Compiling $(NAME)..."$(DEF_COLOR)
				@cc $(OBJS) $(INLIBFT) $(INPRINT) -o $(NAME) $(INPUSH) $(CFLAGS)

$(NAMEB):		$(OBJSB)
				@echo $(BLUE)"Compiling libft..."$(DEF_COLOR)
				@cd $(PATHLIBFT) && $(MAKE)
				@echo $(BLUE)"Compiling libft bonus..."$(DEF_COLOR)
				@cd $(PATHLIBFT) && $(MAKE) bonus
				@echo $(BLUE)"Compiling printf..."$(DEF_COLOR)
				@cd $(PATHPRINT) && $(MAKE)
				@echo $(BLUE)"Compiling get_next_line..."$(DEF_COLOR)
				@cd $(PATHGETNEXT) && $(MAKE)
				@echo $(BLUE)"Compiling $(NAMEB)..."$(DEF_COLOR)
				@cc $(OBJSB) $(INLIBFT) $(INPRINT) -o $(NAMEB) $(INPUSH) $(INCHECK) $(INGETNEXT) $(CFLAGS)

all:			$(NAME)

bonus:			$(NAMEB)

%.o:%.c
				@cc -c $< -o $@ $(CFLAGS)

clean:
				@echo $(RED)"Cleaning object files..."$(DEF_COLOR)
				@rm -f $(OBJS)
				@rm -f $(OBJSB)
				@cd $(PATHLIBFT) && $(MAKE) clean
				@cd $(PATHPRINT) && $(MAKE) clean
				@cd $(PATHGETNEXT) && $(MAKE) clean

fclean:			clean
				@echo $(RED)"Cleaning executable files..."$(DEF_COLOR)
				@rm -f $(NAME)
				@rm -f $(NAMEB)
				@cd $(PATHLIBFT) && $(MAKE) fclean
				@cd $(PATHPRINT) && $(MAKE) fclean
				@cd $(PATHGETNEXT) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re bonus