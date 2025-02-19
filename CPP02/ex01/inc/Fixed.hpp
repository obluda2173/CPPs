/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:05:11 by erian             #+#    #+#             */
/*   Updated: 2025/02/19 12:38:34 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include <iostream>

#include "Colors.hpp"

class Fixed {
	private:
		int _value;
		static const int _fractional_bits = 8;

	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &original);
		~Fixed();

		Fixed &operator=(const Fixed &original);

		int toInt() const;
		float toFloat() const;

		int getRawBits() const;
		void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);