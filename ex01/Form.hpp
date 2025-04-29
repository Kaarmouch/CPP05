#pragma once

#include <string>
#include <iostream>
class Bureaucrat;

class Form
{
	private:
		const	std::string _Fname;
		bool	_signed;
		const int	signGrade;
		const int	exeGrade;
	public:
		Form();
		Form(const std::string);
		Form(const int);
		Form(const int ,const int);
		Form(std::string ,const int ,const int);
		Form(const Form&);
		Form& operator=(const Form&);
		
		~Form();

		std::string getFname() const;
		bool getIsSigned() const ;
		int getSignGrade() const;
		int getExeGrade() const;

		void beSigned(const Bureaucrat& B);
		class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what(void) const throw();
	};

		class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Form& a);
