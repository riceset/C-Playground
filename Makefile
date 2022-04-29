NAME = playground.a
CFLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
DSYM = main.dSYM
AR = ar -rc
RM = rm -rf
EXE = main
DB = lldb
CC = gcc

run: all
	@$(CC) -g $(EXE).c $(NAME) -o $(EXE)
	@./$(EXE)

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\n"
	@$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(EXE) $(DSYM)

re: fclean run

db: run
	$(DB) $(EXE)

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRCS)
	@norminette -R CheckDefine includes/*.h

.PHONY: run all clean fclean re db norm
