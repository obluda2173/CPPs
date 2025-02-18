/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:50:58 by erian             #+#    #+#             */
/*   Updated: 2025/02/18 13:56:32 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <Colors.hpp>

class Weapon {
	private:
		std::string	_type;

	public:
		Weapon( const std::string );

		const std::string getType();
		void setType( const std::string type );

		~Weapon();
};