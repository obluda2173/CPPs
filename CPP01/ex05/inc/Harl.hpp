/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:54:50 by erian             #+#    #+#             */
/*   Updated: 2025/02/18 16:20:17 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ctime>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <iostream>

#include "Colors.hpp"

enum Level { DEBUG, INFO, WARNING, ERROR, UNKNOWN };

class Harl {
	private:
		std::string _texts[4][3];
		
		void debug();
		void info();
		void warning();
		void error();

	public:
		Harl();

		void complain( std::string level );

		~Harl();
};

Level get_level(const std::string& level_str);