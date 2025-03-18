/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:21:21 by erian             #+#    #+#             */
/*   Updated: 2025/03/17 12:53:43 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "_Colors.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		// attributes
		std::string _target;

	public:
		// OCN
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm();

		// geters n setters
		std::string getTarget() const;

		// methods
		void action() const;
};