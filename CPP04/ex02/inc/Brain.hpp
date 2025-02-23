/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:23:42 by erian             #+#    #+#             */
/*   Updated: 2025/02/22 15:08:44 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "_Colors.hpp"

class Brain {
	private:
	  std::string _ideas[100];

  	public:
		Brain();
		Brain(const Brain& original);
		~Brain();

		// operators
		Brain &operator=(const Brain &original);

		// getters and setters
		std::string* getIdeas();
};