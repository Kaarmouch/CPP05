#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", "default", 72, 45) {
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", target,  72, 45){
	std::cout << "PresidentialPardonForm constructor called target: " + _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src): AForm("PresidentialPardonForm", src.getTarget, 72, 45), _target(src.getTarget()) {
	std::cout << "PresidentialPardonForm copy constructor called target: " + _target << std::endl;
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called target: " + _target  << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
	(void)src;
	return *this;
}


// Public Methods
void	PresidentialPardonForm::execute(Bureaucrat const &executor)const
{
	if ((int)executor.getGrade() > this->getExecGrade())
		throw (Bureaucrat::GradeTooLowException());
	else if (!(this->getIsSigned()))
		throw (AForm::FormNotSignedException());
	else
		std::cout << "PresidentialPardonForm " + _target + " has been pardoned by Zaphod Beeblerox" << std::endl;
}


std::string	PresidentialPardonForm::getTarget(void) const { return _target; }

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm *a)
{
	o << "PresidentialPardonForm " << a->getName() <<
		"\n - signGrade\t:\t" << a->getSignGrade() <<
		"\n - execGrade\t:\t" << a->getExecGrade() <<
		"\n - isSigned\t:\t" << (a->getIsSigned() ? "true": "false") << 
		"\n - target\t:\t" << a->getTarget() << std::endl;
	return (o);
}
