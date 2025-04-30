NAME	=	Forms

CPP		=	c++ -Wall -Wextra -Werror -std=c++98

SRC		=	main.cpp					\
			AForm.cpp					\
			Bureaucrat.cpp				\
			ShrubberyCreationForm.cpp	\
			RobotomyRequestForm.cpp		\
			PresidentialPardonForm.cpp		\

OBJ     = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CPP) -c $< -o $@

$(NAME): $(OBJ)
	$(CPP) $(OBJ) -o $(NAME)

all		:
	$(CPP) $(SRC) -o $(NAME)

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean all
