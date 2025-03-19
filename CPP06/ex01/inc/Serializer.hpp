/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:21:42 by erian             #+#    #+#             */
/*   Updated: 2025/03/19 19:06:13 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>

#include "_Colors.hpp"

struct Data {
	int id;
	std::string name;
};

class Serializer {
	private:
		// OCF
		Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer&);
		~Serializer();

	public:
		// methods
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);		   
};