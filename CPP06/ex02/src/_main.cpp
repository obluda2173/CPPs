/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:24:03 by erian             #+#    #+#             */
/*   Updated: 2025/03/20 11:57:57 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

int main() {
	Base* obj = generate();

	std::cout << "Identifying by pointer: ";
	identify(obj);

	std::cout << "Identifying by reference: ";
	identify(*obj);

	// std::cout << "Identifying NULL: ";
	// identify(NULL);

	delete obj;
	return 0;
}