#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class AForm;

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string);
		ShrubberyCreationForm(ShrubberyCreationForm&);

		~ShrubberyCreationForm(void);

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm&);

		void execute(const Bureaucrat&)const;
};

std::ostream &operator<<(std::ostream&, ShrubberyCreationForm*);
