/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:22:41 by erian             #+#    #+#             */
/*   Updated: 2025/02/22 14:20:32 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("animal") {
	std::cout << DARK_GREEN << "wrong animal created\n" << NC;
}

WrongAnimal::WrongAnimal(const WrongAnimal &original) {
	std::cout << DARK_GREEN << "wrong animal created\n" << NC;
	_type = original.getType();
}

WrongAnimal::~WrongAnimal() {
	std::cout << RED << "wrong animal was eaten by wrong asian\n" << NC;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &original) {
	_type = original.getType();
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << DARK_BLUE << "*wrong animal sound*\n" << NC;
}

std::string WrongAnimal::getType() const { 
	return _type;
}

void WrongAnimal::setType(std::string type) { 
	_type = type;
}