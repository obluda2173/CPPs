/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:22:41 by erian             #+#    #+#             */
/*   Updated: 2025/02/22 14:20:17 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << DARK_GREEN << "dog created\n" << NC;
	_type = "dog";
}

Dog::Dog(const Dog &original) : Animal() {
	std::cout << DARK_GREEN << "dog created\n" << NC;
	_type = original.getType();
}

Dog::~Dog() {
	std::cout << RED << "dog was eaten by random asian\n" << NC;
}

Dog &Dog::operator=(const Dog &original) {
	_type = original.getType();
	return *this;
}

void Dog::makeSound() const {
	std::cout << DARK_BLUE << "*dog sound*\n" << NC;
}