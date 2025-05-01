#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm","default", 72, 45) {
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", target, 72, 45) {
	std::cout << "RobotomyRequestForm constructor called target: " + target  << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src): AForm("RobotomyRequestForm",src.getTarget(), 72, 45) {
	std::cout << "RobotomyRequestForm copy constructor called target: " + this->getTarget() << std::endl;
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called target: " + this->getTarget() << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	(void)src;
	return *this;
}


// Public Methods
void	RobotomyRequestForm::execute(Bureaucrat const &executor)const
{
	static int robot_fail = 0;
	if ((int)executor.getGrade() > this->getExecGrade())
		throw (Bureaucrat::GradeTooLowException());
	else if (!(this->getIsSigned()))
		throw (AForm::FormNotSignedException());
	else if (robot_fail++ % 2)
		std::cout << "RobotomyRequestForm *VVRRRRRRRRRRRRRRRRRRR*\nRobotomyRequestForm " + this->getTarget() + " was robotomized" << std::endl;
	else
		std::cout << "RobotomyRequestForm Robotomy failed" << std::endl;
}


std::ostream &operator<<(std::ostream &o, RobotomyRequestForm *a)
{
	o << "[RobotomyRequestForm] " << a->getName() <<
		"\n - signGrade\t:\t" << a->getSignGrade() <<
		"\n - execGrade\t:\t" << a->getExecGrade() <<
		"\n - isSigned\t:\t" << (a->getIsSigned() ? " true":" false") << 
		"\n - target\t:\t" << a->getTarget() << std::endl;
	return (o);
}
