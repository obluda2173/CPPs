/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:25:29 by erian             #+#    #+#             */
/*   Updated: 2025/02/18 14:27:14 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <fstream>
#include <iostream>

#include "Colors.hpp"

class Sed {
	public:
		Sed();
		~Sed();

		void replace( std::string file, std::string to_replace, std::string replace );
};