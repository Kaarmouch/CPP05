#pragma once

#include <iostream>
#include <string>

class Bureaucrat
{
	private:
		const	std::string _name;
		int	grade;
	public:
		Bureaucrat();
		Bureaucrat(const int);
		Bureaucrat(const std::string&);
		Bureaucrat(const std::string&, const int);
		Bureaucrat(const Bureaucrat&);
		Bureaucrat& operator=(const Bureaucrat&);
		
		std::string getName(void) const;
		int getGrade(void) const;
		void setGrade(const int grade);
		void incrementGrade(void);
		void decrementGrade(void);
		
		~Bureaucrat();


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

std::ostream &operator<<(std::ostream &o, Bureaucrat& a);
