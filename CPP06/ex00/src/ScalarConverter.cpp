/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:26:28 by erian             #+#    #+#             */
/*   Updated: 2025/03/20 11:16:02 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ScalarConverter.hpp>

bool isInt(const std::string& str) {
	for (int i = (str[0] == '-' ? 1 : 0); i < (int)str.size(); i++)
		if (!isdigit(str[i]))
			return false;
	return true;
}

bool isFLoat(const std::string& str) {
	return str.find('.') != std::string::npos && str[str.length() - 1] == 'f';
}

bool isDouble(const std::string& str) {
	return str.find('.') != std::string::npos && str[str.length() - 1] != 'f';
}

bool isPseudoLiteral(const std::string& str) {
	return (str == "nan" || str == "+inf" || str == "-inf" || str == "nanf" || str == "+inff" || str == "-inff");
}

void ScalarConverter::convert(const std::string& input) {
	char c = 0;
	int i = 0;
	float f = 0.0f;
	double d = 0.0;

	bool charValid = true, intValid = true, floatValid = true, doubleValid = true;

	if (isPseudoLiteral(input)) {
		std::cout << ERROR << "char: impossible\n" << NC;
		std::cout << ERROR << "int: impossible\n" << NC;
		std::cout << YELLOW << "float: " << input << (input[input.length() - 1] == 'f' ? "" : "f") << "\n" << NC;
		std::cout << GREEN << "double: " << input.substr(0, input.length() - (input[input.length() - 1] == 'f' ? 1 : 0)) << "\n" << NC;
		return;
	}

	try {
		if (isInt(input)) {
			long temp = std::strtol(input.c_str(), NULL, 10);
			if (temp < std::numeric_limits<int>::min() || temp > std::numeric_limits<int>::max()) 
				throw std::out_of_range("Integer overflow");
			i = static_cast<int>(temp);
			d = static_cast<double>(i);
			f = static_cast<float>(i);
		}
		else if (isFLoat(input)) {
			double temp = std::atof(input.c_str());
			if (temp < std::numeric_limits<float>::min() || temp > std::numeric_limits<float>::max()) 
				throw std::out_of_range("Float overflow");
			f = static_cast<float>(temp);
			d = static_cast<double>(f);
			if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
				i = static_cast<int>(f);
			else
				intValid = false;
		}
		else if (isDouble(input)) {
			d = std::strtod(input.c_str(), NULL);
			if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
				i = static_cast<int>(d);
			else
				intValid = false;
			if (d >= std::numeric_limits<float>::min() && d <= std::numeric_limits<float>::max())
				f = static_cast<float>(d);
			else
				floatValid = false;
		}
		else if (input.length() == 3 && input[0] == '\'' && input[2] == '\'') {
			c = input[1];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
		}
		else {
			throw std::invalid_argument("Invalid input");
		}
	}
	catch (...) {
		intValid = false;
		floatValid = false;
		doubleValid = false;
	}

	if (i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max())
			c = static_cast<char>(i);
		else
			charValid = false;

	if (charValid && std::isprint(c))
		std::cout << RED << "char: '" << c << "'\n" << NC;
	else if (charValid)
		std::cout << RED << "char: Non displayable\n" << NC;
	else
		std::cout << ERROR << "char: impossible\n" << NC;

	if (intValid)
		std::cout << ORANGE << "int: " << i << "\n" << NC;
	else
		std::cout << ERROR << "int: impossible\n" << NC;

	if (floatValid)
		std::cout << YELLOW << "float: " << f << "f\n" << NC;
	else
		std::cout << ERROR << "float: impossible\n" << NC;

	if (doubleValid) 
		std::cout << GREEN << "double: " << d << "\n" << NC;
	else
		std::cout << ERROR << "double: impossible\n" << NC;
}