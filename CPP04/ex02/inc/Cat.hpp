/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:23:42 by erian             #+#    #+#             */
/*   Updated: 2025/02/22 16:29:58 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
	private:
		Brain *_brain;

	public:
		Cat();
		Cat(const Cat &original);
		~Cat();

		// operators
		Cat &operator=(const Cat &original);

		// methods
		void makeSound() const;

		// getters and setters
		Brain *getBrain() const;
		void setBrain(const Brain &brain);
};