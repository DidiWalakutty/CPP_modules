NAME		= 	base

# Configuration
CC			= c++
CPP_FLAGS	= -Wall -Werror -Wextra -std=c++11
RM			= rm -rf
HEADERS		= -I ./include

# Source Files
SRC			=	src/main.cpp \
					src/base.cpp
					

OBJDIR		= obj
OBJ			= $(addprefix $(OBJDIR)/, $(notdir $(SRC:.cpp=.o)))

# Objectives
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPP_FLAGS) $(OBJ) $(HEADERS) -o $(NAME)

$(OBJDIR)/%.o: src/%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CPP_FLAGS) -c -o $@ $<

test: $(NAME)
	@echo "${BLUE}Running tests...${DONE}"
	@./test.sh
	
# Cleaning
clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re:		fclean all

.phony: all clean fclean re	