/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:23:42 by erian             #+#    #+#             */
/*   Updated: 2025/02/23 10:27:06 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "_Colors.hpp"

class WrongAnimal {
	protected:
		std::string _type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &original);
		virtual ~WrongAnimal();

		// operators
		WrongAnimal &operator=(const WrongAnimal &original);

		// methods
		void makeSound() const;

		// getters and setters
		std::string getType() const;
		void setType(std::string type);
};