#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), grade(150) {
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name): _name(name), grade(150) {
	std::cout << name << " have been created" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade): _name(name) {
	this->setGrade(grade);
	std::cout << "BC " << name << " lvl " << grade << " pop out" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat&src): _name(src._name + "(clone)") {
    std::cout << _name << " copy constructor called " << this->grade << std::endl;
    *this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat&src) {
    std::cout << _name << " assignation operator called" << std::endl;
    if (this == &src) return *this;
    this->setGrade(src.grade);
    return *this;
}

Bureaucrat::~Bureaucrat(void) {
    std::cout << _name << " destructor called" << std::endl;
}

void Bureaucrat::incrementGrade() {
    std::cout << _name << " incrementing grade" << std::endl;
    setGrade(this->grade - 1);
}

void Bureaucrat::decrementGrade() {
    std::cout << _name << " decrementing grade" << std::endl;
    setGrade(this->grade + 1);
}

std::string Bureaucrat::getName(void) const {
    return _name;
}

int Bureaucrat::getGrade(void) const {
    return grade;
}

void Bureaucrat::setGrade(const int lvl) {
    if (lvl < 1) throw Bureaucrat::GradeTooHighException();
    else if (lvl > 150) throw Bureaucrat::GradeTooLowException();
    else this->grade = lvl;
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("grade too low");
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("grade too high");
}


void Bureaucrat::signForm(Form &form) {
    form.beSigned(*this);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat& a)
{
	o << a.getName() << ", bureaucrat grade " << a.getGrade() << std::endl;
	return (o);
}
