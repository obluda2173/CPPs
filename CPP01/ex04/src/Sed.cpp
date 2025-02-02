/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:37:15 by erian             #+#    #+#             */
/*   Updated: 2025/02/02 18:40:23 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

using std::cerr;
using std::endl;

Sed::Sed() {}

void Sed::replace(std::string file, std::string to_replace, std::string replace) {

	std::ifstream input(file.c_str());
	std::string buffer;
	size_t pos;

	if (!input.is_open()) {
		cerr << ERROR << " could not open a file :( " << NC << endl;
		input.close();
		return;
	}

	getline(input, buffer, '\0');

	if (buffer.empty()) {
		cerr << ERROR << " file is empty :( " << NC << endl;
		input.close();
		return;
	}

	pos = buffer.find(to_replace);

	while (pos != std::string::npos) {
		buffer.erase(pos, to_replace.length());
		buffer.insert(pos, replace);
		pos = buffer.find(to_replace, pos + replace.length());
	}

	std::ofstream output((file + ".replace").c_str());
	output << buffer;

	output.close();
	input.close();
}

Sed::~Sed() {}
