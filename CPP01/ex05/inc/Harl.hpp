/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:54:50 by erian             #+#    #+#             */
/*   Updated: 2025/02/02 19:37:25 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ctime>
#include <string>
#include <unistd.h>
#include <iostream>
#include "Colors.hpp"

class Harl {

	private:
		std::string _debug_texts[3];
		std::string _info_texts[3];
		std::string _warning_texts[3];
		std::string _error_texts[3];
		
		void debug();
		void info();
		void warning();
		void error();

	public:
		Harl();
		~Harl();

		void complain(std::string level);
};