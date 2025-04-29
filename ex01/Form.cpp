#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _Fname("Default"), _signed(0), signGrade(150), exeGrade(150) {
	std::cout << "Default Form constructor called" << std::endl;
}
Form::Form(const std::string Fname): _Fname(Fname), _signed(0), signGrade(150), exeGrade(150) {
        std::cout << Fname << "'s form builded" << std::endl;
}
Form::Form(const int lvlS): _Fname("Default"), _signed(0), signGrade(lvlS), exeGrade(150) {
        std::cout << "Default Form constructor called, lvl require to sign it : "<< lvlS << std::endl;
	if (lvlS < 1) throw Form::GradeTooHighException();
	if (lvlS > 150) throw Form::GradeTooLowException();
}
Form::Form(const int lvlS, const int lvlE): _Fname("Default"), _signed(0), signGrade(lvlS), exeGrade(lvlE) {
        std::cout << "Default Form constructor called, require "<< lvlS << "/"<< lvlE << " to signe/exe"<< std::endl;
	if (lvlS < 1 || lvlE < 1) throw Form::GradeTooHighException();
	if (lvlS > 150 || lvlE > 150) throw Form::GradeTooLowException();
}

Form::Form(std::string Fname, const int lvlS, const int lvlE): _Fname(Fname), _signed(0), signGrade(lvlS), exeGrade(lvlE) {
        std::cout << Fname << "'s form builded, require "<< lvlS << "/"<< lvlE << " to signe/exe"<< std::endl;
	if (lvlS < 1 || lvlE < 1) throw Form::GradeTooHighException();
	if (lvlS > 150 || lvlS > 150) throw Form::GradeTooLowException();
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		// _Fname is const, so it cannot be reassigned
		this->_signed = other._signed;
		// signGrade and exeGrade are const too and cannot be reassigned
		// You'll need to reconsider how assignment works here, or avoid defining operator= entirely
	}
	return *this;
}

Form::~Form() {
	std::cout << "Form " << _Fname << " destroyed" << std::endl;
}

Form::Form(const Form&src): _Fname(src._Fname), _signed(src._signed), signGrade(src.signGrade), exeGrade(src.exeGrade) {
    std::cout << "Form copy constructor called" << std::endl;
}

void Form::beSigned(const Bureaucrat& B) 
{
	if ((B.getGrade()) > signGrade) throw Form::GradeTooLowException();
	else if (!_signed) {
		_signed = 1;
		std::cout << B.getName() << " signed " << _Fname << std::endl;
	}
	else
		std::cout << B.getName() << " couldnt sign " << _Fname << ", Form's already signed"<< std::endl;
}

std::string Form::getFname() const{
    return _Fname;
}

bool Form::getIsSigned() const  {
    return _signed;
}

int Form::getSignGrade() const{
    return signGrade;
}

int Form::getExeGrade() const {
    return exeGrade;
}

const char *Form::GradeTooHighException::what(void) const throw() {
    return "grade too high";
}

const char *Form::GradeTooLowException::what(void) const throw() {
    return "grade too low";
}

std::ostream &operator<<(std::ostream &o, Form *a) 
{
	o << "Form " << a->getFname() <<
	"\n - signGrade:\t" << a->getSignGrade() <<
	"\n - execGrade:\t" << a->getExeGrade() <<
	"\n - isSigned:\t" << (a->getIsSigned() ? "true":"false") << std::endl;
	return (o);
}

