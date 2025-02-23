/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:23:42 by erian             #+#    #+#             */
/*   Updated: 2025/02/22 16:30:02 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
	private:
		Brain *_brain;

	public:
		Dog();
		Dog(const Dog &original);
		~Dog();

		// operators
		Dog &operator=(const Dog &original);

		// methods
		void makeSound() const;

		// getters and setters
		Brain *getBrain() const;
		void setBrain(const Brain &brain);
};