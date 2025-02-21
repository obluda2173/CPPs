/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:02:43 by erian             #+#    #+#             */
/*   Updated: 2025/02/21 12:31:16 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Colors.hpp"
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap(const std::string &_name);
		~FragTrap();

		void highFivesGuys();
};