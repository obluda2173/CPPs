/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:25:00 by erian             #+#    #+#             */
/*   Updated: 2025/03/17 16:02:05 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include <exception>

#include "_Colors.hpp"
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		// attributes
		std::string const _name;
		unsigned int _grade;

	public:
		// OCN
		Bureaucrat();
		Bureaucrat(std::string const &name, unsigned int grade);
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat &operator=(Bureaucrat const &other);
		~Bureaucrat();

		// getters n setters
		std::string const &getName() const;
		unsigned int getGrade() const;

		// methods
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form);
		void executeForm(AForm const &form);

		// exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "bureaucrat grade is too high";
				};
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "bureaucrat grade is too low";
				};
		};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);