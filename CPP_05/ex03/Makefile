NAME		= 	intern

# Configuration
CC			= c++
CPP_FLAGS	= -Wall -Werror -Wextra -std=c++11
RM			= rm -rf
HEADERS		= -I ./include

# Source Files
SRC			=	src/main.cpp \
					src/Bureaucrat.cpp \
					src/AForm.cpp \
					src/PresidentialPardonForm.cpp \
					src/RobotomyRequestForm.cpp \
					src/ShrubberyCreationForm.cpp \
					src/Intern.cpp

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
	$(RM) *_shrubbery

re:		fclean all

.phony: all clean fclean re	