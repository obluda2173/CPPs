/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:25:00 by erian             #+#    #+#             */
/*   Updated: 2025/03/18 13:39:32 by erian            ###   ########.fr       */
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
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);