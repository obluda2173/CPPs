/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:20:17 by erian             #+#    #+#             */
/*   Updated: 2025/03/09 17:27:29 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _signed(false), _signGrade(150), _execGrade(150) {}

Form::Form(std::string const &name, unsigned int signGrade, unsigned int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || signGrade > 150)
		throw Form::GradeTooHighException();
	if (execGrade < 1 || execGrade > 150)
		throw Form::GradeTooHighException();
};

Form::Form(Form const &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade) {};

Form &Form::operator=(Form const &other) {
	if (this != &other)
		_signed = other._signed;
	return *this;
};

Form::~Form() {};

std::string const &Form::getName() const {
	return _name;
};

bool Form::isSigned() const {
	return _signed;
};

unsigned int Form::getSignGrade() const {
	return _signGrade;
};

unsigned int Form::getExecGrade() const {
	return _execGrade;
};

void Form::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	_signed = true;
};

const char *Form::GradeTooHighException::what() const throw() {
	return "form grade is too high";
};

const char *Form::GradeTooLowException::what() const throw() {
	return "form grade is too low";
};

std::ostream &operator<<(std::ostream &out, Form const &form) {
	out << "form: " << form.getName() << ", " << (form.isSigned() ? "" : "not ") << "signed, sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade();
	return out;
};