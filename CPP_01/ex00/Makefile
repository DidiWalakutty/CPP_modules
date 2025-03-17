# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: diwalaku <diwalaku@codam.student.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/03/17 16:14:57 by diwalaku      #+#    #+#                  #
#    Updated: 2025/03/17 17:51:58 by diwalaku      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= zombie

# Configuration
CC			= c++
CPP_FLAGS	= -Wall -Werror -Wextra
CPP_FLAGS	+= -std=c++11
RM			= rm -rf
HEADERS		= -I ./include

SRCDIR	= src/
OBJDIR	= obj/

# Source Files
SRC			=	src/main.cpp \
				src/Zombie.cpp \
				src/newZombie.cpp \
				src/randomChump.cpp

SRCOBJ = $(SRC:%.cpp=$(OBJDIR)%.o)

all: $(NAME)

$(NAME): $(SRCOBJ)
	$(CC) $(CPP_FLAGS) $(SRCOBJ) $(HEADERS) -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c $(CPP_FLAGS) -o $@ $<

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

.phony: all clean fclean re	