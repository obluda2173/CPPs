/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:20:17 by erian             #+#    #+#             */
/*   Updated: 2025/03/17 12:05:01 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(std::string const &name, unsigned int signGrade, unsigned int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || signGrade > 150)
		throw AForm::GradeTooHighException();
	if (execGrade < 1 || execGrade > 150)
		throw AForm::GradeTooHighException();
};

AForm::~AForm() {};

std::string const &AForm::getName() const {
	return _name;
};

bool AForm::isSigned() const {
	return _signed;
};

unsigned int AForm::getSignGrade() const {
	return _signGrade;
};

unsigned int AForm::getExecGrade() const {
	return _execGrade;
};

void AForm::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	_signed = true;
};

void AForm::execute(Bureaucrat const &executor) const {
	if (!isSigned()) {
		throw FormSignedException();
	} else {
		if (getExecGrade() < executor.getGrade())
			throw GradeTooLowException();
		else
			action();
	}
};

const char *AForm::GradeTooHighException::what() const throw() {
	return "form grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "form grade is too low";
}

const char *AForm::FormSignedException::what() const throw() {
	return "form is already signed";
}

std::ostream &operator<<(std::ostream &out, AForm const &form) {
	out << "form: " << form.getName() << ", " << (form.isSigned() ? "" : "not ") << "signed, sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade();
	return out;
};