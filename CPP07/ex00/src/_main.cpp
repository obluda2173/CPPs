/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:24:03 by erian             #+#    #+#             */
/*   Updated: 2025/03/21 12:14:07 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << RED << "a = " << a << NC << ", " << BLUE << "b = " << b << "\n" << NC;
	std::cout << "min( " << RED << "a" << NC << ", " << BLUE << "b" << NC << " ) = " << ::min( a, b ) << "\n";
	std::cout << "max( " << RED << "a" << NC << ", " << BLUE << "b" << NC << " ) = " << ::max( a, b ) << "\n";
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << RED << "c = " << c << NC << ", " << BLUE << "d = " << d << "\n" << NC;
	std::cout << "min( " << RED << "c" << NC << ", " << BLUE << "d" << NC << " ) = " << ::min( c, d ) << "\n";
	std::cout << "max( " << RED << "c" << NC << ", " << BLUE << "d" << NC << " ) = " << ::max( c, d ) << "\n";
	return 0;
}