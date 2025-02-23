/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:23:42 by erian             #+#    #+#             */
/*   Updated: 2025/02/22 16:47:19 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <unistd.h>

#include "_Colors.hpp"

#define SIZE 11

class AAnimal {
	protected:
		std::string _type;

	public:
		AAnimal();
		AAnimal(const AAnimal &original);
		virtual ~AAnimal();

		// operators
		AAnimal &operator=(const AAnimal &original);

		// methods
		virtual void makeSound() const = 0;

		// getters and setters
		std::string getType() const;
		void setType(std::string type);
};