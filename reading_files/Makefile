# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 02:45:29 by tkomeno           #+#    #+#              #
#    Updated: 2022/05/07 08:04:24 by tkomeno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = reading.a
EXE = main

CC = gcc
DB = lldb
RM = rm -rf
AR = ar -rc

SRCS = reading.c
OBJS = $(SRCS:.c=.o)

DEFAULT_BS=256

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(EXE) $(EXE).dSYM

re: fclean all

compile: all
	@$(CC) -g $(EXE).c $(NAME) -o $(EXE)

run: compile
	@echo ""
	@echo "🚀 OUTPUT:"
	@echo "────────────────"
	@./$(EXE)
	@echo ""
	@echo "────────────────"

db: compile
	clear
	$(DB) $(EXE)

norm:
	@norminette -R CheckForbiddenSourceHeader $(SRCS)
	@norminette -R CheckDefine *.h

.PHONY: all clean fclean re compile run db norm
