/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:05:15 by erian             #+#    #+#             */
/*   Updated: 2025/02/02 20:33:15 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

using std::cout;
using std::endl;

Fixed::Fixed() : _value(0) {
	cout << ORANGE << "default constructor called\n" << NC;
}

Fixed::Fixed(const Fixed &original) {
	cout << YELLOW << "copy constructor called\n" << NC;
	_value = original.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &original) {
	cout << GREEN << "copy assignment operator called\n" << NC;
	if (this != &original)
		setRawBits(original.getRawBits());
	return (*this);
}

int Fixed::getRawBits() const {
	cout << BLUE << "getRawBits function called\n" << NC;
	return _value;
}

void Fixed::setRawBits(const int raw) {_value = raw;}

Fixed::~Fixed() {
	cout << INDIGO << "destructor called\n" << NC;
}