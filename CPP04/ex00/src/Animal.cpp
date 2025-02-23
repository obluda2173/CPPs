/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:22:41 by erian             #+#    #+#             */
/*   Updated: 2025/02/22 14:19:51 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("animal") {
	std::cout << DARK_GREEN << "random animal created\n" << NC;
}

Animal::Animal(const Animal &original) {
	std::cout << DARK_GREEN << "random animal created\n" << NC;
	_type = original.getType();
}

Animal::~Animal() {
	std::cout << RED << "random animal was eaten by random asian\n" << NC;
}

Animal& Animal::operator=(const Animal &original) {
	_type = original.getType();
	return *this;
}

void Animal::makeSound() const {
	std::cout << DARK_BLUE << "*random animal sound*\n" << NC;
}

std::string Animal::getType() const { 
	return _type;
}

void Animal::setType(std::string type) { 
	_type = type;
}