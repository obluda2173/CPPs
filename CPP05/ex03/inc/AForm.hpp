/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:04:21 by erian             #+#    #+#             */
/*   Updated: 2025/03/09 17:24:23 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>

#include "_Colors.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		// attriburtes
		std::string const _name;
		bool _signed;
		unsigned int const _signGrade;
		unsigned int const _execGrade;

	public:
		// OCN
		AForm();
		AForm(std::string const &name, unsigned int signGrade, unsigned int execGrade);
		virtual ~AForm();

		// getters n setters
		std::string const &getName() const;
		bool isSigned() const;
		unsigned int getSignGrade() const;
		unsigned int getExecGrade() const;

		// methods
		void beSigned(Bureaucrat const &bureaucrat);
		void execute(Bureaucrat const &executor) const;
		virtual void action() const = 0;

		// exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class FormSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, AForm const &form);