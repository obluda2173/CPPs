/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:22:41 by erian             #+#    #+#             */
/*   Updated: 2025/02/22 17:44:57 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal() {
	std::cout << DARK_GREEN << "dog created\n" << NC;
	_type = "dog";
	_brain = new Brain();
}

Dog::Dog(const Dog &original) : AAnimal() {
	std::cout << DARK_GREEN << "dog created\n" << NC;
	_type = original.getType();
	_brain = new Brain(*original._brain);
}

Dog::~Dog() {
	std::cout << RED << "dog was eaten by random asian\n" << NC;
	delete _brain;
}

Dog &Dog::operator=(const Dog &original) {
	if (this != &original) {
		_type = original.getType();
		delete _brain;
		_brain = new Brain(*original._brain);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << DARK_BLUE << "*dog sound*\n" << NC;
}

Brain* Dog::getBrain() const {
	return _brain;
}

void Dog::setBrain(const Brain &brain) {
	*_brain = brain;
}