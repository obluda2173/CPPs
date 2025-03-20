/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:21:42 by erian             #+#    #+#             */
/*   Updated: 2025/03/20 09:22:22 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include <limits>
#include <string>
#include <cstdlib>
#include <iostream>

#include "_Colors.hpp"

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter &operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:
		static void convert(const std::string& input);
};