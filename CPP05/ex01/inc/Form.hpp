/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
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

class Form {
	private:
		// attriburtes
		std::string const _name;
		bool _signed;
		unsigned int const _signGrade;
		unsigned int const _execGrade;

	public:
		// OCN
		Form();
		Form(std::string const &name, unsigned int signGrade, unsigned int execGrade);
		Form(Form const &other);
		Form &operator=(Form const &other);
		~Form();

		// getters n setters
		std::string const &getName() const;
		bool isSigned() const;
		unsigned int getSignGrade() const;
		unsigned int getExecGrade() const;

		// methods
		void beSigned(Bureaucrat const &bureaucrat);
		
		// exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Form const &form);