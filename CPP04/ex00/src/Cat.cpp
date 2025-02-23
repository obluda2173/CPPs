/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:22:41 by erian             #+#    #+#             */
/*   Updated: 2025/02/22 14:20:04 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << DARK_GREEN << "cat created\n" << NC;
	_type = "cat";
}

Cat::Cat(const Cat &original) : Animal() {
	std::cout << DARK_GREEN << "cat created\n" << NC;
	_type = original.getType();
}

Cat::~Cat() {
	std::cout << RED << "cat was eaten by random asian\n" << NC;
}

Cat &Cat::operator=(const Cat &original) {
	_type = original.getType();
	return *this;
}

void Cat::makeSound() const {
	std::cout << DARK_BLUE << "*cat sound*\n" << NC;
}