/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:24:44 by erian             #+#    #+#             */
/*   Updated: 2025/02/18 11:49:38 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <unistd.h>

#include "Colors.hpp"

class Zombie {
	private:
		std::string _name;

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void Announce();
};

Zombie* zombieHorde(int N, std::string name);