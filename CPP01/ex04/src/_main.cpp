/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:37:11 by erian             #+#    #+#             */
/*   Updated: 2025/02/18 15:02:14 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << ERROR << "Error: wrong number of arguments" << NC << std::endl;
		return 1;
	} else {
		std::string to_replace = av[2];
		if (to_replace.empty()) {
			std::cerr << ERROR << "Error: cannot replace an empty string" << NC << std::endl;
			return 1;
		}
		Sed sed;
		sed.replace(av[1], to_replace, av[3]);
	}

	return 0;
}