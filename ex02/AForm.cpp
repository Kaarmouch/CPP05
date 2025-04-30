#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void): _name("default"),_isSigned(false), _signGrade(150), _execGrade(150), _target("default") {
	std::cout << "AForm constructor called " << std::endl;
}

AForm::AForm(int sign, int exec): _name("default"), _isSigned(false), _signGrade(sign), _execGrade(exec), _target("default"){
	std::cout << "AForm constructor called signGrade: " << sign << ", execGrade: " << exec << std::endl;
	if (sign > 150 || exec > 150) throw AForm::GradeTooLowException();
	if (sign < 1 || exec < 1) throw AForm::GradeTooHighException();
}

AForm::AForm(const std::string& name): _name(name), _isSigned(false), _signGrade(150), _execGrade(150),_target("default") {
	std::cout << "AForm constructor called name: " << name << std::endl;
}

AForm::AForm(const std::string& name, const std::string& target, int sign, int exec): _name(name), _isSigned(false), _signGrade(sign), _execGrade(exec), _target(target) {
	std::cout << "AForm constructor called name: " << name << "target " + _target <<", signGrade: " << sign << ", execGrade: " << exec << "]" << std::endl;
	if (sign > 150 || exec > 150) throw AForm::GradeTooLowException();
	if (sign < 1 || exec < 1) throw AForm::GradeTooHighException();
}

AForm::~AForm(void) {
	std::cout << "AForm " << _name << " destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm&src) {
	(void)src;
	std::cout << "AForm assignment operator called name: " << _name << ", signGrade: " << _signGrade << ", execGrade: " << _execGrade << std::endl;
	return *this;
}

AForm::AForm(const AForm&src): _name(src._name), _isSigned(src._isSigned), _signGrade(src._signGrade), _execGrade(src._execGrade), _target(src._target) {
	std::cout << "AForm copy constructor called" << std::endl;
}

void AForm::beSigned(const Bureaucrat& signer) {
	if (signer.getGrade() > _signGrade) throw Bureaucrat::GradeTooLowException();
	else if (!_isSigned) {
		this->_isSigned = true;
		std::cout << _name << " AForm succesfully signed by " << signer.getName() << std::endl;
	} else {
		std::cout << _name << " AForm is already signed" << std::endl;
	}
}

const char *AForm::GradeTooHighException::what(void) const throw() {
	return "grade too high";
}

const char *AForm::GradeTooLowException::what(void) const throw() {
	return "grade too low";
}

const char *AForm::FormNotSignedException::what(void) const throw() {
	return "form not signed";
}

std::ostream &operator<<(std::ostream &o, AForm *a)
{
	o << "[AForm] " << a->getName() <<
		"\n - signGrade\t:\t" << a->getSignGrade() <<
		"\n - execGrade\t:\t" << a->getExecGrade() <<
		"\n - isSigned\t:\t" << (a->getIsSigned() ?"true" : " false" ) << std::endl;
	return (o);
}

std::string AForm::getName(void) const {
	return _name;
}

bool AForm::getIsSigned(void) const {
	return _isSigned;
}

int AForm::getSignGrade(void) const {
	return _signGrade;
}

int AForm::getExecGrade(void) const {
	return _execGrade;
}
std::string AForm::getTarget(void) const {
	return _target;
}

void AForm::execute(Bureaucrat const &executor)const
{
	(void)executor;
}
