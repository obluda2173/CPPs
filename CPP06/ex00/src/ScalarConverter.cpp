/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:26:28 by erian             #+#    #+#             */
/*   Updated: 2025/03/20 09:40:51 by erian            ###   ########.fr       */
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

	if (isPseudoLiteral(input)) {
		std::cout << ERROR << "char: impossible\n" << NC;
		std::cout << ERROR << "int: impossible\n" << NC;
		std::cout << YELLOW << "float: " << input << (input[input.length() - 1] == 'f' ? "" : "f") << "\n" << NC;
		std::cout << GREEN << "double: " << input.substr(0, input.length() - (input[input.length() - 1] == 'f' ? 1 : 0)) << "\n" << NC;
		return;
	}

	try {
		if (isInt(input)) {
			i = std::strtol(input.c_str(), NULL, 10);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			c = static_cast<char>(i);
		}
		else if (isFLoat(input)) {
			f = static_cast<float>(std::atof(input.c_str()));
			i = static_cast<int>(f);
			d = static_cast<double>(f);
			c = static_cast<char>(i);
		}
		else if (isDouble(input)) {
			d = std::strtod(input.c_str(), NULL);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
			c = static_cast<char>(i);
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

		if (std::isprint(c)) 
			std::cout << RED << "char: '" << c << "'\n" << NC;
		else 
			std::cout << RED << "char: Non displayable\n" << NC;
		
		std::cout << ORANGE << "int: " << i << "\n" << NC;
		if (f - (float)i == 0) {
			std::cout << YELLOW << "float: " << f << ".0f\n" << NC;
			std::cout << GREEN << "double: " << d << ".0\n" << NC;
		} 
		else {
			std::cout << YELLOW << "float: " << f << "f\n" << NC;
			std::cout << GREEN << "double: " << d << "\n" << NC;
		}
	} catch(const std::exception& e) {
		std::cout << ERROR << "char: impossible\n" << NC;
		std::cout << ERROR << "int: impossible\n" << NC;
		std::cout << ERROR << "float: impossible\n" << NC;
		std::cout << ERROR << "double: impossible\n" << NC;
	}
}