/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:50:59 by erian             #+#    #+#             */
/*   Updated: 2025/01/19 19:53:46 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av) {
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int i = 1; i < ac; i++) {
			const char *str = av[i];
			while (*str) {
				std::cout << static_cast<char>(std::toupper(*str));
				++str;
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
