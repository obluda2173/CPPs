# program name
NAME		=	ex03

# compiler and flags
CXX			=	@c++
CXXFLAGS	=	-std=c++98 -Wall -Wextra -Werror

# sources and objects
SRCDIR		=	src
INCDIR		=	inc
OBJDIR		=	obj
SRC			=	src/_main.cpp \
				src/Bureaucrat.cpp \
				src/AForm.cpp \
				src/PresidentialPardonForm.cpp \
				src/RobotomyRequestForm.cpp \
				src/ShrubberyCreationForm.cpp \
				src/Intern.cpp
OBJ			=	$(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# colors for output
RED			:=	\033[1;31m
GREEN		:=	\033[1;32m
BLUE		:=	\033[1;34m
RESET		:=	\033[0m

# default target
all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# link objects to create executable
$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "$(BLUE)built successfully$(RESET)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

# clean object files
clean:
	@echo "$(RED)cleaning objects$(RESET)"
	@rm -fr $(OBJDIR)
	@rm -f *shrubbery

# clean executable and object files
fclean: clean
	@echo "$(RED)cleaning executable$(RESET)"
	@rm -f $(NAME)

# rebuild
re: fclean all

# declare targets as not files
.PHONY: all clean fclean re