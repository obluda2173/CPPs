/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:02:32 by erian             #+#    #+#             */
/*   Updated: 2025/03/18 12:52:02 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& original) { 
    (void)original; 
}

Intern &Intern::operator=(const Intern& original) {
    (void)original;
    return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string formName, std::string formTarget) {
    AForm *revolverDrum[] = {new PresidentialPardonForm(formTarget), new RobotomyRequestForm(formTarget), new ShrubberyCreationForm(formTarget)};
    std::string names[3] = {"PresidentialPardon", "RobotomyRequest", "ShrubberyCreation"};

    for (int i = 0; i < 3; i++) {
        if (formName == names[i]) {
            for (int j = 0; j < 3; j++) {
                if (j != i)
                    delete revolverDrum[j];
            }
            std::cout << INDIGO << "Intern creates " << revolverDrum[i]->getName() << "\n" <<NC;
            return revolverDrum[i];
        }
    }
    for (int k = 0; k < 3; k++)
        delete revolverDrum[k];
    std::cerr << ERROR << "Intern forgot to create a given form\n" << NC;
    return NULL;
}