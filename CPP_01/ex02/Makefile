NAME		= brain

# Configuration
CC			= c++
CPP_FLAGS	= -Wall -Werror -Wextra
CPP_FLAGS	+= -std=c++98
RM			= rm -rf

# Source Files
SRC			= main.cpp

# Object Files and Directories
OBJDIR		= obj
OBJ			= $(notdir $(SRC:.c=.o))

# Objectives
all:	$(NAME)

$(NAME): $(OBJ)
		$(CC) $(OBJ) $(CPP_FLAGS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
		@mkdir -p $(OBJDIR)
		$(CC) $(CPP_FLAGS) -c -o $@ $^

# Cleaning
clean:
		$(RM) $(OBJDIR)

fclean: clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re