/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:22:41 by erian             #+#    #+#             */
/*   Updated: 2025/02/22 14:27:55 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << DARK_GREEN << "wrong cat created\n" << NC;
	_type = "wrong cat";
}

WrongCat::WrongCat(const WrongCat &original) : WrongAnimal() {
	std::cout << DARK_GREEN << "wrong cat created\n" << NC;
	_type = original.getType();
}

WrongCat::~WrongCat() {
	std::cout << RED << "wrong cat was eaten by wrong asian\n" << NC;
}

WrongCat &WrongCat::operator=(const WrongCat &original) {
	_type = original.getType();
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << DARK_BLUE << "*wrong cat sound*\n" << NC;
}