#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class PresidentialPardonForm: public AForm {
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm&);
        ~PresidentialPardonForm();
        PresidentialPardonForm &operator=(const PresidentialPardonForm&);

        void execute(const Bureaucrat&) const;
};

std::ostream &operator<<(std::ostream&, PresidentialPardonForm*);
