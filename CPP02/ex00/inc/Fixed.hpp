/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:05:11 by erian             #+#    #+#             */
/*   Updated: 2025/02/02 20:34:06 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Colors.hpp"

class Fixed {

	private:
		int _value;
		static const int _fractional_bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &original);
		~Fixed();

		Fixed &operator=(const Fixed &original);

		int getRawBits() const;
		void setRawBits(const int raw);

};