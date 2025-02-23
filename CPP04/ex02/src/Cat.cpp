/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:22:41 by erian             #+#    #+#             */
/*   Updated: 2025/02/22 17:44:59 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal() {
	std::cout << DARK_GREEN << "cat created\n" << NC;
	_type = "cat";
	_brain = new Brain();
}

Cat::Cat(const Cat &original) : AAnimal() {
	std::cout << DARK_GREEN << "cat created\n" << NC;
	_type = original.getType();
	_brain = new Brain(*original._brain);
}

Cat::~Cat() {
	std::cout << RED << "cat was eaten by random asian\n" << NC;
	delete _brain;
}

Cat &Cat::operator=(const Cat &original) {
	if (this != &original) {
		_type = original.getType();
		delete _brain;
		_brain = new Brain(*original._brain);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << DARK_BLUE << "*cat sound*\n" << NC;
}

Brain *Cat::getBrain() const {
	return _brain;
}

void Cat::setBrain(const Brain &brain) {
	*_brain = brain;
}