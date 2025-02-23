/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:22:41 by erian             #+#    #+#             */
/*   Updated: 2025/02/22 16:47:31 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("animal") {
	std::cout << DARK_GREEN << "random animal created\n" << NC;
}

AAnimal::AAnimal(const AAnimal &original) {
	std::cout << DARK_GREEN << "random animal created\n" << NC;
	_type = original.getType();
}

AAnimal::~AAnimal() {
	std::cout << RED << "random animal was eaten by random asian\n" << NC;
}

AAnimal &AAnimal::operator=(const AAnimal &original) {
	_type = original.getType();
	return *this;
}

std::string AAnimal::getType() const { 
	return _type;
}

void AAnimal::setType(std::string type) { 
	_type = type;
}