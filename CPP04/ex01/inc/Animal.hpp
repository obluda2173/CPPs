/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:23:42 by erian             #+#    #+#             */
/*   Updated: 2025/02/23 10:44:50 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <unistd.h>

#include "_Colors.hpp"

#define SIZE 11

class Animal {
	protected:
		std::string _type;

	public:
		Animal();
		Animal(const Animal &original);
		virtual ~Animal();

		// operators
		Animal &operator=(const Animal &original);

		// methods
		virtual void makeSound() const;

		// getters and setters
		std::string getType() const;
		void setType(std::string type);
};