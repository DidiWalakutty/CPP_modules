NAME 		= sed

# Configuration
CC 			= c++
CPP_FLAGS	= -Wall -Werror -Wextra -std=c++11
RM			= rm -rf
HEADERS		= -I ./include

# Source Files
<<<<<<< HEAD
SRC			= src/main.cpp
=======
SRC			= src/main.cpp \
				src/Sed.cpp
>>>>>>> b7fc9b57c89d2cecb962810bfe636aefbe296165

OBJDIR		= obj
OBJ			= $(addprefix $(OBJDIR)/, $(notdir $(SRC:.cpp=.o)))

# Objectives
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPP_FLAGS) $(OBJ) $(HEADERS) -o $(NAME)

$(OBJDIR)/%.o: src/%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CPP_FLAGS) -c -o $@ $<

# Cleaning
clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re:		fclean all

.phony: all clean fclean re