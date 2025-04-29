#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern
{
	private:
	public:
		Intern();
		Intern(const Intern&);
		Intern &operator=(const Intern&);
		~Intern();

		AForm *makeForm(const std::string &name,const std::string &target);

};
