/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:22:41 by erian             #+#    #+#             */
/*   Updated: 2025/02/23 13:59:00 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << BLUE << "brain on\n" << NC;
}

Brain::Brain(const Brain& original) {
	std::cout << BLUE << "brain on\n" << NC;
	for (size_t i = 0; i < 100; i++)
		_ideas[i] = original._ideas[i];

}

Brain& Brain::operator=(const Brain& original) {
	for (size_t i = 0; i < 100; i++)
		_ideas[i] = original._ideas[i];
	return *this;
}

std::string *Brain::getIdeas() {
	return _ideas;
}

Brain::~Brain() {
	std::cout << BLUE << "brain off\n" << NC;
}