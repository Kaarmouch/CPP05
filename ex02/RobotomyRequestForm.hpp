#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class RobotomyRequestForm: public AForm {
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm&);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm&);

		void execute(const Bureaucrat&) const;
};

std::ostream &operator<<(std::ostream&, RobotomyRequestForm*);
