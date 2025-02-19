/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:05:15 by erian             #+#    #+#             */
/*   Updated: 2025/02/19 12:36:52 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << DARK_BLUE << "Default constructor called\n" << NC;
}

Fixed::Fixed( const int num ) {
	std::cout << BLUE << "Int constructor called\n" << NC;
	_value = num << _fractional_bits;
}

Fixed::Fixed( const float num ) {
	std::cout << DARK_GREEN << "Float constructor called\n" << NC;
	_value = roundf(num * (1 << _fractional_bits));
}

Fixed::Fixed( const Fixed &original ) {
	std::cout << DARK_MAGENTA << "Copy constructor called\n" << NC;
	_value = original._value;
}

Fixed::~Fixed() {
	std::cout << DARK_RED << "Destructor called\n" << NC;
}

Fixed &Fixed::operator=( const Fixed &original ) {
	std::cout << DARK_INDIGO << "Copy assignment operator called\n" << NC;
	if (this != &original) {
		_value = original._value;
	}
	return *this;
}

float Fixed::toFloat() const {
	return static_cast<float>(_value) / (1 << _fractional_bits);
}

int Fixed::toInt() const {
	return _value >> _fractional_bits;
}

int Fixed::getRawBits() const {
	return _value;
}

void Fixed::setRawBits( int const raw ) {
	_value = raw;
}

std::ostream &operator<<( std::ostream &out, const Fixed &fixed ) {
	out << fixed.toFloat();
	return out;
}