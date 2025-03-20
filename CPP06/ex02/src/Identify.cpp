/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:39:17 by erian             #+#    #+#             */
/*   Updated: 2025/03/20 11:49:46 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

Base* generate() {
	srand(time(NULL));
	int r = rand() % 3;

	if (r == 0)
		return new A();
	else if (r == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {
    try {
        if (dynamic_cast<A*>(&p)) {
            std::cout << "A" << std::endl;
            return;
        }
        if (dynamic_cast<B*>(&p)) {
            std::cout << "B" << std::endl;
            return;
        }
        if (dynamic_cast<C*>(&p)) {
            std::cout << "C" << std::endl;
            return;
        }
    } catch (...) {}

    std::cout << "Unknown type" << std::endl;
}