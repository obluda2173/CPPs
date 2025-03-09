/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:24:44 by erian             #+#    #+#             */
/*   Updated: 2025/03/09 17:20:00 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const &name, unsigned int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade; 
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
	if (this != &other)
		_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string const &Bureaucrat::getName() const {
	return _name;
}

unsigned int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << GREEN << _name << " signs " << form.getName() << NC << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << _name << " cannot sign " << form.getName() << " because " << e.what() << NC << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "bureaucrat grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "bureaucrat grade is too low";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}