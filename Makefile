NAME = playground.a
CC = gcc
EXE = main
CFLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
DEBUGGER = lldb
DSYM = main.dSYM
AR = ar -rc
RM = rm -rf

run: all
	@$(CC) -g $(EXE).c $(NAME) -o $(EXE)
	@./$(EXE)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(EXE) $(DSYM)

re:
	fclean all

db: run
	$(DEBUGGER) $(EXE)

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRCS)
	@norminette -R CheckDefine includes/*.h

.PHONY: all clean fclean re run norm
