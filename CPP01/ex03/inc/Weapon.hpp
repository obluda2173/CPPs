/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:50:58 by erian             #+#    #+#             */
/*   Updated: 2025/01/28 20:01:37 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Weapon {
	private:
		std::string	_type;
	public:
		Weapon(const std::string);
		~Weapon();
		
		const	std::string getType();
		void	setType(const std::string type);
};
