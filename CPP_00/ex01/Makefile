# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: diwalaku <diwalaku@codam.student.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2025/01/16 17:27:03 by diwalaku      #+#    #+#                  #
#    Updated: 2025/03/11 21:11:31 by diwalaku      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= phonebook

# Configuration
CC			= c++
CPP_FLAGS	= -Wall -Werror -Wextra
CPP_FLAGS	+= -std=c++98
RM			= rm -rf
HEADERS		= -I ./include
# Source Files
SRC			= src/main.cpp src/Contact.cpp src/PhoneBook.cpp src/utils.cpp

# Object Files and Directories
OBJDIR		= obj
OBJ			= $(addprefix $(OBJDIR)/, $(notdir $(SRC:.cpp=.o)))

# Objectives
all:	$(NAME)

$(NAME): $(OBJ)
		$(CC) $(OBJ) $(CPP_FLAGS) $(HEADERS) -o $(NAME)

$(OBJDIR)/%.o: src/%.cpp
		@mkdir -p $(OBJDIR)
		$(CC) $(CPP_FLAGS) $(HEADERS) -c -o $@ $^

# Cleaning
clean:
		$(RM) $(OBJDIR)

fclean: clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re