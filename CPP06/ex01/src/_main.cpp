/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:24:03 by erian             #+#    #+#             */
/*   Updated: 2025/03/19 18:59:16 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	Data myData = {42, "Hello World"};

	uintptr_t raw = Serializer::serialize(&myData);

	Data* deserializedPtr = Serializer::deserialize(raw);

	std::cout << "Original Address: " << &myData << std::endl;
	std::cout << "Serialized Value: " << raw << std::endl;
	std::cout << "Deserialized Address: " << deserializedPtr << std::endl;
	std::cout << "Deserialized Data: " << deserializedPtr->id << ", " << deserializedPtr->name << std::endl;

	return 0;
}