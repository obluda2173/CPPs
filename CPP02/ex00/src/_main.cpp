/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:05:13 by erian             #+#    #+#             */
/*   Updated: 2025/02/04 17:54:11 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

using std::cout;
using std::endl;

int main() {
	
	Fixed a;
	Fixed b(a);
	Fixed c;
	
	c = b;

	cout << a.getRawBits() << endl;
	cout << b.getRawBits() << endl;
	cout << c.getRawBits() << endl;

	return 0;

}