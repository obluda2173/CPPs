/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:24:03 by erian             #+#    #+#             */
/*   Updated: 2025/03/25 11:17:03 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}

	try {
		int result = evaluate(av[1]);
		std::cout << BLUE << result << NC << std::endl;
	} catch (const std::exception &e) {
		std::cerr << ERROR << e.what() << NC << std::endl;
		return 1;
	}

	return 0;
}